#include <MyoController.h>


#define FIST_PIN 11
#define WAVEIN_PIN 10
#define WAVEOUT_PIN 9
#define DOUBLETAP_PIN 8
#define FINGERSSPREAD_PIN 6

MyoController myo = MyoController();

void setup() {

  Serial.begin(9600); 
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  
  myo.initMyo();
}

void loop()
{
   //Serial.println("HI");
   myo.updatePose();
   
   switch ( myo.getCurrentPose() ) {
    case fist:
      digitalWrite(FIST_PIN, HIGH);
      break;
    case waveIn:
      digitalWrite(WAVEIN_PIN, HIGH);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN, HIGH);
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN, HIGH);
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN, HIGH);
      break;
   } 
   delay(100);
}
