// Day 3: Serial Monitor basics.
unsigned long readingNumber=0;
void setup(){
  Serial.begin(115200);
  delay(300);
  Serial.println("Hello from ESP32");
}
void loop(){
  Serial.print("Reading number: ");
  Serial.println(readingNumber++);
  Serial.print("Millis since boot: ");
  Serial.println(millis());
  delay(1000);
}