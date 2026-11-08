// Day 13: ESP32-WROOM-32 pinout and safe GPIO reference.
// This lesson prints a reference to Serial Monitor; it does not drive pins.
void setup() {
  Serial.begin(115200);
  delay(300);
  Serial.println();
  Serial.println("Day 13 - ESP32-WROOM-32 GPIO guide");
  Serial.println("Common output-capable GPIOs: 16,17,18,19,21,22,23,25,26,27,32,33.");
  Serial.println("Input-only: GPIO 34,35,36,39 (no internal pull-up/down).");
  Serial.println("Boot strapping pins: GPIO 0,2,5,12,15; use with care.");
  Serial.println("Flash-connected pins: GPIO 6-11; do not use for normal I/O.");
  Serial.println("UART0: GPIO 1 TX and GPIO 3 RX are used for USB serial.");
  Serial.println("Prefer ADC1 pins for analog input while Wi-Fi is active.");
  Serial.println("Never apply 5V to an ESP32 GPIO. GPIO logic is 3.3V.");
}
void loop() {
  // Check the pinout for your exact ESP32 development board.
}