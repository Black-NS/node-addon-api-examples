'use strict'

const { runEcho } = require('bindings')('echo');
const AsyncWorkerCompletion = (err, result ) => {
    if (err) {
        console.log("Run Echo returned an Error : ", err);
    } else {
        console.log("Run Echo returend an Result : ", result, ".");
    }
}

const cmdSet = ["abcd", "quit", "error"];

cmdSet.forEach(cmd => runEcho(cmd, AsyncWorkerCompletion));
