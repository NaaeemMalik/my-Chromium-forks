
gn gen out\gtx --args="enable_widevine=true  treat_warnings_as_errors = false is_debug=true dcheck_always_on=false proprietary_codecs=true ffmpeg_branding=\"Chrome\" "    && autoninja -C out\gtx chrome -j 40    && "out/gtx/chrome.exe"  --enable-logging=stderr --v=0
