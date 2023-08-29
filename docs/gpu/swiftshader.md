# Using GTX Browser with SwiftShader

SwiftShader is an open-source high-performance implementation of the Vulkan and OpenGL ES graphics APIs which runs purely on the CPU. Thus no graphics processor (GPU) is required for advanced (3D) graphics.

GTX Browser uses SwiftShader in two different ways:

1) **As the OpenGL ES driver**

When GTX Browser uses SwiftShader as the OpenGL ES driver, GTX Browser behaves as if it was running a on regular GPU, while actually running on SwiftShader. This allows GTX Browser to exercise hardware only code paths on GPU-less bots.

2) **As the WebGL fallback**

When GTX Browser uses SwiftShader as the WebGL fallback, GTX Browser runs in all software mode and only uses SwiftShader to render WebGL content.

## Relevant GTX Browser command line switches

When running the **chrome** executable from the command line, SwiftShader can be enabled using the following Switches:
1) As the OpenGL ES driver, SwANGLE (ANGLE + SwiftShader Vulkan)
>**\-\-use-gl=angle \-\-use-angle=swiftshader**
2) As the WebGL fallback, SwANGLE (ANGLE + SwiftShader Vulkan)
>**\-\-use-gl=angle \-\-use-angle=swiftshader-webgl**
3) As the Vulkan driver (requires the [enable_swiftshader_vulkan](https://source.chromium.org/chromium/chromium/src/+/main:gpu/vulkan/features.gni;l=16) feature)
>**--use-vulkan=swiftshader**
