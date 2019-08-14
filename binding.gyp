{
  "targets": [
    {
      "target_name": "PiLed",
      "sources": [ "pi-led.cpp" ],
      "dependencies": ["bit_array", "wiringPi", "wiringPiSPI", "<!(node -p \"require('node-addon-api').gyp\")"],
      'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "<!(node -e \"require('nan')\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    },
    {
      "target_name": "bit_array",
      "type": "static_library",
      "sources": [ "bit_array.cpp" ]
    },
    {
      "target_name": "wiringPi",
      "type": "static_library",
      "sources": [ "wiringPi.c" ]
    },
    {
      "target_name": "wiringPiSPI",
      "type": "static_library",
      "sources": [ "wiringPiSPI.c" ]
    }
  ]
}
