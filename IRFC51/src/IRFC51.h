#ifndef IRFC51_H
#define IRFC51_H
//-----------------------------------------------------//
//--------------------- Libraries -------------------- //
#include "Arduino.h"
//-----------------------------------------------------//
//--------------------- Class -------------------------//
class IRFC51 {

  protected:
    int SIGNAL_pin;
    int STATE;
    int OBJECT;

  public:
    IRFC51( int SIGNAL_pin  );

    int get_signal_pin();
    int get_state();
    int get_object();

    void set_signal_pin(int newpin);

    void IRFC51_init_();
    void switch_STATE();
    void switch_STATE_up();
    void switch_STATE_down();
    
    void detect_object();

    void toString();

    void IRFC51_Test();

};

#endif
