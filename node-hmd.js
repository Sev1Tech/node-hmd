var SegfaultHandler = require('segfault-handler');
SegfaultHandler.registerHandler();

module.exports = require(__dirname + "/build/Release/hmd.node");
