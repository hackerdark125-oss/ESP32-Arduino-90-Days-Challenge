// Day 88: Fixed-timestep game loop with bounded catch-up and minimal allocations.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
const int LEFT=32,RIGHT=33,laneX[]={28,64,100};
const uint32_t FRAME_US=33333;
uint32_t nextFrame=0;
int player=1,obLane=0,obY=-10,score=0,lastL=HIGH,lastR=HIGH;
bool crashed=false;
void setup(){
 pinMode(LEFT,INPUT_PULLUP);pinMode(RIGHT,INPUT_PULLUP);randomSeed(analogRead(34));
 Wire.begin(21,22);if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
 nextFrame=micros();
}
void loop(){
 uint32_t now=micros();
 if((int32_t)(now-nextFrame)<0)return;
 nextFrame+=FRAME_US;
 int l=digitalRead(LEFT),r=digitalRead(RIGHT);
 if(!crashed){
  if(l==LOW&&lastL==HIGH&&player>0)player--;
  if(r==LOW&&lastR==HIGH&&player<2)player++;
  obY+=2;
  if(obY>64){obY=-10;obLane=random(0,3);score++;}
  if(player==obLane&&obY>=47&&obY<=61)crashed=true;
 }
 lastL=l;lastR=r;
 display.clearDisplay();
 display.drawLine(46,0,46,63,SSD1306_WHITE);display.drawLine(82,0,82,63,SSD1306_WHITE);
 display.fillRect(laneX[obLane]-6,obY,12,10,SSD1306_WHITE);
 display.fillRoundRect(laneX[player]-7,49,14,12,3,SSD1306_WHITE);
 display.setTextSize(1);display.setTextColor(SSD1306_WHITE);display.setCursor(0,0);display.print("Score:");display.print(score);
 if(crashed){display.setCursor(35,28);display.print("CRASH");}
 display.display();
}