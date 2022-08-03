
// 'use strict'
// var addon = require('bindings')('./build/Release/hello.node');
// const EventEmitter = require('events').EventEmitter
// function helloworld(){
//     console.log("hello world from js");
// }
// function AddTwo(num) {
//     return num + 2;
// }
// const emitter = new EventEmitter()

// emitter.on('start', () => {
//     console.log('### START ...')
// })
// emitter.on('data', (evt) => {
//     console.log(evt+"asd");
// })

// emitter.on('end', () => {
//     console.log('### END ###')
// })

// // addon.callEmit(emitter.emit.bind(emitter))
// function testingfromjs(){
//     return addon.pointer();
// }

//This class is a wrapper for `binding.HID` class
function hello() {
    return "Thirdwayv From js called by Our Keyring";
}
exports.hello = hello;
// console.log(addon.pointer());