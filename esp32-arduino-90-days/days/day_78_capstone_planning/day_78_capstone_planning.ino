// Day 78: Capstone planning - ESP32 OLED racing game.
// This sketch verifies Serial and prints the planned hardware/architecture.
void setup(){
  Serial.begin(115200);
  Serial.println("ESP32 RACING GAME - CAPSTONE PLAN");
  Serial.println("Display: SSD1306 128x64 I2C OLED (SDA21/SCL22)");
  Serial.println("Controls: left button GPIO32, right button GPIO33");
  Serial.println("Optional sound: passive buzzer GPIO25");
  Serial.println("Game: fixed update loop, lanes, obstacles, collision, score");
  Serial.println("Storage: Preferences/NVS high score");
}
void loop(){}