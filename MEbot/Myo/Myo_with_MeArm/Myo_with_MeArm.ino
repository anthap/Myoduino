#include <MyoController.h>
#include <Servo.h> 

MyoController myo = MyoController();

int servoPinClaw = 3;
int servoPinBase = 9;
int servoPinLeft = 6;
int servoPinRight = 5;

Servo servoClaw;
Servo servoBase;
Servo servoLeft;
Servo servoRight;

int ClawAngle = 25;   // servo position in degrees
int BaseAngle = 90;
int RightAngle = 70;
int LeftAngle = 90;
//int flag = 0;

void setup() 
{
  //pinMode(11, OUTPUT); //What does this do?
  
  myo.initMyo();
  servoClaw.attach(servoPinClaw);
  servoBase.attach(servoPinBase);
  servoRight.attach(servoPinRight);
  servoLeft.attach(servoPinLeft);
  
  Serial.begin(9600);
}

void loop()
{
  myo.updatePose();

  
  //FINGERS SPREAD opens claw
  while(myo.getCurrentPose() == fingersSpread)
  {
    //Opening the claws
    if(servoClaw.read() > 25)
    {
      ClawAngle--;
      servoClaw.write(ClawAngle);     
      delay(20);
    }
    myo.updatePose();
  }
  
  myo.updatePose();
  
  //FIST closes claw
  while(myo.getCurrentPose() == fist)
  {
    //Closing the Claws
    if(servoClaw.read() < 70)
    {
      ClawAngle++;
      servoClaw.write(ClawAngle);     
      delay(20);
    }
    myo.updatePose();
  }
  
   myo.updatePose();
   
  //WAVE OUT turns base left
  while(myo.getCurrentPose() == waveOut)
  {
    //Turning base
    if(servoBase.read() < 165)
    {
      BaseAngle++;
      servoBase.write(BaseAngle);     
      delay(20);
    }
    myo.updatePose();
  }
  
   myo.updatePose();
   
  //WAVE IN turns base right
  while(myo.getCurrentPose() == waveIn)
  {
    //Turning base
    if(servoBase.read() > 15)
    {
      BaseAngle--;
      servoBase.write(BaseAngle);     
      delay(20);
    }
    myo.updatePose();
  }
  
   myo.updatePose();
   
  //Double Tap moves arm up and then down one double tap again
 /*if(myo.getCurrentPose() == doubleTap)
 {
   if (flag ==0)
   {
     while(servoRight.read() > 60)
     {
      RightAngle--;
      servoRight.write(RightAngle);     
      delay(20);
      digitalWrite(11, HIGH);
     }
     flag = 1;
   }
   
    else
   {
      while(servoRight.read() < 160)
      {
        RightAngle++;
        servoRight.write(RightAngle);     
        delay(20);
        digitalWrite(11, LOW);
      }
      flag = 0;   
   }
 }
  delay(50);*/
}
