#ifndef __SERIAL_H__
#define __SERIAL_H__

#define SERIAL_TX_LENGTH 120

#include <stddef.h>

void serial_init(void);

size_t serial_read(char *s1, size_t len);

void serial_println(char *s1);

#ifdef DEBUG
extern char serial_tx_buff[SERIAL_TX_LENGTH];
//#define _SERIAL_DEBUG(fmt, args...) sprintf(serial_tx_buff,"%s:%s:%d: "fmt,__FILE__,__FILE__ , __LINE__, ##args);Serial.print(serial_tx_buff);
#define _SERIAL_DEBUG(fmt, args...) sprintf(serial_tx_buff,"%s: %s(): %d: " fmt, __FILE__, __FUNCTION__, __LINE__, ##args);serial_println(serial_tx_buff);
#else
#define _SERIAL_DEBUG(fmt, args...)
#endif

#endif

// 
// End of file.
//
