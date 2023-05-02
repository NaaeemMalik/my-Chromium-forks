gn gen out/gtx --args="treat_warnings_as_errors = false is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true" 


os_name="$(uname)"
if [ "$os_name" = "Darwin" ]; then
    # macOS
    caffeinate autoninja -C out/gtx chrome
    "out/gtx/GTX Browser.app/Contents/MacOS/GTX Browser"
elif [ "$os_name" = "Linux" ]; then
    # Linux
    autoninja -C out/gtx chrome
    "out/gtx/GTX Browser"
    "out/gtx/gtxbrowser"
else
    echo "Unsupported operating system: $os_name . Exiting without installing."
    exit 1
fi

