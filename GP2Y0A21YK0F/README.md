# GP2Y0A21YK0F
Arduino IDE library for the SHARP INFRARED GP2Y0A21YK0F distance sensor

## CONSTRUCTORS
To create an instance of the sensor use:
```
GP2Y0A21YK0F sensor_ID (PIN_NUMBER);
```
Remeber tu use an analog pin to get access to the arduino integrated 12 bits ADC
## METHODS

|Return type |Method | Params  | Description
|:----- | :----- | :---------- | :------
|int|**get_SIGNAL_pin** |   none | Returns the pin number where the sensor is connected
|float|**get_SAMP** |  none | Returns the sample value deliverd by the integrated 12 bits ADC
|float|**get_VADC** |     none  | Returns the voltage equivalent of the sample delivered by the integrated 12 bits ADC
|float|**get_DIST** | none  | Aproximates the distance between the sensor emiter and transmiter to the reflective surface. Be aware that the distance is a linear aproximation of the distance function
|float|**get_stable_DIST** | none  | Aproximates the distance between the sensor emiter and transmiter to the reflective surface with a delay recommended by SHARP
|void|**set_SIGNAL_pin** |  int newpin | Rewrites the pin number where the sensor is connected
|void|**set_SAMP** |     int newpin  | Rewrites the value of SAMP stored
|void|**set_VADC** | int newpin  | Rewrites the value of VADC stored
|void|**set_DIST** | int newpin  | Rewrites the value of DIST stored
|void|**GP2Y0A21YK0F_init_** | none  | Initialize ports and sensor parameters
|void|**GP2Y0A21YK0F_test_** | none  | Simple sesnor test routine that prints the sensor´s parameters at the serial monitor
