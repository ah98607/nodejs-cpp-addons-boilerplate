{
  "targets": [
    {
      "target_name": "pow",
      "sources": [ "pow.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}