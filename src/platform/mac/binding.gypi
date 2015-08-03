{
  "conditions" : [
    ['OS=="mac"', {
        "include_dirs":[
          "3rdParty/TinyXml",
          "LibOVR/Include",
          "LibOVR/Src",
          "LibOVR/Src/CAPI",
          "LibOVR/Src/CAPI/GL",
          "LibOVR/Src/CAPI/Textures",
          "LibOVR/Src/Displays",
          "LibOVR/Src/Kernel",
          "LibOVR/Src/Net",
          "LibOVR/Src/Sensors",
          "LibOVR/Src/Service",
          "LibOVR/Src/Tracking",
          "LibOVR/Src/Util"
        ],

        "sources": [
          "3rdParty/TinyXml/tinyxml2.cpp",
          "LibOVR/Src/CAPI/CAPI_DistortionRenderer.cpp",
          "LibOVR/Src/CAPI/CAPI_FrameTimeManager.cpp",
          "LibOVR/Src/CAPI/CAPI_HMDRenderState.cpp",
          "LibOVR/Src/CAPI/CAPI_HMDState.cpp",
          "LibOVR/Src/CAPI/CAPI_HSWDisplay.cpp",
          "LibOVR/Src/CAPI/GL/CAPI_GL_DistortionRenderer.cpp",
          "LibOVR/Src/CAPI/GL/CAPI_GL_HSWDisplay.cpp",
          "LibOVR/Src/CAPI/GL/CAPI_GL_Util.cpp",
          "LibOVR/Src/Displays/OVR_Display.cpp",
          "LibOVR/Src/Displays/OVR_OSX_Display.cpp",
          "LibOVR/Src/Kernel/OVR_Alg.cpp",
          "LibOVR/Src/Kernel/OVR_Allocator.cpp",
          "LibOVR/Src/Kernel/OVR_Atomic.cpp",
          "LibOVR/Src/Kernel/OVR_CRC32.cpp",
          "LibOVR/Src/Kernel/OVR_File.cpp",
          "LibOVR/Src/Kernel/OVR_FileFILE.cpp",
          "LibOVR/Src/Kernel/OVR_Lockless.cpp",
          "LibOVR/Src/Kernel/OVR_Log.cpp",
          "LibOVR/Src/Kernel/OVR_Math.cpp",
          "LibOVR/Src/Kernel/OVR_RefCount.cpp",
          "LibOVR/Src/Kernel/OVR_SharedMemory.cpp",
          "LibOVR/Src/Kernel/OVR_Std.cpp",
          "LibOVR/Src/Kernel/OVR_String.cpp",
          "LibOVR/Src/Kernel/OVR_String_FormatUtil.cpp",
          "LibOVR/Src/Kernel/OVR_String_PathUtil.cpp",
          "LibOVR/Src/Kernel/OVR_SysFile.cpp",
          "LibOVR/Src/Kernel/OVR_System.cpp",
          "LibOVR/Src/Kernel/OVR_ThreadCommandQueue.cpp",
          "LibOVR/Src/Kernel/OVR_ThreadsPthread.cpp",
          "LibOVR/Src/Kernel/OVR_Timer.cpp",
          "LibOVR/Src/Kernel/OVR_UTF8Util.cpp",
          "LibOVR/Src/Net/OVR_BitStream.cpp",
          "LibOVR/Src/Net/OVR_NetworkPlugin.cpp",
          "LibOVR/Src/Net/OVR_PacketizedTCPSocket.cpp",
          "LibOVR/Src/Net/OVR_RPC1.cpp",
          "LibOVR/Src/Net/OVR_Session.cpp",
          "LibOVR/Src/Net/OVR_Socket.cpp",
          "LibOVR/Src/Net/OVR_Unix_Socket.cpp",
          "LibOVR/Src/OVR_CAPI.cpp",
          "LibOVR/Src/OVR_JSON.cpp",
          "LibOVR/Src/OVR_Profile.cpp",
          "LibOVR/Src/OVR_SerialFormat.cpp",
          "LibOVR/Src/OVR_Stereo.cpp",
          "LibOVR/Src/Service/Service_NetClient.cpp",
          "LibOVR/Src/Service/Service_NetSessionCommon.cpp",
          "LibOVR/Src/Tracking/Tracking_SensorStateReader.cpp",
          "LibOVR/Src/Util/Util_ImageWindow.cpp",
          "LibOVR/Src/Util/Util_Interface.cpp",
          "LibOVR/Src/Util/Util_LatencyTest2Reader.cpp",
          "LibOVR/Src/Util/Util_Render_Stereo.cpp"
        ],

        "link_settings": {
          "libraries": [
            "ApplicationServices.framework",
            "CoreGraphics.framework",
            "IOKit.framework"
          ],
        },

        "xcode_settings": {
          "GCC_ENABLE_CPP_RTTI": "YES",
          "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
          "OTHER_CPLUSPLUSFLAGS" : [ "-stdlib=libstdc++", "-mmacosx-version-min=10.7" ]
        },

        "defines": [
            "OVR_0_4_2"
        ]

    }]
  ]
}
