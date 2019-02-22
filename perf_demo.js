let addon = require('./build/Release/function_definition.node');

// test multiplication perf
let num_loops = 99999999;
console.log("Number of loops: " + num_loops);
let a = 123456;
let b = 654321;

// c++
let t1 = new Date();
addon.multiplicationPerf(a, b, num_loops); // ignore the output
let t2 = new Date();
let cpptime = t2.getTime() - t1.getTime();
console.log(cpptime + " ms (C++)");

// javascript
let t3 = new Date();
for (let i = 0; i < num_loops; i++) {
    let product = a * b; // ignore the output
}
let t4 = new Date();
let jstime = t4.getTime() - t3.getTime();
console.log(jstime + " ms (JavaScript)");

// comparison
let ratio = cpptime / jstime;