
var PiLed = require('./pi-led');


//var piLed = new PiLed()
//console.log(piLed);

//var matrix = new matrix.PiLed();

PiLed.on('end', () => {
    //console.log('### END ###')
})


	PiLed.writeMessage("Hello!", function(err, result) {
        var message = "09:26PM 076" + String.fromCharCode(127) +" 90%";
        PiLed.printMessage(message)
        PiLed.printMessage("0123456789012345")
        
        //console.log("call back")
});





