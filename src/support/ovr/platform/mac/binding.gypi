{
  "conditions" : [
    ['OS=="mac"', {
        "include_dirs":[
          "LibOVR/Include",
          "LibOVR/Include/Extras",
        ],

        "link_settings": {
          "libraries": [
            "LibOVR.framework"
          ],
        },

        "xcode_settings": {
          "GCC_ENABLE_CPP_RTTI": "YES",
          "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
          "OTHER_CPLUSPLUSFLAGS" : [ "-stdlib=libc++", "-mmacosx-version-min=10.7" ]
        },
        "mac_framework_dirs" : [
          "../../../../../../src/support/ovr/platform/mac/LibOVR/Lib/Mac/Release"
        ]
    }]
  ]
}
