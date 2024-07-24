#include <Servo.h>
#Arduino code to control stepper motor and servo to push item into corresponding bucket
Servo myservo;   
const int irSensorPin = 53;   // IR Sensor connected to digital pin 2
const int stepPin = 2; //X.STEP
const int dirPin = 5; // X.DIR
void setup() {
  pinMode(irSensorPin, INPUT);  // Set the IR sensor pin as input
  pinMode(stepPin,OUTPUT); 
 pinMode(dirPin,OUTPUT);
 myservo.attach(51);
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect.
  }

}

 
void loop() {
  char buffer[16];
  int sensorState = digitalRead(irSensorPin); // Read the state from the IR sensor
 
  // The sensor outputs LOW when it detects an obstacle
  if (sensorState == LOW) {  
    Serial.println("trash detected");
  } else {
    
  }
 
  delay(1000);  // Wait for 100 milliseconds
  if (Serial.available() > 0) { 
    int size = Serial.readBytesUntil('\n', buffer, 12); #Serial communication with computer via Serial port
    if (buffer[0] == 'Y') {
       digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      for(int x = 0; x < 1000; x++) {
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(500); 
      }
      myservo.write(180);
      delay(1000); // One second delay
 
      digitalWrite(dirPin,LOW); //Changes the rotations direction
 // Makes 400 pulses for making two full cycle rotation
      for(int x = 0; x < 1000; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(500);
      }
      delay(1000);
      myservo.write(-180);
    }
    else{

    }
  }
}
