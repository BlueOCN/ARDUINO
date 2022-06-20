//-----------------------------------------------------//
//-------------------- Libraries ----------------------//
#include "Arduino.h"
#include "L298N.h"
//-----------------------------------------------------//
//------------------ Constructors ---------------------//
L298N::L298N ( int IN1_newpin, int IN2_newpin, int IN3_newpin, int IN4_newpin ) {

  STATUS = -1;
  ENA_pin = -1;
  ENB_pin = -1;
  IN1_pin = IN1_newpin;
  IN2_pin = IN2_newpin;
  IN3_pin = IN3_newpin;
  IN4_pin = IN4_newpin;
  pinMode(IN1_pin, OUTPUT);
  pinMode(IN2_pin, OUTPUT);
  pinMode(IN3_pin, OUTPUT);
  pinMode(IN4_pin, OUTPUT);
  
}

L298N::L298N ( int _ENA_pin, int _ENB_pin, int _IN1_pin,int _IN2_pin, int _IN3_pin, int _IN4_pin ) {
  
  STATUS = -1;
  ENA_pin = _ENA_pin;
  ENB_pin = _ENB_pin;
  IN1_pin = _IN1_pin;
  IN2_pin = _IN2_pin;
  IN3_pin = _IN3_pin;
  IN4_pin = _IN4_pin;
  pinMode(ENA_pin, OUTPUT);
  pinMode(ENB_pin, OUTPUT);
  pinMode(IN1_pin, OUTPUT);
  pinMode(IN2_pin, OUTPUT);
  pinMode(IN3_pin, OUTPUT);
  pinMode(IN4_pin, OUTPUT);
}
//-----------------------------------------------------//
//-------------------- Getters ------------------------//
int L298N::get_ENA_pin() {
  return (ENA_pin);
}
int L298N::get_ENB_pin() {
  return (ENB_pin);
}
int L298N::get_IN1_pin() {
  return (IN1_pin);
}
int L298N::get_IN2_pin() {
  return (IN2_pin);
}
int L298N::get_IN3_pin() {
  return (IN3_pin);
}
int L298N::get_IN4_pin() {
  return (IN4_pin);
}
//-----------------------------------------------------//
//-------------------- Setters ------------------------//
void L298N::set_ENA_pin(int newpin) {
  IN1_pin = newpin;
}
void L298N::set_ENB_pin(int newpin) {
  IN1_pin = newpin;
}
void L298N::set_IN1_pin(int newpin) {
  IN1_pin = newpin;
}
void L298N::set_IN2_pin(int newpin) {
  IN2_pin = newpin;
}
void L298N::set_IN3_pin(int newpin) {
  IN3_pin = newpin;
}
void L298N::set_IN4_pin(int newpin) {
  IN4_pin = newpin;
}
//-----------------------------------------------------//
//-------------------- Methods ------------------------//
void L298N::free_movement() {
  free_movement_A();
  free_movement_B();
  STATUS = 0;
}


void L298N::free_movement_A() {
  STATUS = 9;
  if (ENA_pin == -1) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, LOW);
  } else {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, LOW);
    analogWrite (ENA_pin, 0);
  }
}


void L298N::free_movement_B() {
  STATUS = 10;
  if (ENB_pin == -1) { 
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, LOW);
  } else {
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, LOW);
    analogWrite (ENB_pin, 0);
  }
}


void L298N::fix_position() {
  fix_position_A();
  fix_position_B();
  STATUS = 0;
}


void L298N::fix_position_A() {
  STATUS = 11;
  if (ENA_pin == -1) {
    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, HIGH);
  } else {
    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, HIGH);
    analogWrite (ENA_pin, 150);
  }
}


void L298N::fix_position_B() {
  STATUS = 12;
  if (ENB_pin == -1) {
    digitalWrite(IN3_pin, HIGH);
    digitalWrite(IN4_pin, HIGH);
  } else {
    digitalWrite(IN3_pin, HIGH);
    digitalWrite(IN4_pin, HIGH);
    analogWrite (ENB_pin, 150);
  }
}


void L298N::roll_clockwise_A(int pwm) {
  STATUS = 5;
  if (ENA_pin == -1) {
    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, LOW);
  } else {
    digitalWrite(IN1_pin, HIGH);
    digitalWrite(IN2_pin, LOW);
    if (pwm > 255){analogWrite(ENA_pin, 255);}
    else if (pwm < 0){analogWrite(ENA_pin, 0);}
    else {analogWrite (ENA_pin, pwm);}
  }
}


void L298N::roll_clockwise_B(int pwm) {
  STATUS = 7;
  if (ENB_pin == -1) {
    digitalWrite(IN3_pin, HIGH);
    digitalWrite(IN4_pin, LOW);
  } else {
    digitalWrite(IN3_pin, HIGH);
    digitalWrite(IN4_pin, LOW);
    if (pwm > 255){analogWrite(ENB_pin, 255);}
    else if (pwm < 0){analogWrite(ENB_pin, 0);}
    else {analogWrite (ENB_pin, pwm);}
  }
}


