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

//=========================================
// ledOnOff
//=========================================
unsigned int count;
void ledOnOff(void) {
  if(++count >= 500)
  {
     count -= 500;
     digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}

//=========================================
// setup
//=========================================
void setup(void) {
  Serial.begin(115200); delay(1000);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, 1);
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
