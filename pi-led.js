//https://stackoverflow.com/questions/14058990/inheriting-node-js-eventemitter-fails
var PiLedCpp = require('bindings')('PiLed');
const EventEmitter = require('events').EventEmitter

exports = module.exports = new EventEmitter();

exports.writeMessage = function(message, callback) {
  PiLedCpp.writeMessage(message, function(value){
    callback(value);
    exports.emit('end');
  })
};

exports.printMessage = function(message) {
  PiLedCpp.printMessage(message);
};

