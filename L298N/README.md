# L298N
Arduino IDE library for the ST L298N Dual full bridge driver.
## ![L298N Dual H Bridge DC Stepper Motor Module Twins Chip 3-550x550w](https://user-images.githubusercontent.com/107767647/174517043-9c2c1b10-d21c-4f86-a766-66006bcef72f.jpg)
[Click here to access L298N datasheet!](https://www.st.com/resource/en/datasheet/l298.pdf "L298N's Datasheet")

## VARIABLES

|Access Specifier|Type|Name|Description
|:-----|:-----|:-----|:----------
|Protected|int|**STATUS**|Motor driver's state flag (0:OFF 1:ON)
|Protected|int|**ENA_pin**|Arduino board pin where the TTL compatible Enable A input is connected
|Protected|int|**ENB_pin**|Arduino board pin where the TTL compatible Enable B input is connected
|Protected|int|**IN1_pin**|Arduino board pin where the TTL compatible A input is connected (Linked to OUTPUT 1)
|Protected|int|**IN2_pin**|Arduino board pin where the TTL compatible A input is connected (Linked to OUTPUT 2)
|Protected|int|**IN3_pin**|Arduino board pin where the TTL compatible B input is connected (Linked to OUTPUT 3)
|Protected|int|**IN4_pin**|Arduino board pin where the TTL compatible B input is connected (Linked to OUTPUT 4)

## CONSTRUCTORS

|Access Specifier|Name|Parameters|Description
|:-----|:-----|:-----|:----------
|public|**L298N**|int IN1_pin, int IN2_pin, int IN3_pin, int IN4_pin| Creates an instance of the motor driver assumng A and B enables are connected to L298N module internal TTL power supply
|public|**L298N**|int ENA_pin, int ENB_pin, int IN1_pin, int IN2_pin, int IN3_pin, int IN4_pin| Creates an instance of the motor driver where A and B enables are externarly provided. Allows +12V power supply voltage

To create an instance of the motor driver use:
```
L298N motorDriver_ID (IN1_pin,IN2_pin,IN3_pin,IN4_pin);
```
```
L298N motorDriver_ID (ENA_pin,ENB_pin,IN1_pin,IN2_pin,IN3_pin,IN4_pin);
```
Remember, be carefull when connecting Vs, Vss and Gnd.

## METHODS
_Be aware, all methods included where designed to control a car with 2 motorized wheels._

### Getters
|Access Specifier|Return type|Method|Parameters|Description
|:---------|:-----|:--------|:----------|:------
|public|int|**get_ENA_pin**|none| Returns the last enable A pin value stored
|public|int|**get_ENB_pin**|none| Returns the last enable B pin value stored
|public|int|**get_IN1_pin**|none| Returns the last A input value stored linked to OUTPUT 1
|public|int|**get_IN2_pin**|none| Returns the last A input value stored linked to OUTPUT 2
|public|int|**get_IN3_pin**|none| Returns the last B input value stored linked to OUTPUT 3
|public|int|**get_IN4_pin**|none| Returns the last B input value stored linked to OUTPUT 4

### Setters
|Access Specifier|Return type|Method|Parameters|Description
|:---------|:-----|:--------|:----------|:------
|public|void|**set_ENA_pin**|int newpin| Rewrites the value of enable A pin stored
|public|void|**set_ENB_pin**|int newpin| Rewrites the value of enable B pin stored
|public|void|**set_ENA_PWM**|int dutycycle| Rewrites a PWM value between 0 and 255 to the enable A pin
|public|void|**set_ENB_PWM**|int dutycycle| Rewrites a PWM value between 0 and 255 to the enable B pin
|public|void|**set_ENS_PWM**|int dutycycle| Rewrites a PWM value between 0 and 255 to A and B enable pins
|public|void|**set_IN1_pin**|int newpin| Rewrites A input value stored linked to OUTPUT 1
|public|void|**set_IN2_pin**|int newpin| Rewrites A input value stored linked to OUTPUT 2
|public|void|**set_IN3_pin**|int newpin| Rewrites B input value stored linked to OUTPUT 3
|public|void|**set_IN4_pin**|int newpin| Rewrites B input value stored linked to OUTPUT 4

### Methods
|Access Specifier|Return type|Method|Parameters|Description
|:---------|:-----|:--------|:----------|:------
|public|void|**free_movement_A**|none| Free running motor stop (No currennt) controlled by enable A. Connected to L298N OUTPUT1 and OUTPUT2 pins
|public|void|**free_movement_B**|none| Free running motor stop (No currennt) controlled by enable B. Connected to L298N OUTPUT3 and OUTPUT4 pins
|public|void|**free_movement**|none| Free running motor stop (No currennt) controlled by enable A and B. Connected to L298N OUTPUT1, OUTPUT2, OUTPUT3, OUTPUT4 pins
|public|void|**fix_position_A**|none| Fixed position motor stop controlled by enable A. Connected to L298N OUTPUT1 and OUTPUT2 pins
|public|void|**fix_position_B**|none| Fixed position motor stop controlled by enable B. Connected to L298N OUTPUT3 and OUTPUT4 pins
|public|void|**fix_position**|none| Fixed position motor stop controlled by enable A and B. Connected to L298N OUTPUT1, OUTPUT2, OUTPUT3, OUTPUT4 pins
|public|void|**roll_clockwise_A**|int pwm| Moves the motor connected to L298N OUTPUT1 and OUTPUT2 pins clockwise given a pwm value between 0 and 255
|public|void|**roll_clockwise_B**|int pwm| Moves the motor connected to L298N OUTPUT3 and OUTPUT4 pins clockwise given a pwm value between 0 and 255
|public|void|**roll_counter_clockwise_A**|int pwm| Moves the motor connected to L298N OUTPUT1 and OUTPUT2 pins counterclockwise given a pwm value between 0 and 255
|public|void|**roll_counter_clockwise_B**|int pwm| Moves the motor connected to L298N OUTPUT3 and OUTPUT4 pins counterclockwise given a pwm value between 0 and 255
|public|void|**roll_clockwise**|int pwm| Moves motors A and B clockwise given a pwm value between 0 and 255
|public|void|**roll_counter_clockwise**|int pwm| Moves both motors counterclockwise given a pwm value between 0 and 255
|public|void|**rotate_left**|int pwm| Moves motor A clockwise and motor B counterclockwise given a pwm value between 0 and 255
|public|void|**rotate_right**|int pwm| Moves motor A counterclockwise and motor B clockwise given a pwm value between 0 and 255
|public|void|**motorTest**|none| Simple motor test routine that prints the motor driver states at the serial monitor
|public|String|**status_str**|none| Returns the state of the motor driver
|public|void|**to_String**|none| Prints the motor driver parameters at the serial monitor
