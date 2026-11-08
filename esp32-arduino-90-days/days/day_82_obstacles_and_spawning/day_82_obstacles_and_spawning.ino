// Day 82: Spawn and move obstacles down the three-lane road.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
const int laneX[]={28,64,100};
int obstacleLane=1, obstacleY=-12, roadOffset=0;
unsigned long lastFrame=0;
void setup(){
  randomSeed(analogRead(34));
  Wire.begin(21,22);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
}
void loop(){
  if(millis()-lastFrame<40)return;
  lastFrame=millis();
  roadOffset=(roadOffset+2)%16;
  obstacleY+=2;
  if(obstacleY>64){obstacleY=-12;obstacleLane=random(0,3);}
  display.clearDisplay();
  display.drawLine(46,0,46,63,SSD1306_WHITE);
  display.drawLine(82,0,82,63,SSD1306_WHITE);
  for(int y=-16+roadOffset;y<64;y+=16)display.drawFastVLine(64,y,8,SSD1306_WHITE);
  display.fillRect(laneX[obstacleLane]-6,obstacleY,12,10,SSD1306_WHITE);
  display.fillRoundRect(57,49,14,12,3,SSD1306_WHITE);
  display.display();
}