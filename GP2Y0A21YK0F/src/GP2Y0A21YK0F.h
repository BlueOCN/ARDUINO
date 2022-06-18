#ifndef GP2Y0A21YK0F_H
#define GP2Y0A21YK0F_H
//-----------------------------------------------------//
//--------------------- Libraries -------------------- //
#include "Arduino.h"
//-----------------------------------------------------//
//--------------------- Class -------------------------//
class GP2Y0A21YK0F {

  protected:
    int SIGNAL_pin;
    float SAMP;
    float VADC;
    float DIST;

  public:
    GP2Y0A21YK0F ( int SIGNAL_pin );

    int get_SIGNAL_pin();
    float get_SAMP();
    float get_VADC();
    float get_DIST();
    float get_stable_DIST();

    void set_SIGNAL_pin(int newpin);
    void set_SAMP(int newpin);
    void set_VADC(int newpin);
    void set_DIST(int newpin);

    void GP2Y0A21YK0F_init_();
    void GP2Y0A21YK0F_test_();

};

#endif
