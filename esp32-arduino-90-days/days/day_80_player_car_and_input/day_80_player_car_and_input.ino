// Day 80: Move a player car between three lanes using two buttons.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
const int LEFT_BUTTON=32, RIGHT_BUTTON=33;
int playerLane=1, lastLeft=HIGH, lastRight=HIGH;
unsigned long lastMove=0;
const int laneX[]={28,64,100};
void setup(){
  pinMode(LEFT_BUTTON,INPUT_PULLUP); pinMode(RIGHT_BUTTON,INPUT_PULLUP);
  Wire.begin(21,22);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
}
void loop(){
  int left=digitalRead(LEFT_BUTTON), right=digitalRead(RIGHT_BUTTON);
  if(millis()-lastMove>140){
    if(left==LOW && lastLeft==HIGH && playerLane>0){playerLane--;lastMove=millis();}
    if(right==LOW && lastRight==HIGH && playerLane<2){playerLane++;lastMove=millis();}
  }
  lastLeft=left; lastRight=right;
  display.clearDisplay();
  display.drawLine(46,0,46,63,SSD1306_WHITE);
  display.drawLine(82,0,82,63,SSD1306_WHITE);
  int x=laneX[playerLane];
  display.fillRoundRect(x-7,48,14,12,3,SSD1306_WHITE);
  display.setTextSize(1);display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);display.print("LEFT / RIGHT");
  display.display();
}