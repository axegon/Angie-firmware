#include <Wire.h>

#define SCK     5
#define MISO    19
#define MOSI    27
#define SS      18
#define RST     23
#define DI0     26
#define BAND    868E6
#define MAX_MESSAGE_LENGTH 128
#define ENCRYPTION_KEY_ADDR 0

#define WIRE Wire