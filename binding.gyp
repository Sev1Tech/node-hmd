{
  "targets": [
    {
      "target_name": "hmd",

      "includes" : [
        "src/platform/linux/binding.gypi",
        "src/platform/mac/binding.gypi",
        "src/platform/win/binding.gypi"
      ],

      "include_dirs": [
        "src/lib",
        "src/lib/types",
        "src/3rdparty",

        "src/support/default",
        "src/support/ovr",
        "src/support/ovr/types",
        "src/support/test",
      ],

      "sources" : [
        "src/binding.cc",
        "src/lib/HMDDeviceFactory.cc",
        "src/lib/types/HMDDeviceInfo.cc",
        "src/lib/types/HMDDeviceOrientation.cc",
        "src/lib/types/HMDDevicePosition.cc",
        "src/lib/types/HMDDeviceQuat.cc",
        "src/lib/types/HMDManager.cc",

        "src/support/default/DefaultDevice.cc",
        
        "src/support/ovr/OculusRiftDevice.cc",
        "src/support/ovr/types/OvrFovPort.cc",
        "src/support/ovr/types/OvrSizei.cc",
        "src/support/ovr/types/OvrVector2i.cc",

        "src/support/test/TestDevice.cc"
      ],

      "cflags!" : [
        "-fno-exceptions"
      ],

      "cflags_cc!" : [
        "-fno-exceptions"
      ]
    }
  ]
}
