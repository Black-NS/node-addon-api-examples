'use strict'

const { Hello, outerMethod } = require('bindings')('hello_class');

console.log(outerMethod());

const Obj = new Hello();
console.log(Obj.innerMethod());