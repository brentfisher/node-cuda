var mymodule = require('../build/Release/cudatest');

console.log("starting...");
console.log("---Module---");
console.dir(mymodule);
console.log("---End Module---");

console.log(mymodule.cudatest("Hello from cpp!"));
