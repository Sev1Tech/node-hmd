# node-hmd

[![npm version](https://badge.fury.io/js/node-hmd.svg)](http://badge.fury.io/js/node-hmd)
[![build status](https://travis-ci.org/Geocent/node-hmd.png?branch=master)](https://travis-ci.org/Geocent/node-hmd)

This module serves to act as a common interface for communicating with a variety of head mounted displays (HMDs). While most applications should expect to access the HMD data as often as possible in a consistent manner both synchronous and asynchronous interfaces are provided in order to conform with Node.js community standards. It is the responsibility of the end user to properly access the HMD positional data in the manner most appropriate for the application.

The current list of supported HMDs are as follows:

* [Oculus Rift](http://www.oculusvr.com/) DK1 and DK2
* Unresponsive default device
* Unresponsive testing mock device

## Getting Started

### Prerequisites

node-hmd statically compiles itself as a Node.js addon from C++ sources and utilizes the brilliant [gyp](https://code.google.com/p/gyp/) build tool via the [node-gpy](https://github.com/TooTallNate/node-gyp) module to enable simple cross-compiling of the module across a wide variety of platforms. As such certain systems will require proper configuration to enable installation of node-hmd.

#### Linux

In order to support certain HMD products the following libraries will need to be installed to ensure proper compilation of source files:

- freeglut3-dev
- mesa-common-dev
- libudev-dev
- libxext-dev
- libxinerama-dev
- libxrandr-dev
- libxxf86vm-dev

Additionally rules will need to be added to udev to enable raw HID access to the Oculus Rift device.

LibOVR includes a script to automatically install these dependencies and udev rules and is included for execution at `/src/platform/linux/ConfigurePermissionsAndPackages.sh`.

##### Ubuntu 13

LibOVR does not currently support Ubuntu 13 out of the box and execution may result in an error such as `error while loading shared libraries: libudev.so.0`.

To resolve this issue from the command line execute:

```
cd /lib/x86_64-linux-gnu/
sudo ln -sf libudev.so.1 libudev.so.0
```

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

Returns a manager for the specified device type. If there is an error or the device is otherwise unsupported an `Error` will be thrown.

* `token` - (String) The device type for which to create a manager. Should be one of the supported device tokens returned by getSupportedDevices().

Example:
```javascript
hmd.createManager("default"); // -> [object HMDManager]
hmd.createManager("unsupported"); // -> "Error: Invalid device creation token."
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
### hmd.HMDManager.getDevicePosition(`callback`)

Returns the most current position of the HMD associated with the HMDManager at creation time.

* `callback` - (Function(error, devicePosition)) Callback to execute once the device information has been retrieved from the HMD.

```javascript
var manager = hmd.createManager("default");
manager.getDevicePosition(function(err, devicePosition) {
	devicePosition; // -> [object HMDDevicePosition]
});
```

### hmd.HMDManager.getDevicePositionSync()

Synchronous version of getDevicePosition().

Example:
```javascript
var manager = hmd.createManager("default");
manager.getDevicePositionSync(); // -> [object HMDDevicePosition]
```

### hmd.HMDManager.getDeviceQuat(`callback`)

Returns the most current quaternion of the HMD associated with the HMDManager at creation time.

* `callback` - (Function(error, deviceInfo)) Callback to execute once the device information has been retrieved from the HMD.

```javascript
var manager = hmd.createManager("default");
manager.getDeviceQuat(function(err, deviceQuat) {
	deviceQuat; // -> [object HMDDeviceQuat]
});
```

### hmd.HMDManager.getDeviceQuatSync()

Synchronous version of getDeviceQuat().

Example:
```javascript
var manager = hmd.createManager("default");
manager.getDeviceQuatSync(); // -> [object HMDDeviceQuat]
```

## Release notes

### 0.2.1
* Fully tested with Oculus Development Kit 1 and 2 (DK1, DK2) on Mac, Window, and Linux systems.
* Added support for [io.js](https://iojs.org/en/index.html) and NodeJS versions 0.11 and 0.12.
* Dropped support for NodeJS 0.10.
* Integrated project with Travis CI build support.

### 0.2.0
* Expanded platform support for with Mac, Windows, and Linux systems.
* Updated Mac and Windows platform Oculus SDK to version 0.4.2 Beta.
* Updated Linux platform Oculus SDK to version 0.3.2 Preview 2.
* Addition of getDeviceQuat/getDeviceQuatSync.
* Addition of getDevicePosition/getDevicePositionSync.
* Implemented [NAN](https://github.com/rvagg/nan) signatures for better Node.js version support.
* [cpplint](http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py) source code compliance.
* Fully tested with Oculus Development Kit 1 (DK1) on Mac, Window, and Linux systems.

### 0.1.2
* Updated Oculus SDK to version 0.2.5c
* Removed Travis CI build support

### 0.1.1

* Updated project description
* Integrated project with Travis CI build support

### 0.1.0

* Initial Release

## License

(The MIT License)

Copyright (c) 2013-2015 Geocent

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
