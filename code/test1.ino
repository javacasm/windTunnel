#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 700
#define MOTOR_PIN 9

Servo ESC;

void setup() {
Serial.begin(9600);
Serial.println("Program begin...");
Serial.println("This program will calibrate the ESC.");

ESC.attach(MOTOR_PIN);

Serial.println("Now writing maximum output.");
Serial.println("Turn on power source, then wait 2 seconds and press any key.");
ESC.writeMicroseconds(MAX_SIGNAL);

// Wait for input-
// while (!Serial.available());
//Serial.read();
delay(1000);
// Send min output
Serial.println("Sending minimum output");
ESC.writeMicroseconds(MIN_SIGNAL);

delay(2000);
Serial.println("Run!!");
}
int value=0;
void loop() {
  ESC.writeMicroseconds(value);
  Serial.println(value);
  if(Serial.available()) 
    value = Serial.parseInt();    // Parse an Integer from Serial
  else
  {
    int pot=map(analogRead(A0),0,1023,700,2000);
    if(pot!=value)
      value=pot;
  }
}
