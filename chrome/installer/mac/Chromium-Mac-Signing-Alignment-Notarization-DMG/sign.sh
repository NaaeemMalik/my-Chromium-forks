#!/usr/bin/env bash
# Signs the application binary using the appropiated signer depending on the distribution channel
# PARAMETERS

# Fail in case something goes wrong
set -o xtrace
set -o errexit
set -o pipefail
set -o nounset


    # Declare global variables
     SCRIPT_PATH="$( cd "$(dirname "$0")" ; pwd -P )" #get path of script
     CERTIFICATE_NAME="Developer ID Application: Doug Warner (8SP2393FG9)" #add full name of cert like it's in keychain
     ID="org.gtxbrowser.GtxBrowser" #this needs to be added to the apple account as a proj and id copied from there
     BROWSER_NAME="GTX Browser" #add name
     BUILDROOT=( "/Volumes/CA/gtx3/src/out/gtx"* ) #change path to app relative to script path
     cd "$BUILDROOT"
     APP_PATH="$BUILDROOT/$BROWSER_NAME.app"
     HELPER_ID="$ID.helper"
     HELPER_RENDERER_ID="$ID.helper.renderer"
     HELPER_PLUGIN_ID="$ID.helper.plugin"
     HELPER_ALERTS_ID="$ID.framework.AlertNotificationService"
     APP_LOADER_ID="app_mode_loader"
     FRAMEWORK_ID="$ID.framework"
     LIBEGL_ID="libEGL"
     LIBGLE2_ID="libGLESv2"
     RELATIVE_FRAMEWORK="$BROWSER_NAME.app/Contents/Frameworks/$BROWSER_NAME Framework.framework"

    # Paths
     RELATIVE_APP_PATH="$BROWSER_NAME.app"
     RELATIVE_LIBEGL="$RELATIVE_FRAMEWORK/Libraries/libEGL.dylib"
     RELATIVE_LIBGLE2="$RELATIVE_FRAMEWORK/Libraries/libGLESv2.dylib"
     RELATIVE_LIBVK_SW="$RELATIVE_FRAMEWORK/Libraries/libvk_swiftshader.dylib"
     RELATIVE_APP_FRAMEWORK="$RELATIVE_FRAMEWORK"
     RELATIVE_SPARKLE_FRAMEWORK="$RELATIVE_FRAMEWORK/Frameworks/Sparkle.framework"
     RELATIVE_APP_HELPER_PATH="$RELATIVE_FRAMEWORK/Helpers/$BROWSER_NAME Helper.app"
     RELATIVE_APP_HELPER_GPU_PATH="$RELATIVE_FRAMEWORK/Helpers/$BROWSER_NAME Helper (GPU).app"
     RELATIVE_APP_HELPER_PLUGIN_PATH="$RELATIVE_FRAMEWORK/Helpers/$BROWSER_NAME Helper (Plugin).app"
     RELATIVE_APP_HELPER_RENDERER_PATH="$RELATIVE_FRAMEWORK/Helpers/$BROWSER_NAME Helper (Renderer).app"
     RELATIVE_APP_HELPER_ALERTS_PATH="$RELATIVE_FRAMEWORK/Helpers/$BROWSER_NAME Helper (Alerts).app"
     RELATIVE_CRASHPAD_PATH="$RELATIVE_FRAMEWORK/Helpers/chrome_crashpad_handler"
     RELATIVE_APP_MODE_LOADER_PATH="$RELATIVE_FRAMEWORK/Helpers/app_mode_loader"
     RELATIVE_LIBGLE_SW="$RELATIVE_FRAMEWORK/Libraries/libswiftshader_libGLESv2.dylib"
     RELATIVE_libGLESv2="$RELATIVE_FRAMEWORK/Libraries/libGLESv2.dylib"
     RELATIVE_LIBEGL_SW="$RELATIVE_FRAMEWORK/Libraries/libswiftshader_libEGL.dylib"


    # Entitlements
    RELATIVE_ENTITLEMENTS_APP_PATH="$SCRIPT_PATH/app-entitlements.plist"
    RELATIVE_ENTITLEMENTS_HELPER_PATH="$SCRIPT_PATH/helper-entitlements.plist"
    RELATIVE_ENTITLEMENTS_HELPER_RENDERER_PATH="$SCRIPT_PATH/helper-renderer-entitlements.plist"
    RELATIVE_ENTITLEMENTS_HELPER_GPU_PATH="$SCRIPT_PATH/helper-gpu-entitlements.plist"
    RELATIVE_ENTITLEMENTS_HELPER_PLUGIN_PATH="$SCRIPT_PATH/helper-plugin-entitlements.plist"

    # Code sign files 
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "chrome_crashpad_handler"' --timestamp --options runtime,restrict,library,kill --force "$RELATIVE_CRASHPAD_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "libvk_swiftshader"' --timestamp --force "$RELATIVE_LIBVK_SW"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$HELPER_ID"'"' --timestamp --options restrict,kill,runtime --force --entitlements "$RELATIVE_ENTITLEMENTS_HELPER_GPU_PATH" "$RELATIVE_APP_HELPER_GPU_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$HELPER_RENDERER_ID"'"' --timestamp --options restrict,kill,runtime --force --entitlements "$RELATIVE_ENTITLEMENTS_HELPER_RENDERER_PATH" "$RELATIVE_APP_HELPER_RENDERER_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$HELPER_PLUGIN_ID"'"' --timestamp --options restrict,kill,runtime --force --entitlements "$RELATIVE_ENTITLEMENTS_HELPER_PLUGIN_PATH" "$RELATIVE_APP_HELPER_PLUGIN_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$HELPER_ALERTS_ID"'"' --timestamp --options runtime,restrict,library,kill --force "$RELATIVE_APP_HELPER_ALERTS_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$LIBGLE2_ID"'"' --timestamp --force "$RELATIVE_LIBGLE2"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$LIBEGL_ID"'"' --timestamp --force "$RELATIVE_LIBEGL"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "libswiftshader_libEGL"' --timestamp --force "$RELATIVE_LIBEGL_SW"
    
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "libswiftshader_libGLESv2"' --force --timestamp "$RELATIVE_LIBGLE_SW"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "app_mode_loader"' --timestamp --options runtime,restrict,library,kill --force "$RELATIVE_APP_MODE_LOADER_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$HELPER_ID"'"' --timestamp --options runtime,restrict,kill  --force --entitlements "$RELATIVE_ENTITLEMENTS_HELPER_PATH" "$RELATIVE_APP_HELPER_PATH"
    codesign -s "$CERTIFICATE_NAME" --requirements '=designated => identifier "'"$FRAMEWORK_ID"'"' --timestamp --force "$RELATIVE_APP_FRAMEWORK"
    codesign -s "$CERTIFICATE_NAME" --timestamp --options runtime,restrict,library,kill --deep --force --entitlements "$RELATIVE_ENTITLEMENTS_APP_PATH" "$RELATIVE_APP_PATH"

  
    #verify code sign
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_CRASHPAD_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_CRASHPAD_PATH"
    codesign --display --verbose=5 --requirements - "$APP_PATH"
    codesign --verify --verbose=6 --deep --no-strict "$APP_PATH"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_FRAMEWORK"
    codesign --verify --verbose=6 --deep --no-strict "$BUILDROOT/$RELATIVE_APP_FRAMEWORK"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_HELPER_GPU_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_APP_HELPER_GPU_PATH"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_LIBEGL_SW"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_LIBEGL_SW"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_HELPER_RENDERER_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_APP_HELPER_RENDERER_PATH"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_HELPER_PLUGIN_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_APP_HELPER_PLUGIN_PATH"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_HELPER_ALERTS_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_APP_HELPER_ALERTS_PATH"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_LIBGLE2"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_LIBGLE2"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_LIBEGL"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_LIBEGL"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_MODE_LOADER_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_APP_MODE_LOADER_PATH"
    codesign --display --verbose=5 --requirements - "$BUILDROOT/$RELATIVE_APP_HELPER_PATH"
    codesign --verify --verbose=6 --deep "$BUILDROOT/$RELATIVE_APP_HELPER_PATH"
    codesign --display --requirements - --verbose=5 "$APP_PATH"
    spctl --assess -vv "$APP_PATH"



# make dmg and sign and notorise it
# create-dmg out/gtx/GTX\ Browser.app
# xcrun notarytool submit --wait --keychain-profile "Developer ID Application: Doug Warner (8SP2393FG9)" GTX\ Browser\ 98.0.4758.132.dmg