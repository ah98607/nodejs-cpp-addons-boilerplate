let addon = require('./build/Release/function_definition.node');

// test function call with passing aruguments and callback function
addon.generateMessage(123, function(msg) {
    console.log(msg);
});