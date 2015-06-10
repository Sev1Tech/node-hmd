{
  "targets": [
    {
      "target_name": "hmd",

      "includes" : [
        "src/support/ovr/binding.gypi"
      ],

      "include_dirs": [
        "src/lib",
        "src/lib/types",
        "src/3rdparty",

        "src/support/default",
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
