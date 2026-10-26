
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <DHT.h>

#define DHT_PIN 15
#define DHT_TYPE DHT22

// Wokwi WiFi settings
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Replace with your ThingSpeak Write API Key before running
const char* apiKey = "YOUR_WRITE_API_KEY";

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("ESP32 Temperature and Humidity Monitor");
  Serial.println("Student ID: 12220986");

  // Connect ESP32 to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if sensor readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error: DHT22 reading failed!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity, 1);
    Serial.println(" %");

    // Send readings to ThingSpeak
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      WiFiClientSecure client;

      // For Wokwi simulation only
      client.setInsecure();

      String url = "https://api.thingspeak.com/update?api_key=";
      url += String(apiKey);
      url += "&field1=" + String(temperature, 1);
      url += "&field2=" + String(humidity, 1);

      http.begin(client, url);
      int response = http.GET();

      if (response == 200) {
        String entryID = http.getString();
        entryID.trim();

        if (entryID != "0" && entryID.length() > 0) {
          Serial.print("Data sent successfully! Entry ID: ");
          Serial.println(entryID);
        } else {
          Serial.println("ThingSpeak did not accept the data.");
        }
      } else {
        Serial.print("Sending failed. HTTP code: ");
        Serial.println(response);
      }

      http.end();
    } else {
      Serial.println("WiFi disconnected!");
    }
  }

  // Send readings every 20 seconds
  delay(20000);
}
