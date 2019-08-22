
var PiLed = require('./pi-led');


//var piLed = new PiLed()
//console.log(piLed);

//var matrix = new matrix.PiLed();

PiLed.on('end', () => {
    //console.log('### END ###')
})


	PiLed.writeMessage("Hello!", function(err, result) {
        //console.log("call back")
});

PiLed.printMessage("09:26PM 076F 90%")



