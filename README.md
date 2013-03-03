# Pi-Led

This is a Node.js module that lets you write messages on HT1632 LED Message Boards from your Raspberry Pi, using its built in SPI Bus. 

It was designed to work with the Raspberry Pi, but it should be easily ported to other platforms that provide an SPI Bus. I use 2 GPIOs to increase the number of Chip Select lines. The whole hardware setup is described here.

## How to Install

```bash
npm install pi-led
```

## How to Use

First, require `pi-led`:

```js
var Led = require('pi-led').PiLed;
```

Then create an instance of it:

```js
var led = new Led();
```

Now you can write messages:

```js
led.WriteMessage("Hello World!", function(err, result) {
	// This Callback happens when a message has finished scrolling
});
```

An event also gets emitted after a message has finished scrolling:

```js
led.on('FinishedWrite', function(s) {
	// Queue up another message to print here
});
```

## How to setup the hardware

I put together a long post on how I wired the boards together here. By default, the module is configured for 4 LED Modules, each with 32 LEDs across and 8 LEDs high.

To change this, go muck around in pi-led.cpp and then rebuild the module by going into the module directory and typing:

```
npm build .
```

