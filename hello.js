
var matrix = require('./pi-led');


console.log(matrix.PiLed);


//var matrix = new matrix.PiLed();




	matrix.PiLed.writeMessage("Hello!", function(err, result) {

	matrix.PiLed.writeMessage("Goodbye!", function(err, result) {});
});



