{
  "targets": [
    {
      "target_name": "libovr",

      "include_dirs": [
        "src/LibOVR/Src",
        "src/LibOVR/Include"
      ],

      "sources" : [
        "src/binding.cc",

	"src/3rdParty/TinyXml/tinyxml2.cpp",

        "src/LibOVR/Src/OVR_DeviceHandle.cpp",
        "src/LibOVR/Src/OVR_DeviceImpl.cpp",
        "src/LibOVR/Src/OVR_JSON.cpp",
        "src/LibOVR/Src/OVR_LatencyTestImpl.cpp",
        "src/LibOVR/Src/OVR_Profile.cpp",
        "src/LibOVR/Src/OVR_SensorFilter.cpp",
        "src/LibOVR/Src/OVR_SensorFusion.cpp",
        "src/LibOVR/Src/OVR_SensorImpl.cpp",
        "src/LibOVR/Src/OVR_ThreadCommandQueue.cpp",
        "src/LibOVR/Src/Kernel/OVR_Alg.cpp",
        "src/LibOVR/Src/Kernel/OVR_Allocator.cpp",
        "src/LibOVR/Src/Kernel/OVR_Atomic.cpp",
        "src/LibOVR/Src/Kernel/OVR_File.cpp",
        "src/LibOVR/Src/Kernel/OVR_FileFILE.cpp",
        "src/LibOVR/Src/Kernel/OVR_Log.cpp",
        "src/LibOVR/Src/Kernel/OVR_Math.cpp",
        "src/LibOVR/Src/Kernel/OVR_RefCount.cpp",
        "src/LibOVR/Src/Kernel/OVR_Std.cpp",
        "src/LibOVR/Src/Kernel/OVR_String.cpp",
        "src/LibOVR/Src/Kernel/OVR_String_FormatUtil.cpp",
        "src/LibOVR/Src/Kernel/OVR_String_PathUtil.cpp",
        "src/LibOVR/Src/Kernel/OVR_SysFile.cpp",
        "src/LibOVR/Src/Kernel/OVR_System.cpp",
        "src/LibOVR/Src/Kernel/OVR_Timer.cpp",
        "src/LibOVR/Src/Kernel/OVR_UTF8Util.cpp",
        "src/LibOVR/Src/Util/Util_LatencyTest.cpp",
        "src/LibOVR/Src/Util/Util_Render_Stereo.cpp"
      ],

      "conditions" : [
        ['OS=="linux"', {
            "sources": [
              "src/LibOVR/Src/OVR_Linux_HIDDevice.cpp",
              "src/LibOVR/Src/OVR_Linux_SensorDevice.cpp",
              "src/LibOVR/Src/OVR_Linux_DeviceManager.cpp",
              "src/LibOVR/Src/OVR_Linux_HMDDevice.cpp",
              "src/LibOVR/Src/Kernel/OVR_ThreadsPthread.cpp"
            ]
        }],
        ['OS=="mac"', {
            "sources": [
              "src/LibOVR/Src/OVR_OSX_HIDDevice.cpp",
              "src/LibOVR/Src/OVR_OSX_SensorDevice.cpp",
              "src/LibOVR/Src/OVR_OSX_DeviceManager.cpp",
              "src/LibOVR/Src/OVR_OSX_HMDDevice.cpp",
              "src/LibOVR/Src/Kernel/OVR_ThreadsPthread.cpp"
            ],
            "link_settings": {
              "libraries": [
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