void L298N::roll_counter_clockwise_A(int pwm) {
  STATUS = 6;
  if (ENA_pin == -1) {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, HIGH);
  } else {
    digitalWrite(IN1_pin, LOW);
    digitalWrite(IN2_pin, HIGH);
    if (pwm > 255){analogWrite(ENA_pin, 255);}
    else if (pwm < 0){analogWrite(ENA_pin, 0);}
    else {analogWrite (ENA_pin, pwm);}
  }
}


void L298N::roll_counter_clockwise_B(int pwm) {
  STATUS = 8;
  if (ENB_pin == -1) {
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, HIGH);
  } else {  
    digitalWrite(IN3_pin, LOW);
    digitalWrite(IN4_pin, HIGH);

    if (pwm > 255){analogWrite(ENB_pin, 255);}
    else if (pwm < 0){analogWrite(ENB_pin, 0);}
    else {analogWrite (ENB_pin, pwm);}
  }
}


void L298N::roll_clockwise(int pwm) {
  roll_clockwise_A(pwm);
  roll_clockwise_B(pwm);
  STATUS = 1;
}


void L298N::roll_counter_clockwise(int pwm) {
  roll_counter_clockwise_A(pwm);
  roll_counter_clockwise_B(pwm);
  STATUS = 2;
}


void L298N::rotate_left(int pwm) {
  roll_clockwise_A(pwm);
  roll_counter_clockwise_B(pwm);
  STATUS = 3;
}


void L298N::rotate_right(int pwm) {
  roll_counter_clockwise_A(pwm);
  roll_clockwise_B(pwm);
  STATUS = 4;
}


void L298N::set_ENA_PWM(int dutycycle) {
  if (ENA_pin > -1) { 
    analogWrite(ENA_pin, dutycycle);
  }
}


void L298N::set_ENB_PWM(int dutycycle) {
  if (ENB_pin > -1) { 
    analogWrite(ENB_pin, dutycycle);
  }
}


void L298N::set_ENS_PWM(int dutycycle) {
  set_ENA_PWM(dutycycle);
  set_ENB_PWM(dutycycle);
}


String L298N::status_str() {
  String str;
  switch (STATUS) {
    case 0:
      str = "IDLE";
      break;
      
    case 1:
      str = "CROLL";
      break;

    case 2:
      str = "CCROLL";
      break;

    case 3:
      str = "LEFT";
      break;

    case 4:
      str = "RIGHT";
      break;

    case 5:
      str = "ACROLL";
      break;

    case 6:
      str = "ACCROLL";
      break;

    case 7:
      str = "BCROLL";
      break;

    case 8:
      str = "BCCROLL";
      break;

    case 9:
      str = "AFRMOV";
      break;

    case 10:
      str = "BFRMOV";
      break;

    case 11:
      str = "AFXPOS";
      break;

    case 12:
      str = "BFXPOS";
      break;
      
    default:
      // if nothing else matches, do the default
      str = "INIT";
      break;
  }
  return str;
}


void L298N::motorTest() {
  Serial.begin(9600);
  Serial.print("\n\t\t---- 7 States motor test ----\t\t");
  Serial.print("\nMotor A roll clockwise 2 seconds ");
  roll_clockwise_A(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor A free movement ");
  free_movement_A();
  Serial.print(status_str());
  delay(2000);

  Serial.print("\nMotor A roll counterclockwise 2 seconds ");
  roll_counter_clockwise_A(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor A fix position ");
  fix_position_A();
  Serial.print(status_str());
  delay(2000);
  
  Serial.print("\nMotor B roll clockwise 2 seconds ");
  roll_clockwise_B(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor B free movement ");
  free_movement_B();
  Serial.print(status_str());
  delay(2000);

  Serial.print("\nMotor B roll counterclockwise 2 seconds ");
  roll_counter_clockwise_B(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor B fix position ");
  fix_position_B();
  Serial.print(status_str());
  delay(2000);

  Serial.print("\nMotor A&B roll clockwise 2 seconds ");
  roll_clockwise(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor A&B free movement ");
  free_movement();
  Serial.print(status_str());
  delay(2000);

  Serial.print("\nMotor A&B roll counterclockwise 2 seconds ");
  roll_counter_clockwise(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor A&B fix position ");
  fix_position();
  Serial.print(status_str());
  delay(2000);

  Serial.print("\nMotor turn left 2 seconds ");
  rotate_left(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor A&B fix position ");
  fix_position();
  Serial.print(status_str());
  delay(2000);

  Serial.print("\nMotor turn right 2 seconds ");
  rotate_right(125);
  Serial.print(status_str());
  delay(2000);
  Serial.print("\nMotor A&B fix position ");
  fix_position();
  Serial.print(status_str());
  delay(2000);
  
  Serial.print("\n\t\t---- 7 States motor test end ----\t\t\n");
  Serial.end();
}


void L298N::to_String() {
  Serial.begin(9600);
  Serial.print("\nENA PIN\tENB PIN\tSTATUS\t");
  Serial.print("\n" + String(ENA_pin) + "\t" + 
                 "" + String(ENB_pin) + "\t" +
                 "" + status_str() + "\t\n" );
  Serial.end();
}
