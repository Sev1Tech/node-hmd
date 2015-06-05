'use strict';

var	assert = require('assert'),
	hmd = require('../node-hmd');

function floatCompareEquality(a, b) {
	return Math.abs(a - b) < 0.000001;
}

describe('node-hmd tests.', function() {
	it('#getSupported', function() {
		var supportedDevices = hmd.getSupportedDevices();
		assert.ok(supportedDevices.length > 0);
		assert.ok(supportedDevices.indexOf('default') > -1);
		assert.ok(supportedDevices.indexOf('oculusrift') > -1);
	});
});

describe('node-hmd manager tests.', function() {
	var instance = hmd.createManager('test');

	describe('#createManager', function() {
		it('node-hmd createManager failure test.', function() {
			assert.throws(function() { hmd.createManager(); });
			assert.throws(function() { hmd.createManager('doesnotexist'); });
		});
	});

	describe('#createManager', function() {
		it('node-hmd createManager test.', function() {
			assert.ok(instance);
		});
	});

	describe('#getDeviceInfo', function() {
		it('getDeviceInfo sanity test.', function(done) {
			instance.getDeviceInfo(function(err, deviceInfo) {
				assert.ok(deviceInfo);

				assert.equal(deviceInfo.hResolution, 800);
				assert.equal(deviceInfo.vResolution, 600);
				assert.ok(floatCompareEquality(deviceInfo.hScreenSize, 0.8));
				assert.ok(floatCompareEquality(deviceInfo.vScreenSize, 0.64));
				assert.equal(deviceInfo.vScreenCenter, 300);
				assert.ok(floatCompareEquality(deviceInfo.eyetoScreenDistance, 0.01));
				assert.ok(floatCompareEquality(deviceInfo.lensSeparationDistance, 0.02));
				assert.ok(floatCompareEquality(deviceInfo.interpuillaryDistance, 0.025));
				assert.ok(floatCompareEquality(deviceInfo.distortionK[0], 1.1));
				assert.ok(floatCompareEquality(deviceInfo.distortionK[1], 2.2));
				assert.ok(floatCompareEquality(deviceInfo.distortionK[2], 3.3));
				assert.ok(floatCompareEquality(deviceInfo.distortionK[3], 4.4));
				assert.equal(deviceInfo.desktopX, 1920);
				assert.equal(deviceInfo.desktopY, 1080);
				assert.equal(deviceInfo.displayDeviceName, 'node-hmd test device');
				assert.equal(deviceInfo.displayId, 1234567890);
				assert.equal(deviceInfo.productName, 'Test Device');
				assert.equal(deviceInfo.manufacturer, 'Geocent LLC');
				assert.equal(deviceInfo.version, 5);
				assert.equal(deviceInfo.mixedData[0], 42);
				assert.equal(deviceInfo.mixedData[1], 'test token');

				done();
			});
		});
	});

	describe('#getDeviceInfoSync', function() {

		var deviceInfo = instance.getDeviceInfoSync();

		it('getDeviceInfoSync sanity test.', function() {
			assert.ok(deviceInfo);
		});

		it('Default getDeviceInfo test.', function() {
			assert.equal(deviceInfo.hResolution, 800);
			assert.equal(deviceInfo.vResolution, 600);
			assert.ok(floatCompareEquality(deviceInfo.hScreenSize, 0.8));
			assert.ok(floatCompareEquality(deviceInfo.vScreenSize, 0.64));
			assert.equal(deviceInfo.vScreenCenter, 300);
			assert.ok(floatCompareEquality(deviceInfo.eyetoScreenDistance, 0.01));
			assert.ok(floatCompareEquality(deviceInfo.lensSeparationDistance, 0.02));
			assert.ok(floatCompareEquality(deviceInfo.interpuillaryDistance, 0.025));
			assert.ok(floatCompareEquality(deviceInfo.distortionK[0], 1.1));
			assert.ok(floatCompareEquality(deviceInfo.distortionK[1], 2.2));
			assert.ok(floatCompareEquality(deviceInfo.distortionK[2], 3.3));
			assert.ok(floatCompareEquality(deviceInfo.distortionK[3], 4.4));
			assert.equal(deviceInfo.desktopX, 1920);
			assert.equal(deviceInfo.desktopY, 1080);
			assert.equal(deviceInfo.displayDeviceName, 'node-hmd test device');
			assert.equal(deviceInfo.displayId, 1234567890);
			assert.equal(deviceInfo.productName, 'Test Device');
			assert.equal(deviceInfo.manufacturer, 'Geocent LLC');
			assert.equal(deviceInfo.version, 5);
			assert.equal(deviceInfo.mixedData[0], 42);
			assert.equal(deviceInfo.mixedData[1], 'test token');
		});
	});

	describe('#getDeviceOrientation', function() {
		it('getDeviceOrientation sanity test.', function(done) {
			instance.getDeviceOrientation(function(err, deviceOrientation) {
				assert.ok(deviceOrientation);

				assert.ok(floatCompareEquality(deviceOrientation.yaw, 0.75));
				assert.ok(floatCompareEquality(deviceOrientation.pitch, 1.28));
				assert.ok(floatCompareEquality(deviceOrientation.roll, 2.33));

				done();
			});
		});
	});

	describe('#getDeviceOrientationSync', function() {
		var deviceOrientation = instance.getDeviceOrientationSync();

		it('getDeviceOrientation sanity test.', function() {
			assert.ok(deviceOrientation);
		});

		it('Default getDeviceOrientation #yaw test.', function() {
			assert.ok(floatCompareEquality(deviceOrientation.yaw, 0.75));
		});

		it('Default getDeviceOrientation #pitch test.', function() {
			assert.ok(floatCompareEquality(deviceOrientation.pitch, 1.28));
		});

		it('Default getDeviceOrientation #roll test.', function() {
			assert.ok(floatCompareEquality(deviceOrientation.roll, 2.33));
		});
	});

	describe('#getDevicePosition', function() {
		it('getDevicePosition sanity test.', function(done) {
			instance.getDevicePosition(function(err, devicePosition) {
				assert.ok(devicePosition);

				assert.ok(floatCompareEquality(devicePosition.x, 1.2));
				assert.ok(floatCompareEquality(devicePosition.y, 3.4));
				assert.ok(floatCompareEquality(devicePosition.z, 5.6));

				done();
			});
		});
	});

	describe('#getDevicePositionSync', function() {
		var devicePosition = instance.getDevicePositionSync();

		it('getDevicePosition sanity test.', function() {
			assert.ok(devicePosition);
		});

		it('Default devicePosition #x test.', function() {
			assert.ok(floatCompareEquality(devicePosition.x, 1.2));
		});

		it('Default devicePosition #y test.', function() {
			assert.ok(floatCompareEquality(devicePosition.y, 3.4));
		});

		it('Default devicePosition #z test.', function() {
			assert.ok(floatCompareEquality(devicePosition.z, 5.6));
		});
	});

	describe('#getDeviceQuat', function() {
		it('getDeviceQuat sanity test.', function(done) {
			instance.getDeviceQuat(function(err, deviceQuat) {
				assert.ok(deviceQuat);

				assert.ok(floatCompareEquality(deviceQuat.w, 0.11));
				assert.ok(floatCompareEquality(deviceQuat.x, 0.22));
				assert.ok(floatCompareEquality(deviceQuat.y, 0.33));
				assert.ok(floatCompareEquality(deviceQuat.z, 0.44));

				done();
			});
		});
	});

	describe('#getDeviceQuatSync', function() {
		var deviceQuat = instance.getDeviceQuatSync();
		it('getDeviceQuat sanity test.', function() {
			assert.ok(deviceQuat);
		});

		it('Default getDeviceQuat #w test.', function() {
			assert.ok(floatCompareEquality(deviceQuat.w, 0.11));
		});

		it('Default getDeviceQuat #x test.', function() {
			assert.ok(floatCompareEquality(deviceQuat.x, 0.22));
		});

		it('Default getDeviceQuat #y test.', function() {
			assert.ok(floatCompareEquality(deviceQuat.y, 0.33));
		});

		it('Default getDeviceQuat #z test.', function() {
			assert.ok(floatCompareEquality(deviceQuat.z, 0.44));
		});
	});

	describe('Oculus Rift specific #getDeviceInfo tests', function() {
		it('OvrFovPort type test.', function(done) {
			instance.getDeviceInfo(function(err, deviceInfo) {
				assert.ok(deviceInfo.ovrFovPort);

				assert.equal(deviceInfo.ovrFovPort.length, 2);
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[0].UpTan, 2.1));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[0].DownTan, 4.3));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[0].LeftTan, 6.5));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[0].RightTan, 8.7));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[1].UpTan, 2.1));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[1].DownTan, 4.3));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[1].LeftTan, 6.5));
				assert.ok(floatCompareEquality(deviceInfo.ovrFovPort[1].RightTan, 8.7));

				done();
			});
		});

		it('OvrSizei type test.', function(done) {
			instance.getDeviceInfo(function(err, deviceInfo) {
				assert.ok(deviceInfo.ovrSizei);

				assert.equal(deviceInfo.ovrSizei.w, 44);
				assert.equal(deviceInfo.ovrSizei.h, 55);

				done();
			});
		});

		it('OvrVector2i type test.', function(done) {
			instance.getDeviceInfo(function(err, deviceInfo) {
				assert.ok(deviceInfo.ovrVector2i);

				assert.equal(deviceInfo.ovrVector2i.x, 787);
				assert.equal(deviceInfo.ovrVector2i.y, 989);

				done();
			});
		});
	});
});
