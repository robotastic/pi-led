// C standard library
#include <cstdlib>
#include <ctime>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

#include "bit_array.hpp"
#include "font.h"

#define COMMAND 0x4
#define RD 0x6
#define WR 0x5
#define SYS_DIS 0x00
#define COMMON_8NMOS 0x20
#define COMMON_8PMOS 0x28
#define MASTER_MODE 0x14
#define INT_RC 0x18
#define SYS_EN 0x01
#define LED_ON 0x03
#define LED_OFF 0x02
#define PWM_CONTROL 0xA0
#define BLINK_ON 0x09
#define BLINK_OFF 0x08

class LedModule {

public:
LedModule();
LedModule(uint8_t chip, uint8_t width, uint8_t hieght);
~LedModule();
void clearMatrix();
void writeMatrix();
void printMatrix(unsigned char output[][129]);
void init();
void drawPixel(uint8_t x, uint8_t y, uint8_t color);
void setBrightness(uint8_t pwm);
void blink(int blinky);
void setChip(uint8_t c);
uint8_t scrollMatrixOnce(uint8_t shift);
private:
  uint8_t width, height, chip;
  uint8_t matrix[32]; // we are assuming the width is 32 and the height is 8
  void *reverseEndian(void *p, size_t size); 
void selectChip();
void sendCommand( uint8_t cmd);
};