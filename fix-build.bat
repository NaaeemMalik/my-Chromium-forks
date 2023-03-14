@REM ninja -C out\gtx -t clean

gclient sync

cd v8
git reset --hard
git remote add gtx https://github.com/OSITA-Consulting/v8
git pull gtx gtx
git switch gtx 
cd ..

cd net\third_party\quiche\src
git reset --hard
git remote add gtx https://github.com/OSITA-Consulting/quiche
git pull gtx gtx
git switch gtx 
cd ..\..

cd angle
git reset --hard
git remote add gtx https://github.com/OSITA-Consulting/angle
git pull gtx gtx
git switch gtx 
cd ..


cd skia
git reset --hard
git remote add gtx https://github.com/OSITA-Consulting/skia
git pull gtx gtx
git switch gtx 
cd ..

cd pdfium
git reset --hard
git remote add gtx https://github.com/OSITA-Consulting/PDFium
git pull gtx gtx
git switch gtx 


gclient sync

gn gen out\gtx --args="treat_warnings_as_errors = false is_debug=false dcheck_always_on=false blink_symbol_level=0 symbol_level=0 proprietary_codecs=true ffmpeg_branding=\"Chrome\" is_official_build=true"

autoninja -C out\gtx chrome

ninja -C out\gtx mini_installer


"out/gtx/gtxbrowser.exe"

