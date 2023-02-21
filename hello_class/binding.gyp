{
    "targets" : [
        {
            "target_name" : "hello_class",
            "sources" : [
                '<!@(ls -1 *.cc)'
            ],
            "include_dirs" : [
                "<!@(node -p \"require('node-addon-api').include\")",
            ],
            'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        }
    ]
}