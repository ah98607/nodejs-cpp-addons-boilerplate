{
  "targets": [
    {
      "target_name": "product",
      "sources": [ "product.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}