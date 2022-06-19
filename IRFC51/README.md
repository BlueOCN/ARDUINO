# IRFC51
Arduino IDE library for the generic infrared IRFC51 proximity sensor
## ![image](https://user-images.githubusercontent.com/107767647/174498934-31280c70-772b-4f96-8912-7153c949c6f0.png)
[Click here to access IRFC51 datasheet!](http://www.dmf.unisalento.it/~denunzio/allow_listing/ARDUINO/FC51.pdf "IRFC51's Description")

## VARIABLES

|Access Specifier|Type|Name|Description
|:-----|:-----|:-----|:----------
|Protected|int|**SIGNAL_pin**|Arduino pin number where the sensor signal pin is connected
|Protected|int|**STATE**|Sensor reading control flag 0:OFF 1:ON
|Protected|int|**OBJECT**|Object detected flag 0:None 1:Detected

## CONSTRUCTORS

|Access Specifier|Name|Parameters|Description
|:-----|:-----|:-----|:----------
|public|**IRFC51**|SIGNAL_pin|Creates a single instance of the IRFC51 sensor

To create an instance of the sensor use:
```
IRFC51 sensor_ID (PIN_NUMBER);
```

## METHODS

|Access Specifier|Return type|Method|Parameters|Description
|:---------|:-----|:--------|:----------|:------
|public|int|**get_signal_pin**|none| Returns the last signal pin stored
|public|int|**get_state**|none| Returns the last state stored flag
|public|int|**get_object**|none| Returns the last object detection flag
|public|void|**set_signal_pin**|int newpin| Rewrites the arduino pin number where the sensor signal pin is connected
|public|void|**IRFC51_init_**|none| Initialize ports and sensor´s parameters
|public|void|**switch_STATE**|none| Rewrites and switches the state value
|public|void|**switch_STATE_up**|none| Rewrites the state value as 1
|public|void|**switch_STATE_down**|none| Rewrites the state value as 0
|public|void|**detect_object**|none| Reads the sensor signal pin and rewrites OBJECT variable if founds one
|public|void|**toString**|none| Prints into the serial monitor the sensor data
|public|void|**IRFC51_Test**|none| Simple sensor test routine that prints the sensor´s parameters at the serial monitor
