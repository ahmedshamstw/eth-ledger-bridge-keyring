{
  "targets": [
    # {
    #   "target_name": "hello",
    #   "cflags!": [ "-fno-exceptions" ],
    #   "cflags_cc!": [ "-fno-exceptions" ],
    #   "sources": [ "hello.cc","test_api.c"],
    #   "include_dirs": [
    #     "<!@(node -p \"require('node-addon-api').include\")",
    #     "./"
    #   ],
    #   'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    # },
    
    {
        'target_name': 'hello',
        'sources': [ 'crypto/hello.cc' ],
        'defines': [
            '_LARGEFILE_SOURCE',
            '_FILE_OFFSET_BITS=64',
            'NAPI_DISABLE_CPP_EXCEPTIONS'
        ],
        'cflags!': ['-ansi', '-fno-exceptions' ],
        'cflags_cc!': [ '-fno-exceptions' ],
        'cflags': ['-g', '-exceptions'],
        'cflags_cc': ['-g', '-exceptions'],
        'include_dirs': [
          "<!@(node -p \"require('node-addon-api').include\")",
          'crypto'
        ],
        'dependencies': [
          "<!(node -p \"require('node-addon-api').gyp\")"
        ],
    }, # target HID
  ]
}
