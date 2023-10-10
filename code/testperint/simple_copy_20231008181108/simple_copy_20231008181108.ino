//========================================================================
// program name : simple.ino
// date/author  : 2022/04/24 v0.0.1 @chromlinux03
// date/update  : 2022/04/25 v0.0.2 Changed interrupt to pass a function pointer
// github       : https://github.com/chrmlinux/tinyTimeR
// Specifies the interrupt interval in microseconds
//========================================================================
#include "tinyTimeR.hpp"
static tinyTimeR tt;
#define LED_PIN (13)
#define LED_RED_PIN (14)
#define LED_GREEN_PIN (15)
#define LED_BLUE_PIN (16)

//=========================================
// ledOnOff
//=========================================
unsigned int count;
unsigned int color = 0;
void ledOnOff(void) {
  if(++count >= 1000)
  {
     count -= 1000;
     digitalWrite(LED_PIN, !digitalRead(LED_PIN));
     digitalWrite(LED_RED_PIN, (color & 1));
     digitalWrite(LED_GREEN_PIN, (color & 2));
     digitalWrite(LED_BLUE_PIN, (color & 4));
     --color;
  }
}

//=========================================
// setup
//=========================================
void setup(void) {
  Serial.begin(115200); delay(1000);

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  digitalWrite(LED_PIN, 1);
  digitalWrite(LED_RED_PIN, 1);
  digitalWrite(LED_GREEN_PIN, 1);
  digitalWrite(LED_BLUE_PIN, 1);
  count = 0;
  
  tt.begin(ledOnOff, 1000);

  Serial.write("starting test2\n");
}

//=========================================
// loop
//=========================================
void loop(void) 
{
  if(Serial.available())
  {
    int ichar = Serial.read();
    Serial.write(ichar);
  }
}
