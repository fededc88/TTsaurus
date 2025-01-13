
#include "serial.h"

#if defined (__AVR__) || (__avr__)

#include <Arduino.h>

#endif

#ifdef DEBUG
char serial_tx_buff[SERIAL_TX_LENGTH];
#endif

void serial_init(void)
{
    Serial.begin(9600); while(!Serial){;} /* Wait serial connection TODO: add a loop break */
}

size_t serial_read(char *s1, size_t len)
{
    size_t cmd_len = 0;

    if(Serial.available() > 0)
    {
        cmd_len = Serial.readBytesUntil('\n', s1, len);
        s1[cmd_len++] = '\0';
    }

    return cmd_len;
}

void serial_println(char *s1)
{
    Serial.println(s1);
}

// 
// End of file.
//
