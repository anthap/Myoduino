#include <MyoController.h>

#define CLAW 11
#define BASE 6
#define LEFT 10
#define RIGHT 9

MyoController myo = MyoController();

void setup()
{
  Serial.begin(9600);
  pinMode(CLAW, OUTPUT);
  pinMode(BASE, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  
  myo.initMyo();
}

void loop() 
{
  //myo.updatePose();
  
  Serial.print('hellow');
    
  if(myo.getCurrentPose() == fist)
  {
    Serial.print("Its working yall");
  }
  
  delay(100);
}
