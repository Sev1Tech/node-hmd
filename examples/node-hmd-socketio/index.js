var hmd = require("../.."),
	express = require("express"),
	http = require("http"),
	io = require("socket.io");

// Create HMD manager object
var manager = hmd.createManager("default");

// Instantiate express server
var app = express();
app.set('port', process.env.PORT || 3000);

// Set up request routing
app.get("/", function (req, res) {
	res.sendfile(__dirname + "/index.html");
});

app.get("/supported", function (req, res) {
	res.json(hmd.getSupportedDevices());
});

app.get("/info", function (req, res) {
	manager.getDeviceInfo(function(err, deviceInfo) {
		res.json(deviceInfo);
	});
});

app.get("/orientation", function (req, res) {
	manager.getDeviceOrientation(function(err, deviceOrientation) {
		res.json(deviceOrientation);
	});
});

// Launch express server
var server = http.createServer(app).listen(app.get("port"), function () {
	console.log("Express server listening on port " + app.get("port"));
});

// Attack socket.io listener to the server
var socket = io.listen(server);

// On socket connection set up event emitters to automatically push the HMD orientation data
socket.sockets.on("connection", function (socket) {
	var orientation = setInterval(function () {
		manager.getDeviceOrientation(function(err, deviceOrientation) {
			socket.emit("orientation", deviceOrientation);
		});
	}, 1000);

	socket.on("disconnect", function () {
		clearInterval(orientation);
	});
});

