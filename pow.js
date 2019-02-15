var addon = require('./build/Release/pow.node');

// test
let str = "";
for (let i = 0; i < 500; i++) {
    let r1 = Math.floor(Math.random() * 10);
    let r2 = Math.floor(Math.random() * 10);
    str += addon.pow(r1, r2);
}
console.log(str);