#include <Servo.h> 

int servoPin = 6;
 
Servo servo;  
 
int angle = servo.read();   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); 
  Serial.begin(9600); 
} 
 
 
void loop() 
{ 
  //start at the correct location
  if(angle > 0)
  {
    for(angle; angle > 0; angle--)    
    {                                
      servo.write(angle);           
      delay(20);   
    } 
  }
  
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle);     
    delay(20);    
  } 
  
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(20);   
  } 
} 
