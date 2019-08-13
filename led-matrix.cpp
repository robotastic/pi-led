#include "led-module.h"
#include "led-matrix.h"

LedMatrix::LedMatrix(int m) {
	int i;
	moduleNum = m;
	_width = 32*moduleNum;
	_height = 8;
modules = new LedModule[m];
	fontWidth = 8;


if (wiringPiSPISetup(0, 256000) <0)
  cout <<  "SPI Setup Failed: " <<  strerror(errno) << endl;

 if (wiringPiSetup() == -1)
   exit(1);
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);


for (i=0; i < m; i++) {
	modules[i].setChip(i);
	modules[i].init();
}

}

LedMatrix::~LedMatrix() {
	delete []modules;
}

void LedMatrix::drawPixel(uint8_t x, uint8_t y, uint8_t color) {
  if (y >= _height) return;
  if (x >= _width) return;

  uint8_t m;
  // figure out which matrix controller it is
  m = x / 32;
	x %= 32;
	modules[m].drawPixel(x, y, color);
 }

void LedMatrix::writeMatrix() {
	
 for (int i=0; i < moduleNum; i++) {
 	modules[i].writeMatrix();
 }
 	//printMatrix();
}

void LedMatrix::printMatrix() {
	unsigned char output[8][128+1];

	for (int i=0; i < moduleNum; i++) {
		modules[i].printMatrix(output);
	}


	for (int i=0; i < _height; i++ ){
		output[i][_width] = '\0';
		//cout << strlen(output[i]) << endl;
		cout << output[i] << endl;
		//printf("%s \n",output[i]);
	}
}

void LedMatrix::clearMatrix() {
	
 for (int i=0; i < moduleNum; i++) {
 	modules[i].clearMatrix();
 }
}

void LedMatrix::scrollMatrixOnce(int offset) {
  int n;

if (offset >= fontWidth)
	return;

uint8_t temp = offscreen[offset];

for(n=moduleNum;n>0;n--) {
temp = modules[n-1].scrollMatrixOnce(temp); // n-1 since the matrix is 0 based
}
 

  writeMatrix();
  usleep(12500);
}

void LedMatrix::drawChar(char c, int offset, uint8_t *buf) {
  int row, col,x,y;
  memset(buf,0,8);
     for (row=0; row<8; row++) {
	uint8_t z = fontData[(int8_t) c][row];
	for(col=0; col<8; col++) {
	  x = offset * fontWidth + col;
	  y = 8 - row;

	  if ((z &0x80) != 0) {
	    *(buf + x) = *(buf + x) | (1 << y); // find the bit in the byte that needs to be turned on;
	  }else {
	    *(buf + x) = *(buf + x) & ~(1 << y); // find the bit in the byte that needs to be turned on;
	  }
	
	  z = z <<1;
	}
     }
}

void LedMatrix::writeMessage(char *message) {
  int display_len = 16;//width*displays/font_width;
  int i, pix;
  int msg_len = strlen(message);


for (i=0; i < display_len; i++) {
	modules[i].init();
} 

 clearMatrix();

  for (i=0; i < msg_len; i++ ) {

      char c = message[i];
      drawChar(c, 0, offscreen);

      for (pix = 0; pix < fontWidth; pix++){
	scrollMatrixOnce(pix);
      }
  }
  
  for (i=0; i < display_len; i++ ) {

      char c = ' ';
      drawChar(c, 0, offscreen);

      for (pix = 0; pix < fontWidth; pix++){
  scrollMatrixOnce(pix);
      }
  }

}

