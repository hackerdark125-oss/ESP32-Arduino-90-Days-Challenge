// Day 32: Draw basic graphics on a 128x64 SSD1306 OLED.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup() {
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while (true) delay(1000);
}
void loop() {
  display.clearDisplay();
  display.drawLine(0, 0, 127, 63, SSD1306_WHITE);
  display.drawRect(4, 4, 40, 24, SSD1306_WHITE);
  display.fillCircle(82, 20, 12, SSD1306_WHITE);
  display.drawRoundRect(48, 38, 72, 22, 5, SSD1306_WHITE);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(7, 12);
  display.print("ESP32");
  display.display();
  delay(1500);
}