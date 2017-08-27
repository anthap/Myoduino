#include <MyoController.h>
//#include <Servo.h> 

//int servoPin = 6;
//Servo servo;  
//int angle = servo.read();   // servo position in degrees 

MyoController myo = MyoController();

void setup() {
  
  //servo.attach(servoPin); 
  //Serial.begin(9600); 

  myo.initMyo();
}

void loop() {
  
  myo.updatePose();
  Serial.println("HI");
  if ( myo.getCurrentPose() == rest)
  {
    Serial.println("Why you no work!!!!");
  }
  
  Serial.print(myo.getCurrentPose());
  delay(1000);

}
