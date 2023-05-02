os_name="$(uname)"
if [ "$os_name" = "Darwin" ]; then
    # macOS
    sudo ln -s /usr/bin/python3 /usr/local/bin/python
elif [ "$os_name" = "Linux" ]; then
    # Linux
    ./build/install-build-deps.sh
else
    echo "Unsupported operating system: $os_name . Exiting without installing."
    exit 1
fi

git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git  ~/depot_tools --depth=1
grep -qxF 'export PATH="$PATH:${HOME}/depot_tools"' ~/.bashrc || echo 'export PATH="$PATH:${HOME}/depot_tools"' >> ~/.bashrc
source ~/.bashrc

rm ../.gclient
echo 'solutions = [' > ../.gclient
echo '  {' >> ../.gclient
echo '    "name": "src",' >> ../.gclient
echo '    "url": "https://chromium.googlesource.com/chromium/src.git",' >> ../.gclient
echo '    "managed": False,' >> ../.gclient
echo '    "custom_deps": {},' >> ../.gclient
echo '    "custom_vars": {' >> ../.gclient
echo '        "checkout_pgo_profiles": True,' >> ../.gclient
echo '    },' >> ../.gclient
echo '  },' >> ../.gclient
echo ']' >> ../.gclient

gclient sync
gclient sync
gclient sync
rmdir /s /q v8
git clone -b gtx --depth=1 https://github.com/OSITA-Consulting/v8 v8
rmdir /s /q net/third_party/quiche/src
git clone -b gtx --depth=1 https://github.com/OSITA-Consulting/quiche net/third_party/quiche/src 
rmdir /s /q third_party/angle 
git clone -b gtx --depth=1 https://github.com/OSITA-Consulting/angle third_party/angle
rmdir /s /q third_party/skia
git clone -b gtx --depth=1 https://github.com/OSITA-Consulting/skia third_party/skia
rmdir /s /q third_party/pdfium
git clone -b gtx --depth=1 https://github.com/OSITA-Consulting/PDFium third_party/pdfium
gclient runhooks 
gclient runhooks 
gn gen out/gtx --args="treat_warnings_as_errors = false is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true" 
autoninja -C out/gtx chrome 


"out/gtx/GTX Browser.app/Contents/MacOS/GTX Browser" --enable-logging=stderr --v=0
# for linux
 "out/gtx/GTX Browser" --enable-logging=stderr --v=0
"out/gtx/gtxbrowser" --enable-logging=stderr --v=0


