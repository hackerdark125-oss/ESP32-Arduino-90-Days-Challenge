// Day 42: OLED menu controlled by rotary encoder.
// OLED I2C: SDA 21, SCL 22. Encoder A 32, B 33, switch 25.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
const int ENC_A = 32, ENC_B = 33, ENC_SW = 25;
const char *items[] = {"Status", "Settings", "Sensors", "About"};
const int ITEM_COUNT = sizeof(items) / sizeof(items[0]);
int selected = 0, lastA, lastButton = HIGH;
unsigned long lastButtonAt = 0;
bool showDetails = false;
void drawMenu() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0); display.println("ESP32 MENU");
  for (int i = 0; i < ITEM_COUNT; i++) {
    display.setCursor(0, 16 + i * 11);
    display.print(i == selected ? "> " : "  ");
    display.println(items[i]);
  }
  if (showDetails) {
    display.fillRect(65, 48, 63, 16, SSD1306_BLACK);
    display.drawRect(65, 48, 63, 16, SSD1306_WHITE);
    display.setCursor(69, 53); display.print("Selected");
  }
  display.display();
}
void setup() {
  pinMode(ENC_A, INPUT_PULLUP); pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_SW, INPUT_PULLUP);
  lastA = digitalRead(ENC_A);
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) while (true) delay(1000);
  drawMenu();
}
void loop() {
  int a = digitalRead(ENC_A);
  if (a != lastA && a == LOW) {
    selected += (digitalRead(ENC_B) == HIGH) ? 1 : -1;
    if (selected < 0) selected = ITEM_COUNT - 1;
    if (selected >= ITEM_COUNT) selected = 0;
    showDetails = false;
    drawMenu();
  }
  lastA = a;
  int button = digitalRead(ENC_SW);
  if (button == LOW && lastButton == HIGH && millis() - lastButtonAt > 200) {
    lastButtonAt = millis();
    showDetails = !showDetails;
    drawMenu();
  }
  lastButton = button;
}