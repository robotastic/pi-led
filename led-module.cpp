#include "led-module.h"
using namespace std;
void LedModule::setChip(uint8_t c){
	chip = c;
}

void * LedModule::reverseEndian(void *p, size_t size) {
  char *head = (char *)p;
  char *tail = head + size -1;

  for(; tail > head; --tail, ++head) {
    char temp = *head;
    *head = *tail;
    *tail = temp;
  }
  return p;
}

void LedModule::clearChip() {
  digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
}
void LedModule::selectChip()
{
  switch (chip) {
  case 0:
  digitalWrite(0,0);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
    break;

  case 1:
  digitalWrite(0,1);
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(3,1);
    break;

  case 2:
  digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,0);
  digitalWrite(3,1);
    break;

  case 3:
  digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,0);
    break;


  }
}

void LedModule::clearMatrix()
{
  memset(matrix,0,(width * height) /8);
}

void LedModule::drawPixel(uint8_t x, uint8_t y, uint8_t color) {
  if (y >= height) return;
  if (x >= width) return;


  if (color) {
    *(matrix + x) = *(matrix + x) | (1 << y); // find the bit in the byte that needs to be turned on;
  }else {
   *(matrix + x) = *(matrix + x) & ~(1 << y); // find the bit in the byte that needs to be turned on;
  }



}

uint8_t LedModule::scrollMatrixOnce(uint8_t shift) {
  int n;
  uint8_t temp;

  

for(n=width-1;n>-1;n--) {
	temp = matrix[n];
	matrix[n] = shift;
	shift = temp;
}
 return shift;
 }

void LedModule::printMatrix(unsigned char output[][129]) {
	uint8_t byte;
	for (int col=0; col < width; col++) {
		byte = matrix[col];
		for (int row=0; row < height; row++) {
			if ((byte &0x80) != 0) {
				output[row][col + (width * chip)] = 248;
			} else {
				output[row][col + (width * chip)] = ' ';
			}

			byte = byte << 1;
		}
	}
}

void LedModule::writeMatrix(){
  int size = width * height / 8;
  uint8_t *output = (uint8_t *) malloc(size+2);
  uint16_t data;
  uint8_t write;

  *output = 160;
  *(output+1) = 0;


  
  bitarray_copy(matrix, 0, width * height, (output+1), 2);
  selectChip();
  //sendCommand(LED_OFF);
  wiringPiSPIDataRW(0,output,size+1);
  clearChip();
  
  data = WR;
  data <<= 7;
  data |= 63; //last address on screen
  data <<= 4;
  write = (0x0f & *(matrix+31));
  data |= write;
  data <<= 2;

  reverseEndian(&data, sizeof(data));
  selectChip();
  wiringPiSPIDataRW(0, (uint8_t *) &data, 2);
  clearChip();
  //sendCommand(LED_ON);
  free(output);
}
void LedModule::sendCommand( uint8_t cmd) {
  uint16_t data=0;

  data = COMMAND;

  data <<= 8;
  data |= cmd;
  data <<= 5;
 

  reverseEndian(&data, sizeof(data));
  selectChip();
  wiringPiSPIDataRW(0, (uint8_t *) &data, 2);
  clearChip();
}

void LedModule::blink(int blinky) {
  if (blinky)
    sendCommand(BLINK_ON);
  else
    sendCommand(BLINK_OFF);
}

void LedModule::setBrightness(uint8_t pwm) {
  if (pwm > 15)
{
 pwm = 15;
 }
  
  sendCommand(PWM_CONTROL | pwm);
}
void LedModule::init(){
 sendCommand(SYS_EN);
 sendCommand(LED_ON);
 sendCommand(MASTER_MODE);
 sendCommand(INT_RC);
 sendCommand(COMMON_8NMOS);
 blink(0);
 setBrightness(15);
}
LedModule::LedModule() {
	chip = -1;
	width = 32;
	height = 8;
}
LedModule::~LedModule() {

}
LedModule::LedModule(uint8_t c, uint8_t w, uint8_t h) {
	chip = c;
	width = w;
	height = h;
}