
var Matrix = require('./pi-led').PiLed;





var matrix = new Matrix();



	matrix.WriteMessage("Hello!", function(err, result) {

	matrix.WriteMessage("Goodbye!", function(err, result) {});
});



