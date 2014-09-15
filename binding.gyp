{
  "targets": [
    {
      "target_name": "hmd",
      
      "includes" : [
        "src/platform/mac/binding.gypi"
      ],

      "include_dirs": [
        "src/lib",
        "src/3rdparty/nan",
        
        "src/support/default",
        "src/support/ovr",
        "src/support/test",
      ],

      "sources" : [
        "src/binding.cc",
        "src/lib/HMDDeviceFactory.cc",
        "src/lib/HMDDeviceInfo.cc",
        "src/lib/HMDDeviceInfoWrap.cc",
        "src/lib/HMDDeviceOrientation.cc",
        "src/lib/HMDDeviceOrientationWrap.cc",
        "src/lib/HMDManagerWrap.cc",

        "src/support/default/DefaultDevice.cc",
        "src/support/ovr/OculusRiftDevice.cc",
        "src/support/test/TestDevice.cc"
      ]
    }
  ]
}
