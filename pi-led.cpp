#include <node/node.h>
#include <node/node_object_wrap.h>

// C standard library
#include <cstdlib>
#include <ctime>
#include <errno.h>

#include <stdint.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;


extern "C"  {
#include "wiringPiSPI.h"
#include "wiringPi.h"
}

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
void LedModule::selectChip()
{
	
  switch (chip) {
  case 0:
 digitalWrite(0,0);
 digitalWrite(1,0);

    break;

  case 1:

 digitalWrite(0,0); 
digitalWrite(1,1);

    break;

  case 2:
 digitalWrite(0,1);
 digitalWrite(1,0);
    break;

  case 3:
 digitalWrite(0,1);
 digitalWrite(1,1);
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
  
  data = WR;
  data <<= 7;
  data |= 63; //last address on screen
  data <<= 4;
  write = (0x0f & *(matrix+31));
  data |= write;
  data <<= 2;

  reverseEndian(&data, sizeof(data));
  wiringPiSPIDataRW(0, (uint8_t *) &data, 2);
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

class LedMatrix {

public:
	LedMatrix(int modules);
	~LedMatrix();
	void writeMessage(char *message);
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
	uint8_t fontWidth, _width, _height;
};

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



namespace {

// We use a struct to store information about the asynchronous "work request".
struct Baton {
    // This handle holds the callback function we'll call after the work request
    // has been completed in a threadpool thread. It's persistent so that V8
    // doesn't garbage collect it away while our request waits to be processed.
    // This means that we'll have to dispose of it later ourselves.
    Persistent<Function> callback;
    Persistent<Object> emitter;
   
    //Persistent<String> display_message;
    char *display_message;

    // Tracking errors that happened in the worker function. You can use any
    // variables you want. E.g. in some cases, it might be useful to report
    // an error number.
    bool error;
    std::string error_message;


    // Custom data you can pass through.
    int32_t result;
};

static LedMatrix *matrix;

class PiLed: public ObjectWrap {
public:
  
  static Handle<Value> New(const Arguments& args);
  static Handle<Value> WriteMessage(const Arguments& args);
  static void AsyncWork(uv_work_t* req);
  static void AsyncAfter(uv_work_t* req);
};


Handle<Value> PiLed::New(const Arguments& args) {
  HandleScope scope;

  assert(args.IsConstructCall());
  PiLed* self = new PiLed();
  self->Wrap(args.This());

  matrix = new LedMatrix(4);

  return scope.Close(args.This());
}


// emits ping event
Handle<Value> PiLed::WriteMessage(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 2) {
        // No argument was passed. Throw an exception to alert the user to
        // incorrect usage. Alternatively, we could just use 0.
        return ThrowException(
            Exception::TypeError(String::New("Arguments: String to print, Callback Function"))
        );
    }

    if (!args[1]->IsFunction()) {
        return ThrowException(Exception::TypeError(
            String::New("Second argument must be a callback function")));
    }
     if (!args[0]->IsString()) {
        return ThrowException(Exception::TypeError(
            String::New("First argument must be a String")));
    }
    // There's no ToFunction(), use a Cast instead.
    Local<Function> callback = Local<Function>::Cast(args[1]);

    // The baton holds our custom status information for this asynchronous call,
    // like the callback function we want to call when returning to the main
    // thread and the status information.
    Baton* baton = new Baton();
    baton->error = false;
    baton->callback = Persistent<Function>::New(callback);
    baton->emitter = Persistent<Object>::New(args.This());

    //From: http://create.tpsitulsa.com/wiki/V8/Persistent_Handles
    //Persistent<Value> value = Persistent<Value>::New(String::New("Hello, World"));
    

    v8::String::AsciiValue string(args[0]);
        baton->display_message = (char *) malloc(string.length() + 1);
        strcpy(baton->display_message, *string);
  
    // This creates the work request struct.
    uv_work_t *req = new uv_work_t();
    req->data = baton;

    // Schedule our work request with libuv. Here you can specify the functions
    // that should be executed in the threadpool and back in the main thread
    // after the threadpool function completed.
    int status = uv_queue_work(uv_default_loop(), req, AsyncWork, AsyncAfter);
    assert(status == 0);

    return Undefined();
 

  return Undefined();
}

// This function is executed in another thread at some point after it has been
// scheduled. IT MUST NOT USE ANY V8 FUNCTIONALITY. Otherwise your extension
// will crash randomly and you'll have a lot of fun debugging.
// If you want to use parameters passed into the original call, you have to
// convert them to PODs or some other fancy method.
void PiLed::AsyncWork(uv_work_t* req) {
    Baton* baton = static_cast<Baton*>(req->data);



    // Do work in threadpool here.
    //LedMatrix *matrix = new LedMatrix(4);

  matrix->writeMessage(baton->display_message);

 
  baton->result = 42;

    // If the work we do fails, set baton->error_message to the error string
    // and baton->error to true.
}

// This function is executed in the main V8/JavaScript thread. That means it's
// safe to use V8 functions again. Don't forget the HandleScope!
void PiLed::AsyncAfter(uv_work_t* req) {
    HandleScope scope;
    Baton* baton = static_cast<Baton*>(req->data);

    if (baton->error) {
        Local<Value> err = Exception::Error(String::New(baton->error_message.c_str()));

        // Prepare the parameters for the callback function.
        const unsigned argc = 1;
        Local<Value> argv[argc] = { err };

        // Wrap the callback function call in a TryCatch so that we can call
        // node's FatalException afterwards. This makes it possible to catch
        // the exception from JavaScript land using the
        // process.on('uncaughtException') event.
        TryCatch try_catch;
        baton->callback->Call(Context::GetCurrent()->Global(), argc, argv);
        if (try_catch.HasCaught()) {
            node::FatalException(try_catch);
        }
    } else {
        // In case the operation succeeded, convention is to pass null as the
        // first argument before the result arguments.
        // In case you produced more complex data, this is the place to convert
        // your plain C++ data structures into JavaScript/V8 data structures.


    Local<Value> event[2] = {
    String::New("FinishedWrite"), // event name
    String::New("success")  // argument
    };

    MakeCallback(baton->emitter, "emit", 2, event);
   

       const unsigned argc = 2;
        Local<Value> argv[argc] = {
            Local<Value>::New(Null()),
            Local<Value>::New(Integer::New(baton->result))
        };

        // Wrap the callback function call in a TryCatch so that we can call
        // node's FatalException afterwards. This makes it possible to catch
        // the exception from JavaScript land using the
        // process.on('uncaughtException') event.
        TryCatch try_catch;
        baton->callback->Call(Context::GetCurrent()->Global(), argc, argv);
        if (try_catch.HasCaught()) {
            node::FatalException(try_catch);
        }
    }
    

    // The callback is a permanent handle, so we have to dispose of it manually.
    baton->callback.Dispose();
    baton->emitter.Dispose();

    //baton->display_message.Dispose();
    free(baton->display_message);

    // We also created the baton and the work_req struct with new, so we have to
    // manually delete both.
    delete baton;
    delete req;
}





void RegisterModule(Handle<Object> target) {
   HandleScope scope;

  Local<FunctionTemplate> t = FunctionTemplate::New(PiLed::New);
  t->InstanceTemplate()->SetInternalFieldCount(1);
  t->SetClassName(String::New("PiLed"));
  NODE_SET_PROTOTYPE_METHOD(t, "WriteMessage", PiLed::WriteMessage);

  target->Set(String::NewSymbol("PiLed"), t->GetFunction());

}

NODE_MODULE(PiLed, RegisterModule);
}





