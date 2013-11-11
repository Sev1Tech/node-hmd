var hmd = require("../.."),
	express = require("express");

var app = express();
var manager = hmd.createManager("default");

app.get("/supported", function(req, res) {
	res.json(hmd.getSupportedDevices());
});

app.get("/info", function(req, res) {
	manager.getDeviceInfo(function(err, deviceInfo) {
		res.json(deviceInfo);
	});
});

app.get("/orientation", function(req, res) {
	manager.getDeviceOrientation(function(err, deviceOrientation) {
		res.json(deviceOrientation);
	});
});

app.listen(3000);
