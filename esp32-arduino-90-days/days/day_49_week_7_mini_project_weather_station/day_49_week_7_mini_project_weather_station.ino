// Day 49: Open-Meteo weather data on an SSD1306 OLED.
// Configure Wi-Fi credentials. Demo uses setInsecure(); see README security note.
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
const char *SSID = "YOUR_WIFI_NAME";
const char *PASSWORD = "YOUR_WIFI_PASSWORD";
const char *URL = "https://api.open-meteo.com/v1/forecast?latitude=30.32&longitude=78.03&current=temperature_2m,relative_humidity_2m,weather_code";
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while (true) delay(1000);
  WiFi.begin(SSID, PASSWORD);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 20000) delay(300);
  display.clearDisplay(); display.setTextColor(SSD1306_WHITE); display.setCursor(0,0);
  if (WiFi.status() != WL_CONNECTED) { display.println("WiFi failed"); display.display(); return; }
  WiFiClientSecure client;
  client.setInsecure(); // Learning demo only: skips server certificate validation.
  HTTPClient http;
  if (!http.begin(client, URL)) return;
  int status = http.GET();
  if (status == HTTP_CODE_OK) {
    JsonDocument doc;
    DeserializationError err = deserializeJson(doc, http.getStream());
    if (!err) {
      float temp = doc["current"]["temperature_2m"] | NAN;
      int humidity = doc["current"]["relative_humidity_2m"] | -1;
      display.clearDisplay(); display.setCursor(0,0);
      display.println("Weather sample");
      display.print("Temp: "); display.print(temp); display.println(" C");
      display.print("Humidity: "); display.print(humidity); display.println("%");
      display.println("Open-Meteo");
      display.display();
    } else Serial.println(err.c_str());
  } else Serial.printf("HTTP error: %d\n", status);
  http.end();
}
void loop() {}