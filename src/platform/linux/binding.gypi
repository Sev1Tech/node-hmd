{
  "conditions" : [
    ['OS=="linux"', {
        "include_dirs":[
            "3rdParty/EDID",
            "3rdParty/TinyXml",
            "LibOVR/Include",
            "LibOVR/Src",
            "LibOVR/Src/CAPI",
            "LibOVR/Src/CAPI/GL",
            "LibOVR/Src/Kernel",
            "LibOVR/Src/Util"
        ],

        "sources": [
            "3rdParty/EDID/edid.cpp",
            "LibOVR/Src/OVR_CAPI.cpp",
            "LibOVR/Src/CAPI/CAPI_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/GL/CAPI_GL_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/GL/CAPI_GL_Util.cpp",
            "LibOVR/Src/CAPI/CAPI_FrameTimeManager.cpp",
            "LibOVR/Src/CAPI/CAPI_GlobalState.cpp",
            "LibOVR/Src/CAPI/CAPI_HMDRenderState.cpp",
            "LibOVR/Src/CAPI/CAPI_HMDState.cpp",
            "LibOVR/Src/OVR_DeviceHandle.cpp",
            "LibOVR/Src/OVR_DeviceImpl.cpp",
            "LibOVR/Src/OVR_JSON.cpp",
            "LibOVR/Src/OVR_LatencyTestImpl.cpp",
            "LibOVR/Src/OVR_Profile.cpp",
            "LibOVR/Src/OVR_Linux_SensorDevice.cpp",
            "LibOVR/Src/OVR_SensorCalibration.cpp",
            "LibOVR/Src/OVR_SensorFilter.cpp",
            "LibOVR/Src/OVR_SensorFusion.cpp",
            "LibOVR/Src/OVR_SensorImpl.cpp",
            "LibOVR/Src/OVR_Sensor2Impl.cpp",
            "LibOVR/Src/OVR_SensorImpl_Common.cpp",
            "LibOVR/Src/OVR_SensorTimeFilter.cpp",
            "LibOVR/Src/OVR_Stereo.cpp",
            "LibOVR/Src/OVR_ThreadCommandQueue.cpp",
            "LibOVR/Src/Kernel/OVR_Alg.cpp",
            "LibOVR/Src/Kernel/OVR_Allocator.cpp",
            "LibOVR/Src/Kernel/OVR_Atomic.cpp",
            "LibOVR/Src/Kernel/OVR_File.cpp",
            "LibOVR/Src/Kernel/OVR_FileFILE.cpp",
            "LibOVR/Src/Kernel/OVR_Log.cpp",
            "LibOVR/Src/Kernel/OVR_Math.cpp",
            "LibOVR/Src/OVR_Recording.cpp",
            "LibOVR/Src/Kernel/OVR_RefCount.cpp",
            "LibOVR/Src/Kernel/OVR_Std.cpp",
            "LibOVR/Src/Kernel/OVR_String.cpp",
            "LibOVR/Src/Kernel/OVR_String_FormatUtil.cpp",
            "LibOVR/Src/Kernel/OVR_String_PathUtil.cpp",
            "LibOVR/Src/Kernel/OVR_SysFile.cpp",
            "LibOVR/Src/Kernel/OVR_System.cpp",
            "LibOVR/Src/Kernel/OVR_Timer.cpp",
            "LibOVR/Src/Kernel/OVR_UTF8Util.cpp",
            "LibOVR/Src/Util/Util_LatencyTest.cpp",
            "LibOVR/Src/Util/Util_LatencyTest2.cpp",
            "LibOVR/Src/Util/Util_Render_Stereo.cpp",
            "LibOVR/Src/Kernel/OVR_ThreadsPthread.cpp",
            "LibOVR/Src/OVR_Linux_HIDDevice.cpp",
            "LibOVR/Src/OVR_Linux_SensorDevice.cpp",
            "LibOVR/Src/OVR_Linux_DeviceManager.cpp",
            "LibOVR/Src/OVR_Linux_HMDDevice.cpp",
        ],

        "defines": [
            "OVR_0_3_2"
        ],

        "link_settings": {
            "libraries": [
                "-ludev",
                "-lX11",
                "-lXrandr"
            ]
        }
    }]
  ]
}
