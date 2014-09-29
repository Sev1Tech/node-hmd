{
  "targets": [
    {
      "target_name": "hmd",
      
      "includes" : [
        "src/platform/mac/binding.gypi"
      ],

      "include_dirs": [
        "src/lib",
        "src/lib/types/HMDDeviceInfo",
        "src/lib/types/HMDDeviceOrientation",
        "src/lib/types/HMDDevicePosition",
        "src/lib/types/HMDDeviceQuat",
        "src/3rdparty",
        
        "src/support/default",
        "src/support/ovr",
        "src/support/ovr/types/OvrFovPort",
        "src/support/ovr/types/OvrSizei",
        "src/support/ovr/types/OvrVector2i",
        "src/support/test",
      ],

      "sources" : [
        "src/binding.cc",
        "src/lib/HMDDeviceFactory.cc",
        "src/lib/HMDManagerWrap.cc",
        "src/lib/types/HMDDeviceInfo/HMDDeviceInfo.cc",
        "src/lib/types/HMDDeviceInfo/HMDDeviceInfoWrap.cc",
        "src/lib/types/HMDDeviceOrientation/HMDDeviceOrientation.cc",
        "src/lib/types/HMDDeviceOrientation/HMDDeviceOrientationWrap.cc",
        "src/lib/types/HMDDevicePosition/HMDDevicePosition.cc",
        "src/lib/types/HMDDevicePosition/HMDDevicePositionWrap.cc",
        "src/lib/types/HMDDeviceQuat/HMDDeviceQuat.cc",
        "src/lib/types/HMDDeviceQuat/HMDDeviceQuatWrap.cc",

        "src/support/default/DefaultDevice.cc",

        "src/support/ovr/OculusRiftDevice.cc",
        "src/support/ovr/types/OvrFovPort/OvrFovPort.cc",
        "src/support/ovr/types/OvrFovPort/OvrFovPortWrap.cc",
        "src/support/ovr/types/OvrSizei/OvrSizei.cc",
        "src/support/ovr/types/OvrSizei/OvrSizeiWrap.cc",
        "src/support/ovr/types/OvrVector2i/OvrVector2i.cc",
        "src/support/ovr/types/OvrVector2i/OvrVector2iWrap.cc",

        "src/support/test/TestDevice.cc"
      ],

      "cflags!" : [
        "-fno-rtti",
        "-fno-exceptions"
      ],

      "cflags_cc!" : [
        "-fno-rtti",
        "-fno-exceptions"
      ]
    }
  ]
}
