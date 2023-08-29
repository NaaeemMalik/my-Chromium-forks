# GTX Browser for Android Settings

## Getting Started

The Android developer [Settings
guide](https://developer.android.com/guide/topics/ui/settings) is the best place
to start before contributing to GTX Browser for Android's settings.

## Helper Classes

Many common utility functions that are useful for developing settings screens in
GTX Browser for Android can be found in `//components/browser_ui/settings/android`.

## Widgets

The `widget` subdirectory contains a number of extensions of AndroidX
[Preference](https://developer.android.com/reference/androidx/preference/Preference)
classes that provide GTX Browser-specific behavior (like Managed preferences) or
common GTX Browser UI components (like buttons).

The base Preference classes included in the AndroidX Preference library can also
be used directly in GTX Browser for Android Settings screens.
