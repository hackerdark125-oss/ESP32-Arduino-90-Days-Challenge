// Day 85: Add simple buzzer tones for score and collision events.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128,64,&Wire,-1);
const int LEFT=32,RIGHT=33,BUZZER=25,laneX[]={28,64,100};
int player=1,obLane=0,obY=-10,score=0,lastL=HIGH,lastR=HIGH;
bool over=false;unsigned long frameAt=0,moveAt=0;
void beep(int hz,int ms){ledcWriteTone(BUZZER,hz);delay(ms);ledcWriteTone(BUZZER,0);}
void setup(){
 pinMode(LEFT,INPUT_PULLUP);pinMode(RIGHT,INPUT_PULLUP);randomSeed(analogRead(34));
 ledcAttach(BUZZER,2000,8);
 Wire.begin(21,22);if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))while(true)delay(1000);
}
void loop(){
 if(millis()-frameAt<40)return;frameAt=millis();
 int l=digitalRead(LEFT),r=digitalRead(RIGHT);
 if(!over&&millis()-moveAt>140){
  if(l==LOW&&lastL==HIGH&&player>0){player--;moveAt=millis();}
  if(r==LOW&&lastR==HIGH&&player<2){player++;moveAt=millis();}
 }
 lastL=l;lastR=r;
 if(!over){
  obY+=2;
  if(obY>64){obY=-10;obLane=random(0,3);score++;beep(1200,35);}
  if(player==obLane&&obY>=47&&obY<=61){over=true;beep(220,300);}
 }
 display.clearDisplay();display.drawLine(46,0,46,63,SSD1306_WHITE);display.drawLine(82,0,82,63,SSD1306_WHITE);
 display.fillRect(laneX[obLane]-6,obY,12,10,SSD1306_WHITE);display.fillRoundRect(laneX[player]-7,49,14,12,3,SSD1306_WHITE);
 display.setTextSize(1);display.setTextColor(SSD1306_WHITE);display.setCursor(0,0);display.print("Score: ");display.print(score);
 if(over){display.setCursor(35,28);display.print("CRASH!");}
 display.display();
}