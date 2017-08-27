#include <MyoController.h>

#define PITCH1 11
#define PITCH2 10
#define PITCH3 9
#define PITCH4 8
#define PITCH5 6

MyoController myo = MyoController();

void setup() {

  Serial.begin(9600); 
  pinMode(PITCH1, OUTPUT);
  pinMode(PITCH2, OUTPUT);
  pinMode(PITCH3, OUTPUT);
  pinMode(PITCH4, OUTPUT);
  pinMode(PITCH5, OUTPUT);
  
  myo.initMyo();
}

void loop()
{
   myo.updatePitch();
   
   if(myo.getCurrentPitch() == 1)
   {
      digitalWrite(PITCH1, HIGH);
   }
   
    if(myo.getCurrentPitch() == 2)
   {
      digitalWrite(PITCH2, HIGH);
   }
   
    if(myo.getCurrentPitch() == 3)
   {
      digitalWrite(PITCH3, HIGH);
   }
   
    if(myo.getCurrentPitch() == 4)
   {
      digitalWrite(PITCH4, HIGH);
   }
   
    if(myo.getCurrentPitch() == 5)
   {
      digitalWrite(PITCH5, HIGH);
   }
   
   delay(100);
}
