var	assert = require('assert'),
	hmd = require('../node-hmd');

describe('node-hmd tests.', function() {
	var instance = hmd();

	describe('constructor', function() {
		it('Default constructor sanity test.', function() {
			assert.ok(instance);
		});	
	});

	describe('#getDeviceInfo', function() {
		var deviceInfo = instance.getDeviceInfo();

		it('getDeviceInfo sanity test.', function() {
			assert.ok(deviceInfo);
		});

		it('Default getDeviceInfo #productName test.', function() {
			assert.equal(deviceInfo.productName(), "Default Device");
		});	
		it('Default getDeviceInfo #manufacturer test.', function() {
			assert.equal(deviceInfo.manufacturer(), "Geocent LLC");
		});	
	});
});

