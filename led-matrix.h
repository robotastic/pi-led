#ifndef LED_MATRIX_H_
#define LED_MATRIX_H_
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
#include "led-module.h"
#include <math.h> 

extern "C"  {
#include "wiringPiSPI.h"
#include "wiringPi.h"
}

class LedMatrix {

public:
	LedMatrix(int modules);
	~LedMatrix();
	void writeMessage(char const *message);
	void printMessage(char const *message);
	void drawPixel(uint8_t x, uint8_t y, uint8_t color);
	void writeMatrix(); 
	void printMatrix();
	void clearMatrix();
private:
	void drawChar(char c, int offset, uint8_t *buf);
	void scrollMatrixOnce(int offset);
	
	LedModule *modules;
	uint8_t offscreen[8]; // font width;
	int moduleNum;
	int matrixFd ;
	uint8_t fontWidth, _width, _height;
};
#endif