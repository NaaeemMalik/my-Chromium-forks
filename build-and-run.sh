
os_name="$(uname)"
if [ "$os_name" = "Darwin" ]; then
    # macOS
    gn gen out/gtx --args="treat_warnings_as_errors = false is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true" && caffeinate autoninja -C out/gtx chrome &&    "out/gtx/GTX Browser.app/Contents/MacOS/GTX Browser" --enable-logging=stderr --v=0
elif [ "$os_name" = "Linux" ]; then
    # Linux
    gn gen out/gtx --args="treat_warnings_as_errors = false enable_linux_installer = true is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true" &&    autoninja -C out/gtx chrome &&    cp -r out/gtx/default_apps out/gtx/extensions &&    "out/gtx/gtxbrowser" --enable-logging=stderr --v=0
else
    echo "Unsupported operating system: $os_name . Exiting without installing."
    exit 1
fi
