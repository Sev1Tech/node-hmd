{
  "conditions" : [
    ['OS=="win"', {

        "include_dirs":[
            "3rdParty/glext",
            "3rdParty/TinyXml",
            "LibOVR/Include",
            "LibOVR/Src",
            "LibOVR/Src/CAPI",
            "LibOVR/Src/CAPI/D3D1X",
            "LibOVR/Src/CAPI/GL",
            "LibOVR/Src/CAPI/Shaders",
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
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D10_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D10_HSWDisplay.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D11_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D11_HSWDisplay.cpp",
            # "LibOVR/Src/CAPI/D3D1X/CAPI_D3D1X_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D1X_HSWDisplay.cpp",
            # "LibOVR/Src/CAPI/D3D1X/CAPI_D3D1X_Util.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D9_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D9_HSWDisplay.cpp",
            "LibOVR/Src/CAPI/D3D1X/CAPI_D3D9_Util.cpp",
            "LibOVR/Src/CAPI/GL/CAPI_GL_DistortionRenderer.cpp",
            "LibOVR/Src/CAPI/GL/CAPI_GL_HSWDisplay.cpp",
            "LibOVR/Src/CAPI/GL/CAPI_GL_Util.cpp",
            "LibOVR/Src/Displays/OVR_Display.cpp",
            "LibOVR/Src/Displays/OVR_Win32_Display.cpp",
            "LibOVR/Src/Displays/OVR_Win32_FocusReader.cpp",
            "LibOVR/Src/Displays/OVR_Win32_RenderShim.cpp",
            "LibOVR/Src/Displays/OVR_Win32_ShimFunctions.cpp",
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
            "LibOVR/Src/Kernel/OVR_ThreadsWinAPI.cpp",
            "LibOVR/Src/Kernel/OVR_Timer.cpp",
            "LibOVR/Src/Kernel/OVR_UTF8Util.cpp",
            "LibOVR/Src/Net/OVR_BitStream.cpp",
            "LibOVR/Src/Net/OVR_NetworkPlugin.cpp",
            "LibOVR/Src/Net/OVR_PacketizedTCPSocket.cpp",
            "LibOVR/Src/Net/OVR_RPC1.cpp",
            "LibOVR/Src/Net/OVR_Session.cpp",
            "LibOVR/Src/Net/OVR_Socket.cpp",
            "LibOVR/Src/Net/OVR_Win32_Socket.cpp",
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

        "defines": [
            "OVR_0_4_2",
            "_UNICODE",
            "UNICODE"
        ],

        "msvs_settings": {
			"VCCLCompilerTool": {
				"RuntimeLibrary": 2,
				"ExceptionHandling": 1,
                "WarningLevel": 0,
				"AdditionalOptions": [
					"/EHsc",
                    "/O2",
                    "/Oi",
                    "/Oy-",
                    "/Z7",
                    "/WX-",
                    "/MP",
                    "/Gm-",
                    "/GS",
                    "/Gy",
                    "/fp:precise",
                    "/Zc:wchar_t",
                    "/Zc:forScope",
                    "/Gd",
                    "/errorReport:prompt",
                    "/d2Zi+"
				]
			},
            # "VCLibrarianTool": {
            #     "AdditionalDependencies": [
            #         "Setupapi.lib"
            #
            #     ]
            # },
            "VCLinkerTool": {
                "SubSystem": 2,
                "AdditionalDependencies": [
                    "Setupapi.lib",
                    "Winmm.lib",
                    "Ws2_32.lib"
                ]
            }
		}
    }]
  ]
}
