// Day 37: ESP32 UART2 loopback test.
// Jumper GPIO 17 (TX2) to GPIO 16 (RX2). Do not connect two outputs together.
const int RX2_PIN = 16;
const int TX2_PIN = 17;
unsigned long lastSend = 0;
void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RX2_PIN, TX2_PIN);
  Serial.println("UART2 loopback: connect TX2 GPIO17 to RX2 GPIO16.");
}
void loop() {
  if (millis() - lastSend >= 1000) {
    lastSend = millis();
    Serial2.println("ESP32 UART2 test");
  }
  while (Serial2.available()) {
    String received = Serial2.readStringUntil('\n');
    Serial.print("UART2 received: ");
    Serial.println(received);
  }
}