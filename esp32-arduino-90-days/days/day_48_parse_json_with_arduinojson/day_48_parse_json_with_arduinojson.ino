// Day 48: Parse a JSON document with ArduinoJson.
#include <ArduinoJson.h>
const char jsonInput[] = R"json(
{
  "city": "Dehradun",
  "temperature_c": 27.5,
  "humidity_percent": 61,
  "condition": "Cloudy"
}
)json";
void setup() {
  Serial.begin(115200);
  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, jsonInput);
  if (error) {
    Serial.print("JSON parse failed: ");
    Serial.println(error.c_str());
    return;
  }
  const char *city = doc["city"] | "Unknown";
  float temperature = doc["temperature_c"] | 0.0;
  int humidity = doc["humidity_percent"] | 0;
  const char *condition = doc["condition"] | "Unknown";
  Serial.print("City: "); Serial.println(city);
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("%");
  Serial.print("Condition: "); Serial.println(condition);
}
void loop() {}