// Day 23: DHT22 temperature and humidity sensor.
#include <DHT.h>
#define DHT_PIN 4
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);
void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT22 sensor starting...");
}
void loop() {
  delay(2000); // DHT22 should not be read more frequently than about every 2 seconds.
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("DHT22 read failed. Check wiring and library.");
    return;
  }
  Serial.print("Temperature: "); Serial.print(temperatureC, 1); Serial.println(" C");
  Serial.print("Humidity: "); Serial.print(humidity, 1); Serial.println(" %");
}