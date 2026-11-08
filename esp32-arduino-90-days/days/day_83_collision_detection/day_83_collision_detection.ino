// Day 83: Add player movement and rectangle-based collision detection.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
const int LEFT=32, RIGHT=33, laneX[]={28,64,100};
int playerLane=1, obstacleLane=0, obstacleY=-10, roadOffset=0;
int lastLeft=HIGH,lastRight=HIGH;
bool crashed=false;
unsigned long lastFrame=0,lastMove=0;
bool overlaps(int ax,int ay,int aw,int ah,int bx,int by,int bw,int bh){
  return ax<bx+bw && ax+aw>bx && ay<by+bh && ay+ah>by;
}
void setup(){
  pinMode(LEFT,INPUT_PULLUP);pinMode(RIGHT,INPUT_PULLUP);
  randomSeed(analogRead(34));Wire.begin(21,22);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
}
void loop(){
  if(millis()-lastFrame<40)return;lastFrame=millis();
  int l=digitalRead(LEFT),r=digitalRead(RIGHT);
  if(!crashed && millis()-lastMove>140){
    if(l==LOW&&lastLeft==HIGH&&playerLane>0){playerLane--;lastMove=millis();}
    if(r==LOW&&lastRight==HIGH&&playerLane<2){playerLane++;lastMove=millis();}
  }
  lastLeft=l;lastRight=r;
  if(!crashed){
    obstacleY+=2;
    if(obstacleY>64){obstacleY=-10;obstacleLane=random(0,3);}
    if(overlaps(laneX[playerLane]-7,49,14,12,laneX[obstacleLane]-6,obstacleY,12,10))crashed=true;
  }
  display.clearDisplay();
  display.drawLine(46,0,46,63,SSD1306_WHITE);display.drawLine(82,0,82,63,SSD1306_WHITE);
  display.fillRect(laneX[obstacleLane]-6,obstacleY,12,10,SSD1306_WHITE);
  display.fillRoundRect(laneX[playerLane]-7,49,14,12,3,SSD1306_WHITE);
  if(crashed){display.setTextSize(1);display.setTextColor(SSD1306_WHITE);display.setCursor(32,25);display.print("CRASH!");}
  display.display();
}