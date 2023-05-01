gn gen out/gtx --args="treat_warnings_as_errors = false is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true" 
caffeinate autoninja -C out/gtx chrome
autoninja -C out/gtx chrome
"out/gtx/GTX Browser.app/Contents/MacOS/GTX Browser"
# for linux
"out/gtx/GTX Browser"
"out/gtx/gtxbrowser"