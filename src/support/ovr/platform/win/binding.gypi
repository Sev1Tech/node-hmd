{
  "conditions" : [
    ['OS=="win"', {

        "include_dirs":[
          "LibOVR/Include",
          "LibOVR/Include/Extras",
        ],

        "defines": [
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
            "VCLinkerTool": {
                "SubSystem": 2,
                "AdditionalDependencies": [
                    "Setupapi.lib",
                    "Winmm.lib",
                    "Ws2_32.lib",
                    "..\src\support\ovr\platform\win\LibOVR\Lib\Windows\\x64\Release\VS2013\LibOVR.lib"
                ]
            }
		}
    }]
  ]
}
