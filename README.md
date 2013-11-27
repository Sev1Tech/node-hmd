# node-hmd

This module serves to act as a common interface for communicating with a variety of head mounted displays (HMDs). While most applications should expect to access the HMD data as often as possible in a consistent manner both synchronous and asynchronous interfaces are provided in order to conform with Node.js community standards. It is the responsiblity of the end user to properly access the HMD positional data in the manner most appropriate for the application.

The current list of supported HMDs are as follows:

* [Oculus Rift](http://www.oculusvr.com/)
* Unresponsive default device
* Unresponsive testing mock device

## Getting Started

### Prerequisites

node-hmd statically compiles itself as a Node.js addon from C++ sources and utilizes the brilliant [gyp](https://code.google.com/p/gyp/) build tool via the [node-gpy](https://github.com/TooTallNate/node-gyp) module to enable simple cross-compiling of the module across a wide variety of platforms. As such certain systems will require proper configuration to enable installation of node-hmd.

#### Linux

In order to support certain HMD products the following libraries will need to be installed to ensure proper compilation of source files:

- [libudev-dev](http://cgit.freedesktop.org/systemd/systemd/tree/src/libudev)
- [libx11-dev](http://cgit.freedesktop.org/xorg/lib/libX11/)
- [libxinerama-dev](http://cgit.freedesktop.org/xorg/lib/libXinerama/)

#### OSX

By default OSX includes most components required to ensure proper compilation of source files. To properly account for certain nonstandardized packaging of frameworks it is recommended to ensure the following configuration and supporting modules:

- [Xcode](https://developer.apple.com/xcode/) and Xcode Command Line Tools
- 10.8 or higher

### Usage

Install the package or otherwise include the package in your project:

```
npm install node-hmd
```

```javascript
var hmd = require('node-hmd');
```

If desired query the library for the currently supported device tokens:

```javascript
var supportedDevices = hmd.getSupportedDevices();
```

Then construct a new HMD Manager object and go to town...

```javascript
var manager = hmd.createManager("default");

manager.getDeviceInfo(function(err, deviceInfo) {
	if(!err) {
		console.log(deviceInfo);
	}
	else {
		console.error("Unable to retrieve device information.");
	}
});

manager.getDeviceOrientation(function(err, deviceOrientation) {
	if(!err) {
		console.log(deviceOrientation);
	}
	else {
		console.error("Unable to retrieve device orientation.");
	}
});
```

## API

### hmd.getSupportedDevices()

Returns an array of tokens specifying the devices currently supported by the module.

Example:
```javascript
hmd.getSupportedDevices(); // -> ["default", "oculusrift"]
```

### hmd.createManager(`token`)

Returns a manager for the specified device type. If there is an error or the device is otherwise unsupported `undefined` will be returned.

* `token` - (String) The device type for which to create a manager. Should be one of the supported device tokens returned by getSupportedDevices().

Example:
```javascript
hmd.createManager("default"); // -> [object HMDManager]
hmd.createManager("unsupported"); // -> undefined
```

### hmd.HMDManager.getDeviceInfo(`callback`)

Returns relevant information about the HMD associated with the HMDManager at creation time. Note that the video signal for the HMD likely needs to be active for this function to properly execute.

* `callback` - (Function(error, deviceInfo)) Callback to execute once the device information has been retrieved from the HMD.

```javascript
var manager = hmd.createManager("default");
manager.getDeviceInfo(function(err, deviceInfo) {
	deviceInfo; // -> [object HMDDeviceInformation]
}); 
```

### hmd.HMDManager.getDeviceInfoSync()

Synchronous version of getDeviceInfo().

Example:
```javascript
var manager = hmd.createManager("default");
manager.getDeviceInfoSync(); // -> [object HMDDeviceInformation]
```

### hmd.HMDManager.getDeviceOrientation(`callback`)

Returns the most current orientation of the HMD associated with the HMDManager at creation time.

* `callback` - (Function(error, deviceInfo)) Callback to execute once the device information has been retrieved from the HMD.

```javascript
var manager = hmd.createManager("default");
manager.getDeviceOrientation(function(err, deviceOrientation) {
	deviceOrientation; // -> [object HMDDeviceOrientation]
}); 
```

### hmd.HMDManager.getDeviceOrientationSync()

Synchronous version of getDeviceOrientation().

Example:
```javascript
var manager = hmd.createManager("default");
manager.getDeviceOrientationSync(); // -> [object HMDDeviceOrientation]
```

## Release notes

### 0.1.0

* Initial Release

## License

(The MIT License)

Copyright (c) 2013 Geocent

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
