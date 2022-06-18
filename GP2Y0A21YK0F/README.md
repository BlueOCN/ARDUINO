# GP2Y0A21YK0F
Arduino IDE library for the SHARP INFRARED GP2Y0A21YK0F distance sensor

## VARIABLES

|Access Specifier|Type|Name|Description
|:-----|:-----|:-----|:----------
|Protected|int|**SIGNAL_pin** |Pin number where the sensor is connected
|Protected|float|**SAMP** |Sample value deliverd by the integrated 12 bits ADC
|Protected|float|**VADC** |Voltage read by the ADC at SIGNAL_pin
|Protected|float|**DIST** |Distance between the sensor emiter-transmiter and the reflective surface

## CONSTRUCTORS
To create an instance of the sensor use:
```
GP2Y0A21YK0F sensor_ID (PIN_NUMBER);
```
Remeber tu use an analog pin to get access to the arduino integrated 12 bits ADC
## METHODS

|Access Specifier|Return type|Method|Parameters|Description
|:---------|:-----|:--------|:----------|:------
|Protected|int|**get_SIGNAL_pin** |   none | Returns the pin number where the sensor is connected
|Protected|float|**get_SAMP** |  none | Returns the sample value deliverd by the integrated 12 bits ADC
|Protected|float|**get_VADC** |     none  | Returns the voltage equivalent of the sample delivered by the integrated 12 bits ADC
|Protected|float|**get_DIST** | none  | Aproximates the distance between the sensor emiter and transmiter to the reflective surface. Be aware that the distance is a linear aproximation of the distance function
|Protected|float|**get_stable_DIST** | none  | Aproximates the distance between the sensor emiter and transmiter to the reflective surface with a delay recommended by SHARP
|Protected|void|**set_SIGNAL_pin** |  int newpin | Rewrites the pin number where the sensor is connected
|Protected|void|**set_SAMP** |     int newpin  | Rewrites the value of SAMP stored
|Protected|void|**set_VADC** | int newpin  | Rewrites the value of VADC stored
|Protected|void|**set_DIST** | int newpin  | Rewrites the value of DIST stored
|Protected|void|**GP2Y0A21YK0F_init_** | none  | Initialize ports and sensor parameters
|Protected|void|**GP2Y0A21YK0F_test_** | none  | Simple sesnor test routine that prints the sensor´s parameters at the serial monitor
