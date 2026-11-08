// Day 79: OLED display and fixed-rate game loop foundation.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
const unsigned long FRAME_MS=33;
unsigned long previousFrame=0;
uint32_t frameCount=0;
void setup(){
  Serial.begin(115200); Wire.begin(21,22);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){Serial.println("OLED missing");while(true)delay(1000);}
}
void loop(){
  unsigned long now=millis();
  if(now-previousFrame<FRAME_MS)return;
  previousFrame+=FRAME_MS;
  frameCount++;
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2); display.setCursor(12,10); display.println("RACE GAME");
  display.setTextSize(1); display.setCursor(20,38); display.println("Day 79 - Game Loop");
  display.setCursor(20,52); display.print("Frame "); display.print(frameCount);
  display.display();
}