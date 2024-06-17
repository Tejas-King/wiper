#include <Servo.h>

#define RAIN_SENSOR_PIN A0 // Arduino pin connected to rain sensor's pin
#define SERVO_PIN       9  // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int prev_rain_state;    // the previous state of rain sensor
int rain_state; // the current state of rain sensor

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(RAIN_SENSOR_PIN, INPUT); // set arduino pin to input mode
  servo.attach(SERVO_PIN);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  rain_state = digitalRead(RAIN_SENSOR_PIN);
}

void loop() {
  prev_rain_state = rain_state;             // save the last state
  rain_state = digitalRead(RAIN_SENSOR_PIN); // read new state

  if (rain_state == LOW && prev_rain_state == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Rain detected!");
    servo.write(90);
  }
  else
  if (rain_state == HIGH && prev_rain_state == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Rain stopped!");
    servo.write(0);
  }
}
