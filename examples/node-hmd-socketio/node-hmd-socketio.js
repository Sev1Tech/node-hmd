#!/usr/bin/env node

'use strict';

var hmd = require("../.."),
	express = require("express"),
	http = require("http"),
	io = require("socket.io");

var argv = require('optimist')
	.usage('Usage: $0 -d [driver]')
    .default('d', 'default')
    .alias('d', 'driver')
    .describe('d', 'Driver to load');

argv.showHelp(console.info);

// Create HMD manager object
console.info("Attempting to load node-hmd driver: " + argv.argv.driver);
var manager = hmd.createManager(argv.argv.driver);
if(typeof(manager) === "undefined") {
	console.error("Unable to load driver: " + argv.argv.driver);
	process.exit(1);
}

// Instantiate express server
var app = express();
app.set('port', process.env.PORT || 3000);

// Set up request routing
app.get("/", function (req, res) {
	res.sendfile(__dirname + "/index.html");
});

// Launch express server
var server = http.createServer(app).listen(app.get("port"), function () {
	console.log("Express server listening on port " + app.get("port"));
});

// Attach socket.io listener to the server
var socket = io.listen(server);

// On socket connection set up event emitters to automatically push the HMD orientation data
socket.sockets.on("connection", function (socket) {

	function emitOrientation() {
		var deviceOrientation = manager.getDeviceOrientationSync();
		var devicePosition = manager.getDevicePositionSync();

		socket.emit("update", {
			orientation: deviceOrientation,
			position: devicePosition
		});

	}

	var orientation = setInterval(emitOrientation, 1000);

	socket.on("adjust", function(data) {
		clearInterval(orientation);
		orientation = setInterval(emitOrientation, data);
	});

	socket.on("disconnect", function () {
		clearInterval(orientation);
	});
});
