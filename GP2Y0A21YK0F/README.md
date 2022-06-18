# GP2Y0A21YK0F
Arduino IDE library for the SHARP INFRARED GP2Y0A21YK0F distance sensor
## ![image](https://user-images.githubusercontent.com/107767647/174457942-c281ed91-2fde-4ea0-a6b6-254e38888d1f.png)
[I'm an inline-style link with title]([https://www.google.com](https://media.digikey.com/pdf/Data%20Sheets/Sharp%20PDFs/GP2Y0A21YK0F.pdf) "GP2Y0A21YK0F's Datasheet")

## VARIABLES

|Access Specifier|Type|Name|Description
|:-----|:-----|:-----|:----------
|Protected|int|**SIGNAL_pin** |Arduino pin number where the sensor signal pin is connected
|Protected|float|**SAMP** |Sample value delivered by the integrated 12 bits ADC
|Protected|float|**VADC** |Voltage read by the ADC at SIGNAL_pin
|Protected|float|**DIST** |Distance between the sensor emiter-transmiter and the reflective surface

## CONSTRUCTORS

|Access Specifier|Name|Parameters|Description
|:-----|:-----|:-----|:----------
|public|**GP2Y0A21YK0F**|SIGNAL_pin|Creates a single instance of the GP2Y0A21YK0F sensor

To create an instance of the sensor use:
```
GP2Y0A21YK0F sensor_ID (PIN_NUMBER);
```
Remember, use an analog pin to get access to the arduino integrated 12 bits ADC

## METHODS

|Access Specifier|Return type|Method|Parameters|Description
|:---------|:-----|:--------|:----------|:------
|Protected|int|**get_SIGNAL_pin**|none| Returns the last signal pin stored
|Protected|float|**get_SAMP**|none| Returns the last sample value stored
|Protected|float|**get_VADC**|none| Returns the last ADC voltage value stored
|Protected|float|**get_DIST**|none| Returns the distance between the sensor emiter-transmiter and the reflective surface. Be aware that the distance is a linear aproximation of the sensor´s distance function
|Protected|float|**get_stable_DIST**|none| Returns the distance between the sensor emiter-transmiter and the reflective surface with a delay recommended by SHARP.Be aware that the distance is a linear aproximation of the sensor´s distance function
|Protected|void|**set_SIGNAL_pin**|int newpin| Rewrites the arduino pin number where the sensor signal pin is connected
|Protected|void|**set_SAMP**|int newpin| Rewrites the value of SAMP stored
|Protected|void|**set_VADC**|int newpin| Rewrites the value of VADC stored
|Protected|void|**set_DIST**|int newpin| Rewrites the value of DIST stored
|Protected|void|**GP2Y0A21YK0F_init_**|none| Initialize ports and sensor´s parameters
|Protected|void|**GP2Y0A21YK0F_test_**|none| Simple sensor test routine that prints the sensor´s parameters at the serial monitor
