{
  "targets": [
    {
      "target_name": "hmd",

      "include_dirs": [
        "src/lib",
        
        "src/support/default",
        "src/support/test",

        "src/support/ovr/LibOVR/Src",
        "src/support/ovr/LibOVR/Include"
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
        "src/support/test/TestDevice.cc",

      	"src/support/ovr/3rdParty/TinyXml/tinyxml2.cpp",
        "src/support/ovr/LibOVR/Src/OVR_DeviceHandle.cpp",
        "src/support/ovr/LibOVR/Src/OVR_DeviceImpl.cpp",
        "src/support/ovr/LibOVR/Src/OVR_JSON.cpp",
        "src/support/ovr/LibOVR/Src/OVR_LatencyTestImpl.cpp",
        "src/support/ovr/LibOVR/Src/OVR_Profile.cpp",
        "src/support/ovr/LibOVR/Src/OVR_SensorFilter.cpp",
        "src/support/ovr/LibOVR/Src/OVR_SensorFusion.cpp",
        "src/support/ovr/LibOVR/Src/OVR_SensorImpl.cpp",
        "src/support/ovr/LibOVR/Src/OVR_ThreadCommandQueue.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Alg.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Allocator.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Atomic.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_File.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_FileFILE.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Log.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Math.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_RefCount.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Std.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_String.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_String_FormatUtil.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_String_PathUtil.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_SysFile.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_System.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_Timer.cpp",
        "src/support/ovr/LibOVR/Src/Kernel/OVR_UTF8Util.cpp",
        "src/support/ovr/LibOVR/Src/Util/Util_LatencyTest.cpp",
        "src/support/ovr/LibOVR/Src/Util/Util_Render_Stereo.cpp"
      ],

      "conditions" : [
        ['OS=="linux"', {
            "sources": [
              "src/support/ovr/LibOVR/Src/OVR_Linux_HIDDevice.cpp",
              "src/support/ovr/LibOVR/Src/OVR_Linux_SensorDevice.cpp",
              "src/support/ovr/LibOVR/Src/OVR_Linux_DeviceManager.cpp",
              "src/support/ovr/LibOVR/Src/OVR_Linux_HMDDevice.cpp",
              "src/support/ovr/LibOVR/Src/Kernel/OVR_ThreadsPthread.cpp"
            ]
        }],
        ['OS=="mac"', {
            "sources": [
              "src/support/ovr/LibOVR/Src/OVR_OSX_HIDDevice.cpp",
              "src/support/ovr/LibOVR/Src/OVR_OSX_SensorDevice.cpp",
              "src/support/ovr/LibOVR/Src/OVR_OSX_DeviceManager.cpp",
              "src/support/ovr/LibOVR/Src/OVR_OSX_HMDDevice.cpp",
              "src/support/ovr/LibOVR/Src/Kernel/OVR_ThreadsPthread.cpp"
            ],
            "link_settings": {
              "libraries": [
                "ApplicationServices.framework",
                "CoreGraphics.framework",
                "IOKit.framework"
              ],
            },
        }],
        ['OS=="win"', {
          "sources": [
          ]
        }],
      ]
    }
  ]
}
