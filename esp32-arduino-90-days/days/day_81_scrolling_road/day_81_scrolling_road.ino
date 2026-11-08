// Day 81: Animate a scrolling three-lane road on the OLED.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
unsigned long lastFrame=0;
int roadOffset=0;
void setup(){
  Wire.begin(21,22);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
}
void loop(){
  if(millis()-lastFrame<33)return;
  lastFrame=millis();
  roadOffset=(roadOffset+2)%16;
  display.clearDisplay();
  display.drawLine(46,0,46,63,SSD1306_WHITE);
  display.drawLine(82,0,82,63,SSD1306_WHITE);
  for(int y=-16+roadOffset;y<64;y+=16){
    display.drawFastVLine(64,y,8,SSD1306_WHITE);
  }
  display.fillRoundRect(57,49,14,12,3,SSD1306_WHITE);
  display.display();
}