// Day 35: Simple sensor dashboard - potentiometer value on SSD1306 OLED.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
const int POT_PIN = 34;
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed.");
    while (true) delay(1000);
  }
}
void loop() {
  int raw = analogRead(POT_PIN);
  int percent = map(raw, 0, 4095, 0, 100);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0); display.println("ESP32 SENSOR PANEL");
  display.drawLine(0, 12, 127, 12, SSD1306_WHITE);
  display.setCursor(0, 22); display.print("ADC: "); display.println(raw);
  display.setCursor(0, 36); display.print("Position: "); display.print(percent); display.println("%");
  display.drawRect(0, 52, 128, 10, SSD1306_WHITE);
  display.fillRect(1, 53, map(percent, 0, 100, 0, 126), 8, SSD1306_WHITE);
  display.display();
  delay(150);
}