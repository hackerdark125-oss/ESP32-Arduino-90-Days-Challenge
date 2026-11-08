// Day 33: Bouncing ball OLED animation using millis() timing.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
int x = 12, y = 12, dx = 2, dy = 1;
const int RADIUS = 4;
const unsigned long FRAME_MS = 33;
unsigned long lastFrame = 0;
void setup() {
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while (true) delay(1000);
}
void loop() {
  unsigned long now = millis();
  if (now - lastFrame < FRAME_MS) return;
  lastFrame = now;
  x += dx; y += dy;
  if (x <= RADIUS || x >= 127 - RADIUS) dx = -dx;
  if (y <= RADIUS || y >= 63 - RADIUS) dy = -dy;
  display.clearDisplay();
  display.drawCircle(x, y, RADIUS, SSD1306_WHITE);
  display.display();
}