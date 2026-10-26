# ESP32-Based Temperature and Humidity Monitoring Using ThingSpeak

**Internet of Things (IoT) | ESP32 + DHT22 + Wokwi + ThingSpeak**

An IoT monitoring system that measures temperature and humidity using a simulated ESP32 and DHT22 sensor, transmits readings to ThingSpeak, and visualizes the data through publicly accessible cloud charts.

## 1. Student Information

| Information | Details |
|---|---|
| Student Name | Nancy Khaled Aljabbarin |
| University ID | 12220986 |
| University | An-Najah National University |
| Course | Internet of Things (IoT) |
| Project | ESP32 → ThingSpeak |

## 2. Project Objective

The objective of this project is to implement and demonstrate a complete IoT data-monitoring workflow, from sensor measurement to cloud visualization.

The system is designed to:

- Read temperature and humidity values from a DHT22 sensor.
- Connect an ESP32 microcontroller to Wi-Fi.
- Transmit sensor readings to ThingSpeak every 20 seconds.
- Store temperature and humidity measurements in separate ThingSpeak fields.
- Display the collected data through publicly accessible, time-based charts.
- Demonstrate that changes in sensor values are reflected in the cloud.

The project uses Wokwi simulation instead of physical hardware.

## 3. System Architecture

The system follows a simple sensor-to-cloud architecture:

**DHT22 Sensor → ESP32 → Wi-Fi → ThingSpeak Cloud → Temperature and Humidity Charts**

The DHT22 measures environmental conditions, while the ESP32 processes the readings and sends them to ThingSpeak using HTTP GET requests over HTTPS.

ThingSpeak stores the received measurements and displays them as time-series data.

## 4. Hardware and Software Components

| Component | Purpose |
|---|---|
| ESP32 Dev Board | Reads sensor data and communicates with ThingSpeak |
| DHT22 Sensor | Measures temperature and relative humidity |
| Wokwi | Simulates the ESP32 circuit and sensor |
| ThingSpeak | Receives, stores, and visualizes sensor measurements |
| Arduino C++ | Implements the ESP32 monitoring program |
| DHT Library | Provides temperature and humidity sensor readings |
| WiFi Library | Establishes the ESP32 network connection |
| HTTPClient Library | Sends HTTP requests to ThingSpeak |
| WiFiClientSecure Library | Provides the HTTPS client connection |

## 5. Circuit Connections

The DHT22 sensor is connected to the ESP32 using the following wiring:

| DHT22 Pin | ESP32 Connection |
|---|---|
| VCC | 3V3 |
| GND | GND |
| DATA | GPIO 15 |

GPIO 15 is defined in the source code as the sensor's data pin.

The complete circuit can be viewed in the Wokwi simulation.

## 6. Project Links

### Wokwi Simulation

https://wokwi.com/projects/478957923300107265

### ThingSpeak Public Channel

https://thingspeak.mathworks.com/channels/3551666

### GitHub Repository

https://github.com/nancy-khaled-aljabbarin/ESP32-DHT22-ThingSpeak

The ThingSpeak channel is configured with:

- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)

The channel is publicly accessible so that the measurements and graphs can be reviewed without requiring access to the Write API Key.

## 7. Implementation and Data Flow

The ESP32 program performs the following operations:

1. Initializes serial communication and the DHT22 sensor.
2. Connects to the `Wokwi-GUEST` Wi-Fi network.
3. Reads temperature in degrees Celsius and humidity as a percentage.
4. Checks whether the sensor readings are valid.
5. Constructs a ThingSpeak update request containing both measurements.
6. Sends the request through an HTTPS connection.
7. Checks the server response and prints the returned entry ID when the upload succeeds.
8. Waits 20 seconds before repeating the monitoring process.

The University ID, **12220986**, is printed in the Serial Monitor during initialization.

The program also reports invalid sensor readings, Wi-Fi disconnections, and unsuccessful HTTP requests.

## 8. Running the Simulation

1. Open the Wokwi project using the simulation link above.
2. Create a ThingSpeak channel with two fields: Temperature and Humidity.
3. Obtain the Write API Key for that channel.
4. Replace `YOUR_WRITE_API_KEY` in the working copy of `sketch.ino` with the valid Write API Key.
5. Start the simulation in Wokwi.
6. Open the Serial Monitor to observe the readings and upload status.
7. Open the ThingSpeak channel to inspect the incoming measurements and charts.

**API Key Security:** The public GitHub source code contains a placeholder instead of a real Write API Key. A valid key is required to send data to a ThingSpeak channel. The key should not be committed to a public repository.

**Simulation Security Note:** The HTTPS client uses `setInsecure()` for this educational simulation, which disables TLS certificate verification. A production implementation should validate the server certificate.

## 9. Testing and Results

The system was tested using two different simulated DHT22 sensor settings.

| Test | Temperature | Humidity |
|---|---|---|
| Initial sensor values | 24.0°C | 40.0% |
| Updated sensor values | 30.0°C | 60.0% |

### Test 1 — Initial Data Transmission

The ESP32 successfully connected to Wi-Fi and transmitted the initial temperature and humidity readings to ThingSpeak.

The Serial Monitor displayed successful upload messages with entry IDs, and the ThingSpeak charts displayed the received measurements over time.

### Test 2 — Sensor Value Changes

The DHT22 simulation values were manually changed from 24°C to 30°C and from 40% to 60%.

The Serial Monitor confirmed the updated readings, and successful uploads were recorded with new ThingSpeak entry IDs.

After refreshing the ThingSpeak channel, both charts reflected the updated sensor values.

This verified that the system could transmit changing measurements rather than only displaying fixed values.

### Observed Results

- Successful ESP32 Wi-Fi connection.
- Valid DHT22 temperature and humidity readings.
- Successful transmission of sensor data to ThingSpeak.
- Repeated data uploads at approximately 20-second intervals.
- Temperature and humidity displayed in separate time-series charts.
- Updated sensor values reflected in the ThingSpeak visualizations.

## 10. Project Screenshots

The project documentation includes the following evidence:

- **Wokwi Circuit:** ESP32 and DHT22 wiring connections.
- **Serial Monitor:** Sensor readings, Wi-Fi connection, and successful ThingSpeak upload messages.
- **ThingSpeak Temperature Chart:** Temperature measurements and the change from 24°C to 30°C.
- **ThingSpeak Humidity Chart:** Humidity measurements and the change from 40% to 60%.

These screenshots document the simulation setup, data transmission, and cloud visualization results.

## 11. Conclusion

This project successfully demonstrates an end-to-end IoT monitoring workflow using a simulated ESP32 microcontroller, a DHT22 sensor, and the ThingSpeak cloud platform.

The ESP32 reads environmental measurements and sends them to ThingSpeak at regular intervals, where they are stored and visualized.

Testing with different simulated sensor values confirmed that the system responds to changes and updates the cloud charts accordingly.

The project demonstrates fundamental IoT concepts, including sensor integration, Wi-Fi communication, cloud data collection, and remote monitoring.
