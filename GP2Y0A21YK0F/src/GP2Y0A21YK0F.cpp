//-----------------------------------------------------//
//--------------------- Libraries -------------------- //
#include "GP2Y0A21YK0F.h"
//-----------------------------------------------------//
//---------------------- LAYOUT ---------------------- //
//                      ---------
//                     |   Tx    |
//               ------|         |
// To Micro     |  Vo  | GP2Y0A  | -0.3 to Vcc+0.3
// To ground    | GND  | 21YK0F  | 0V Typ
// -0.3V to +7V | VCC  |         | 5V Typ
//               ------|         |
//                     |   Rx    |
//                      ---------
//-----------------------------------------------------//
//-----------------------------------------------------//
//------------------ Constructors ---------------------//
GP2Y0A21YK0F::GP2Y0A21YK0F( int new_SIGNAL_pin ) {
  SIGNAL_pin = new_SIGNAL_pin;
  GP2Y0A21YK0F_init_();
}
//-----------------------------------------------------//
//-------------------- Getters ------------------------//
int GP2Y0A21YK0F::get_SIGNAL_pin() {
  return (SIGNAL_pin);
}
float GP2Y0A21YK0F::get_SAMP() {
  SAMP = analogRead(SIGNAL_pin);
  return (SAMP);
}
float GP2Y0A21YK0F::get_VADC() {
  float Vref = 5.0;
  VADC = (Vref/1023.0)*get_SAMP();
  return (VADC);
}
float GP2Y0A21YK0F::get_DIST() {
  if (get_VADC() >= 2.25){ DIST = 10.0; }
  else if (get_VADC() <= 0.435) { DIST = 80.0; }
  else {
    DIST = 28.365 * (pow(get_VADC(), -1.218));
  }
  return (DIST);
}
float GP2Y0A21YK0F::get_stable_DIST() {
  delay(50);      // Time until measurment stabilizes
  if (get_VADC() >= 2.25){ DIST = 10.0; }
  else if (get_VADC() <= 0.435) { DIST = 80.0; }
  else {
    DIST = 28.365 * (pow(get_VADC(), -1.218));
  }
  return (DIST);
}
//-----------------------------------------------------//
//-------------------- Setters ------------------------//
void GP2Y0A21YK0F::set_SIGNAL_pin(int newpin) {
  SIGNAL_pin = newpin;
}
void GP2Y0A21YK0F::set_SAMP(int newSamp) {
  SAMP = newSamp;
}
void GP2Y0A21YK0F::set_VADC(int newVADC) {
  VADC = newVADC;
}
void GP2Y0A21YK0F::set_DIST(int newDIST) {
  DIST = newDIST;
}
//-----------------------------------------------------//
//-------------------- Methods ------------------------//
void GP2Y0A21YK0F::GP2Y0A21YK0F_init_() {
  analogReference(DEFAULT);
  pinMode(SIGNAL_pin, INPUT);
}
void GP2Y0A21YK0F::GP2Y0A21YK0F_test_() {
  Serial.begin(9600);/*
  Serial.println("\nUnstable distance read");
  get_DIST();
  Serial.println("PIN: " + String(SIGNAL_pin) 
               + "\t\tSAMP: " + String(SAMP) 
               + "\tVADC: " + String(VADC) 
               + "\tDIST: " + String(DIST));
  Serial.println("Stable distance read");*/
  get_stable_DIST();
  Serial.println("PIN: " + String(SIGNAL_pin) 
               + "\t\tSAMP: " + String(SAMP) 
               + "\tVADC: " + String(VADC) 
               + "\tDIST: " + String(DIST));
  Serial.end();
}
