#!/bin/bash



# # Check if Chromium is already running

# if pgrep -x "gtxbrowser" > /dev/null; then

#     echo "GTX Browser is currently running. Close the browser before updating."

#     exit 1

# fi



# Get the current version of Chromium

current_version=$(gtx-browser --version | awk '{print $3}')



# Get the latest version and download link from a JSON URL

json_data=$(curl -s http://localhost/status.json)
#json_data=$(curl -s https://api.gpool.io/status/gtx-browser?os=windows)

latest_version=$(echo $json_data | jq -r '.version')

download_link=$(echo $json_data | jq -r '.downloadUrl')





# Check if the current version is different from the latest version

if [ "$current_version" != "$latest_version" ]; then

    echo "GTX Browser is outdated. Updating to version $latest_version..."

    wget -O gtxbrowser.deb $download_link

#kill gtxbrowser on linux

    pkill gtxbrowser

    sudo dpkg -i gtxbrowser.deb

    rm gtxbrowser.deb

    echo "GTX Browser has been updated to version $latest_version."

else

    echo "GTX Browser is already up to date."

fi

