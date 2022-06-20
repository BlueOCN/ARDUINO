#ifndef L298N_H
#define L298N_H
//-----------------------------------------------------//
//--------------------- Libraries -------------------- //
#include "Arduino.h"
//-----------------------------------------------------//
//--------------------- Class -------------------------//
class L298N {

  protected:
    int STATUS;
    int ENA_pin;
    int ENB_pin;
    int IN1_pin;
    int IN2_pin;
    int IN3_pin;
    int IN4_pin;

  public:
    L298N ( int IN1_pin, int IN2_pin, int IN3_pin, int IN4_pin );
    L298N ( int _ENA_pin, int _ENB_pin, int _IN1_pin,int _IN2_pin, int _IN3_pin, int _IN4_pin );

    int get_ENA_pin();
    int get_ENB_pin();
    int get_IN1_pin();
    int get_IN2_pin();
    int get_IN3_pin();
    int get_IN4_pin();

    void set_ENA_pin(int newpin);
    void set_ENB_pin(int newpin);
    void set_ENA_PWM(int dutycycle);
    void set_ENB_PWM(int dutycycle);
    void set_ENS_PWM(int dutycycle);
    void set_IN1_pin(int newpin);
    void set_IN2_pin(int newpin);
    void set_IN3_pin(int newpin);
    void set_IN4_pin(int newpin);
    
    void free_movement_A();
    void free_movement_B();
    void free_movement();
    void fix_position_A();
    void fix_position_B();
    void fix_position();
    void roll_clockwise_A(int pwm);
    void roll_clockwise_B(int pwm);
    void roll_counter_clockwise_A(int pwm);
    void roll_counter_clockwise_B(int pwm);
    void roll_clockwise(int pwm);
    void roll_counter_clockwise(int pwm);
    void rotate_left(int pwm);
    void rotate_right(int pwm);
    void motorTest();

    String status_str();
    void to_String();
};
#endif
