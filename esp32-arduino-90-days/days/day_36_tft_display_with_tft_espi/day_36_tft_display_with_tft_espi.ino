// Day 36: TFT graphics using TFT_eSPI.
// Configure TFT_eSPI User_Setup.h for your exact display before compiling.
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();
void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("ESP32 TFT", 10, 10);
  tft.drawRect(10, 50, 120, 60, TFT_GREEN);
  tft.fillCircle(200, 80, 25, TFT_BLUE);
  tft.drawLine(10, 130, 300, 130, TFT_RED);
}
void loop() {}