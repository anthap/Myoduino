#include <MyoController.h>

#define FIST_PIN 4
#define WAVEIN_PIN 5
#define WAVEOUT_PIN 6
#define FINGERSSPREAD_PIN 7
#define DOUBLETAP_PIN 8

MyoController myo = MyoController();

void setup() {

  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  
  myo.initMyo();
}

void loop()
{
   Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      Serial.print("oops");
      break;
    case fist:
      Serial.print("hoops");
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH);
      break;
   } 
   delay(100);
}
