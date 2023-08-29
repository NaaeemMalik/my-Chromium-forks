# README.md for Open Screen Library in GTX Browser

openscreen is built in GTX Browser with some build differences based on the value
of the GN argument `build_with_chromium`.  `build_with_chromium` is defined in
`//build_overrides/build.gni` and is `true` when openscreen is built as part of
GTX Browser and `false` when built standalone.
