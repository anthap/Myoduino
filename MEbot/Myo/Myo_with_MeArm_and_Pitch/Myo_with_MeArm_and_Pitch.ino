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

int ClawAngle = 75;   // servo position in degrees
int BaseAngle = 90;
int RightAngle = 50;
int LeftAngle = 170;
int pitch = 0 ;
int prevPitch = 0;
int RightAngleEq = 0;
int LeftAngleEq = 0;

void setup() 
{ 
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

  if(myo.getCurrentPitch() != prevPitch && myo.getCurrentPitch() != 0)
  {
    pitch = myo.getCurrentPitch();
    
    //Move only the left servo
    if (pitch <= 8)
    { 
      while (servoRight.read() > 50)
      {
        RightAngle--;
        servoRight.write(RightAngle);
        delay(20);
      }

      LeftAngleEq = (((-10)*pitch)+170);
      while(LeftAngleEq > LeftAngle)
      {
        LeftAngle++;
        servoLeft.write(LeftAngle);
        delay(20);
      }
      
      while(LeftAngleEq < LeftAngle)
      {
        LeftAngle--;
        servoLeft.write(LeftAngle);
        delay(20);
      }
    }

    //Move only the right servo
    else
    {
      while (servoLeft.read() > 90)
      {
        LeftAngle--;
        servoLeft.write(LeftAngle);
        delay(20);
      }

      RightAngleEq = ((15*pitch)-85);
      while(RightAngleEq > RightAngle)
      {
        RightAngle++;
        servoRight.write(RightAngle);
        delay(20);
      }
      
      while(RightAngleEq < RightAngle)
      {
        RightAngle--;
        servoRight.write(RightAngle);
        delay(20);
      }

    }
    prevPitch = pitch;
  }
 delay(20);
}
