{
  "targets": [
    {
      "target_name": "PiLed",
      "sources": [ "pi-led.cpp" ],
      "dependencies": ["bit_array","led-matrix","led-module", "<!(node -p \"require('node-addon-api').gyp\")"],
      'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "<!(node -e \"require('nan')\")",
            "/usr/local/include"
      ],
      "libraries": [ "-L/usr/local/lib", "-lwiringPi", "-lwiringPiSPI" ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    },
   {
      "target_name": "led-matrix",

      "dependencies": ["bit_array", "wiringPi", "wiringPiSPI"],
      "type": "static_library",
      "sources": [ "led-matrix.cpp" ]
    },
    {
      "target_name": "led-module",
      "dependencies": ["bit_array", "wiringPi", "wiringPiSPI"],
      "type": "static_library",
      "sources": [ "led-module.cpp" ]
    },
    {
      "target_name": "bit_array",
      "type": "static_library",
      "sources": [ "bit_array.cpp" ]
    }
  ]
}
