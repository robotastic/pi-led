
var matrix = require('./pi-led');


console.log(matrix.PiLed);


//var matrix = new matrix.PiLed();




	matrix.PiLed.WriteMessage("Hello!", function(err, result) {

	matrix.PiLed.WriteMessage("Goodbye!", function(err, result) {});
});



