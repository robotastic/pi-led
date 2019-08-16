
var matrix = require('./pi-led');


console.log(matrix.PiLed);


//var matrix = new matrix.PiLed();




	matrix.PiLed.writeMessage("Hello!", function(err, result) {

	matrix.PiLed.writeMessage("Goodbye!", function(err, result) {});
});


matrix.PiLed.on('FinishedWrite', function(s) {
    console.log("Got This");
});


