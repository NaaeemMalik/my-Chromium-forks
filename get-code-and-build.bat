git clone -b gtx-dev --depth=1 https://github.com/OSITA-Consulting/gtx-browser.git src

git clone -b gtx-dev --depth=1 https://github.com/OSITA-Consulting/gtx-browser.git src

cd src


gclient sync

gclient sync

gclient sync

gn gen out\gtx --args="is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true"

gn gen out\gtx --args="is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true"


autoninja -C out\gtx chrome

autoninja -C out\gtx chrome

autoninja -C out\gtx chrome

autoninja -C out\gtx chrome

ninja -C out\gtx mini_installer

ninja -C out\gtx mini_installer


"out/gtx/gtx browser.exe"
