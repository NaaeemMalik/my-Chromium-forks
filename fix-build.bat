ninja -C out\gtx -t clean

gclient sync

gn gen out\gtx --args="is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true"

autoninja -C out\gtx chrome

ninja -C out\gtx mini_installer


"out/gtx/gtx browser.exe"

