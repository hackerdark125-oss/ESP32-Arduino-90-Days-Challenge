// Day 30: 16x2 character LCD with I2C backpack.
// SDA -> GPIO 21, SCL -> GPIO 22. Common addresses: 0x27 or 0x3F.
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ESP32 + I2C LCD");
  lcd.setCursor(0, 1);
  lcd.print("Day 30 ready");
}
void loop() {
  static unsigned long lastUpdate = 0;
  static unsigned long seconds = 0;
  if (millis() - lastUpdate >= 1000) {
    lastUpdate = millis();
    seconds++;
    lcd.setCursor(0, 1);
    lcd.print("Uptime: ");
    lcd.print(seconds);
    lcd.print("s     ");
  }
}