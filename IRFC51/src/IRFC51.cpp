//-----------------------------------------------------//
//--------------------- Libraries -------------------- //
#include "IRFC51.h"
//-----------------------------------------------------//
//-----------------------------------------------------//
//---------------------- LAYOUT ---------------------- //
//                      -----------------------------
// Digital pin    OUT  |                        | TX |
// Micro GND      GND  |        IR FC-51        | ---
// Micro VCC      VCC  |                        | RX |
//                      -----------------------------
//-----------------------------------------------------//
//------------------ Constructors ---------------------//
IRFC51::IRFC51(  int new_signal_pin  ) {
  SIGNAL_pin = new_signal_pin;
  IRFC51_init_();
}
//-----------------------------------------------------//
//-------------------- Getters ------------------------//
int IRFC51::get_signal_pin() {
  return (SIGNAL_pin);
}
int IRFC51::get_state() {
  return (STATE);
}
int IRFC51::get_object() {
  return (OBJECT);
}
//-----------------------------------------------------//
//-------------------- Setters ------------------------//
void IRFC51::set_signal_pin(int newpin) {
  SIGNAL_pin = newpin;
}
//-----------------------------------------------------//
//-------------------- Methods ------------------------//
void IRFC51::IRFC51_init_() {
  pinMode(SIGNAL_pin, INPUT);
  switch_STATE_up();
}


void IRFC51::switch_STATE() {
  STATE = !STATE;
}


void IRFC51::switch_STATE_up() {
  STATE = 1;
}


void IRFC51::switch_STATE_down() {
  STATE = 0;
}


void IRFC51::detect_object() {
  if (STATE == 1) {
    OBJECT = !digitalRead(SIGNAL_pin);
  } else {
    OBJECT = OBJECT;
  }
}


void IRFC51::toString() {
  Serial.begin(9600);
  Serial.println("PIN\tSTATE\tOBJECT");
  Serial.println("" + String(SIGNAL_pin) + "\t" + 
                 "" + String(STATE) + "\t" + 
                 "" + String(OBJECT) + "\t");
  Serial.end();
  
}


void IRFC51::IRFC51_Test() {
  Serial.begin(9600);

  Serial.println("Switch state up");
  switch_STATE_up();
  
  Serial.println("Detect Object");
  detect_object();
  
  toString();
  delay(3000);

  Serial.end();
}
