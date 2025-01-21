# TTsaurus
Dynamometer for small RC motors.<Br>

## HARDWARE

The following is the current target hardware for this project.<Br>

1. [Microcontroler - Adafruit METRO 328 Fully Assembled - Arduino IDE compatible - ATmega328](https://www.adafruit.com/product/50)<Br>
2. [ESC - Hobbywing Quicrun 1060 1/10 Brushed ESC w/T-Plug]( https://www.amainhobbies.com/hobbywing-quicrun-1060-1-10-brushed-esc-hwa30120203/p1533864?gad_source=1&gclid=CjwKCAiA1eO7BhATEiwAm0Ee-KpRxFM2_5_Ww6sVfiFjOhrzGNWaQoS78-MS9VYoMyEYTMNNGlwCSxoCoTQQAvD_BwE)<Br>
3. [Rotary Position Sensor - AS5040](https://www.digikey.com/en/products/detail/ams-osram-usa-inc/AS5040-ADAPTERBOARD/2339617?_gl=1*6t009t*_up*MQ..*_gs*MQ..&gclid=CjwKCAiA1eO7BhATEiwAm0Ee-HnGToGmb_i_UwndvSzrPG9VV5JNKUp1R7ztrRSc0J1y3mgx4piHbhoClB8QAvD_BwE&gclsrc=aw.ds)<Br>

## DEBUG
For debuging messages, DEBUG macro should be defined. Check _SERIAL_DEBUG @ [serial.h](serial.h)<Br>

On arduino-cli, add the DEBUG flag with --build-property as follow
```C
arduino-cli compile -b arduino:avr:uno --build-property "build.extra_flags=\"-DDEBUG=\"" --clean -v
```

