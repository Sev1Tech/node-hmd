var	assert = require('assert'),
	hmd = require('../node-hmd');

function floatCompareEquality(a, b) {
	return Math.abs(a - b) < 0.000001;
}

describe('node-hmd tests.', function() {
	it('#getSupported', function() {
		console.log(hmd.getSupported());
	});	
});

describe('node-hmd manager tests.', function() {
	var instance = hmd.createManager("test");

	describe('#createManager', function() {
		it('node-hmd createManager failure test.', function() {
			assert.strictEqual(typeof(hmd.createManager()), "undefined");
			assert.strictEqual(typeof(hmd.createManager("doesnotexist")), "undefined");
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
				var distortionK = deviceInfo.distortionK;
				assert.ok(floatCompareEquality(distortionK[0], 1.1));
				assert.ok(floatCompareEquality(distortionK[1], 2.2));
				assert.ok(floatCompareEquality(distortionK[2], 3.3));
				assert.ok(floatCompareEquality(distortionK[3], 4.4));
				assert.equal(deviceInfo.desktopX, 1920);
				assert.equal(deviceInfo.desktopY, 1080);
				assert.equal(deviceInfo.displayDeviceName, "node-hmd test device");
				assert.equal(deviceInfo.displayId, 1234567890);
				assert.equal(deviceInfo.productName, "Test Device");
				assert.equal(deviceInfo.manufacturer, "Geocent LLC");
				assert.equal(deviceInfo.version, 5);

				done();
			});
		});
	});

	describe('#getDeviceInfoSync', function() {
		var deviceInfo = instance.getDeviceInfoSync();

		it('getDeviceInfoSync sanity test.', function() {
			assert.ok(deviceInfo);
		});

		it('Default getDeviceInfo #hResolution test.', function() {
			assert.equal(deviceInfo.hResolution, 800);
		});

		it('Default getDeviceInfo #vResolution test.', function() {
			assert.equal(deviceInfo.vResolution, 600);
		});
		it('Default getDeviceInfo #hScreenSize test.', function() {
			assert.ok(floatCompareEquality(deviceInfo.hScreenSize, 0.8));
		});
		it('Default getDeviceInfo #vScreenSize test.', function() {
			assert.ok(floatCompareEquality(deviceInfo.vScreenSize, 0.64));
		});

		it('Default getDeviceInfo #vScreenCenter test.', function() {
			assert.equal(deviceInfo.vScreenCenter, 300);
		});

		it('Default getDeviceInfo #eyetoScreenDistance test.', function() {
			assert.ok(floatCompareEquality(deviceInfo.eyetoScreenDistance, 0.01));
		});

		it('Default getDeviceInfo #lensSeparationDistance test.', function() {
			assert.ok(floatCompareEquality(deviceInfo.lensSeparationDistance, 0.02));
		});

		it('Default getDeviceInfo #interpuillaryDistance test.', function() {
			assert.ok(floatCompareEquality(deviceInfo.interpuillaryDistance, 0.025));
		});

		it('Default getDeviceInfo #distortionK test.', function() {
			var distortionK = deviceInfo.distortionK;
			assert.ok(floatCompareEquality(distortionK[0], 1.1));
			assert.ok(floatCompareEquality(distortionK[1], 2.2));
			assert.ok(floatCompareEquality(distortionK[2], 3.3));
			assert.ok(floatCompareEquality(distortionK[3], 4.4));
		});

		it('Default getDeviceInfo #desktopX test.', function() {
			assert.equal(deviceInfo.desktopX, 1920);
		});

		it('Default getDeviceInfo #desktopY test.', function() {
			assert.equal(deviceInfo.desktopY, 1080);
		});

		it('Default getDeviceInfo #displayDeviceName test.', function() {
			assert.equal(deviceInfo.displayDeviceName, "node-hmd test device");
		});

		it('Default getDeviceInfo #displayId test.', function() {
			assert.equal(deviceInfo.displayId, 1234567890);
		});

		it('Default getDeviceInfo #productName test.', function() {
			assert.equal(deviceInfo.productName, "Test Device");
		});

		it('Default getDeviceInfo #manufacturer test.', function() {
			assert.equal(deviceInfo.manufacturer, "Geocent LLC");
		});

		it('Default getDeviceInfo #version test.', function() {
			assert.equal(deviceInfo.version, 5);
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
});

