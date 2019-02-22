{
  "targets": [
    {
      "target_name": "function_definition",
      "sources": [ "function_definition.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}