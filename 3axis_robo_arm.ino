#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  // create Adafruit_PWMServoDriver object

int servo1_channel = 0;  // assign each servo to a channel on the servo controller
int servo2_channel = 1;
int servo3_channel = 2;
int servo4_channel = 3;

int joystick_x = A0;   // joystick x direction pin
int joystick_y = A1;   // joystick y direction pin
int joystick_x2 = A2;  // joystick x direction pin
int joystick_y2 = A3;  // joystick y direction pin

int pos_x;   // declare variable to store horizontal value of jk1
int pos_y;   // declare variable to store vertical value of jk1
int pos_x2;  // declare variable to store horizontal value of jk2
int pos_y2;  // declare variable to store vertical value of jk2

int servo1_pos = 90;  // storing servo position
int servo2_pos = 90;
int servo3_pos = 90;
int servo4_pos = 90;

void setup() {
  Serial.begin(9600);
  pwm.begin();         // initialize Adafruit_PWMServoDriver object
  pwm.setPWMFreq(60);  // set PWM frequency
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(joystick_x2, INPUT);
  pinMode(joystick_y2, INPUT);
}

void loop() {
  pos_x = analogRead(joystick_x);
  pos_y = analogRead(joystick_y);
  pos_x2 = analogRead(joystick_x2);
  pos_y2 = analogRead(joystick_y2);

  if (pos_x < 300) {        //if the horizontal value from joystick is less than 300
    if (servo1_pos < 10) {  // first servo moves right
    } else {
      servo1_pos = servo1_pos - 20;
      pwm.setPWM(servo1_channel, 0, map(servo1_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }

  if (pos_x > 700) {
    if (servo1_pos > 180) {  // first servo moves left
    } else {
      servo1_pos = servo1_pos + 20;
      pwm.setPWM(servo1_channel, 0, map(servo1_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }

  if (pos_y < 300) {        //if the vertical value from joystick is less than 300
    if (servo2_pos < 10) {  // second servo moves up
    } else {
      servo2_pos = servo2_pos - 20;
      pwm.setPWM(servo2_channel, 0, map(servo2_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }

  if (pos_y > 700) {
    if (servo2_pos > 180) {  // second servo moves down
    } else {
      servo2_pos = servo2_pos + 20;
      pwm.setPWM(servo2_channel, 0, map(servo2_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }


  ///////

  if (pos_x2 < 300) {        //if the horizontal value from joystick is less than 300
    if (servo3_pos < 10) {  // third servo moves right
    } else {
      servo3_pos = servo3_pos - 20;
      pwm.setPWM(servo3_channel, 0, map(servo3_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }

  if (pos_x2 > 700) {
    if (servo3_pos > 180) {  // third servo moves left
    } else {
      servo3_pos = servo3_pos + 20;
      pwm.setPWM(servo3_channel, 0, map(servo3_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }

  if (pos_y2 < 300) {        //if the vertical value from joystick is less than 300
    if (servo4_pos < 10) {  // fourth servo moves up
    } else {
      servo4_pos = servo4_pos - 20;
      pwm.setPWM(servo4_channel, 0, map(servo4_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }

  if (pos_y2 > 700) {
    if (servo4_pos > 180) {  // fourth servo moves down
    } else {
      servo4_pos = servo4_pos + 20;
      pwm.setPWM(servo4_channel, 0, map(servo4_pos, 0, 180, 100, 600));  // map servo position to PWM signal and set it on the servo controller
      delay(100);
    }
  }
}
