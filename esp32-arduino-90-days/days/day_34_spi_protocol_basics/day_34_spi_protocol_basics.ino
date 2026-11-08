// Day 34: SPI loopback demonstration.
// Wire MOSI GPIO 23 directly to MISO GPIO 19 for this test.
// Default classic ESP32 VSPI pins: SCK 18, MISO 19, MOSI 23, CS 5.
#include <SPI.h>
const int SCK_PIN = 18, MISO_PIN = 19, MOSI_PIN = 23, CS_PIN = 5;
void setup() {
  Serial.begin(115200);
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  Serial.println("SPI loopback test: connect MOSI to MISO.");
}
void loop() {
  const uint8_t sent = 0xA5;
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(CS_PIN, LOW);
  uint8_t received = SPI.transfer(sent);
  digitalWrite(CS_PIN, HIGH);
  SPI.endTransaction();
  Serial.print("Sent 0x"); Serial.print(sent, HEX);
  Serial.print(" | Received 0x"); Serial.println(received, HEX);
  if (received == sent) Serial.println("Loopback OK");
  else Serial.println("Check MOSI-MISO jumper");
  delay(1000);
}