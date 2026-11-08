// Day 87: Add title, playing and game-over states to the racing game.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
enum GameState{TITLE,PLAYING,GAME_OVER};
GameState state=TITLE;
const int LEFT=32,RIGHT=33,laneX[]={28,64,100};
int player=1,obLane=0,obY=-10,score=0,lastL=HIGH,lastR=HIGH;
unsigned long frameAt=0,moveAt=0;
void resetGame(){player=1;obLane=random(0,3);obY=-10;score=0;state=PLAYING;}
void setup(){
 pinMode(LEFT,INPUT_PULLUP);pinMode(RIGHT,INPUT_PULLUP);randomSeed(analogRead(34));
 Wire.begin(21,22);if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
}
void loop(){
 if(millis()-frameAt<40)return;frameAt=millis();
 int l=digitalRead(LEFT),r=digitalRead(RIGHT);
 if(state==TITLE && r==LOW && lastR==HIGH)resetGame();
 else if(state==GAME_OVER && (l==LOW&&lastL==HIGH || r==LOW&&lastR==HIGH))state=TITLE;
 else if(state==PLAYING){
  if(millis()-moveAt>140){
   if(l==LOW&&lastL==HIGH&&player>0){player--;moveAt=millis();}
   if(r==LOW&&lastR==HIGH&&player<2){player++;moveAt=millis();}
  }
  obY+=2;
  if(obY>64){obY=-10;obLane=random(0,3);score++;}
  if(player==obLane&&obY>=47&&obY<=61)state=GAME_OVER;
 }
 lastL=l;lastR=r;
 display.clearDisplay();display.setTextColor(SSD1306_WHITE);display.setTextSize(1);
 if(state==TITLE){display.setTextSize(2);display.setCursor(12,12);display.print("RACE GAME");display.setTextSize(1);display.setCursor(18,42);display.print("RIGHT = START");}
 else{
  display.drawLine(46,0,46,63,SSD1306_WHITE);display.drawLine(82,0,82,63,SSD1306_WHITE);
  display.fillRect(laneX[obLane]-6,obY,12,10,SSD1306_WHITE);display.fillRoundRect(laneX[player]-7,49,14,12,3,SSD1306_WHITE);
  display.setCursor(0,0);display.print("Score:");display.print(score);
  if(state==GAME_OVER){display.setCursor(30,28);display.print("GAME OVER");display.setCursor(12,42);display.print("PRESS TO MENU");}
 }
 display.display();
}