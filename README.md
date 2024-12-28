# TTsaurus
Dynamometer for small RC motors.

## DEBUG
For debuging messages, DEBUG macro should be defined. Check _SERIAL_DEBUG @ [serial.h](serial.h)

On arduino-cli, add the DEBUG flag with --build-property as follow
```C
arduino-cli compile -b arduino:avr:uno --build-property "build.extra_flags=\"-DDEBUG=\"" --clean -v
```

