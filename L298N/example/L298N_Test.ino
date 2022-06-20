//-----------------------------------------------------//
//-------------------- Libraries ----------------------//
#include "Arduino.h"
#include "L298N.h"
//-----------------------------------------------------//
//--------------------- Objects -----------------------//
//L298N *name* (IN1,IN2,IN3,IN4)
//L298N no_enables_motor_driver (7,8,9,10);

//L298N *name* (ENA,ENB,IN1,IN2,IN3,IN4)
L298N enables_motor_driver (3,3,4,5,6,7);
//-----------------------------------------------------//
//---------------------- Setup ------------------------//
void setup() {
  // bah-bah-bah bah bah-bah-bah bah bah
  // https://youtu.be/D-UmfqFjpl0
}

void loop() { 
  //no_enables_motor_driver.motorTest();
  //enables_motor_driver.motorTest();
  enables_motor_driver.roll_clockwise_A(100);
  delay(500);
  enables_motor_driver.roll_counter_clockwise(100);
  delay(500);
}
