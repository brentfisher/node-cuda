var mymodule = require('../build/Release/cudatest');

console.log("starting...");
console.log("---Module---");
console.dir(mymodule);
console.log("---End Module---");

console.log("\n");

mymodule.cudatest("Hello from cpp!", function(err, obj) {
  console.log("done");
  console.log(obj);
});;
