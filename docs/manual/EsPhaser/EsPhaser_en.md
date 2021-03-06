---
lang: en
...

# EsPhaser
![](img/esphaser.png)

EsPhaser is a phaser with up to 4096 stages of order 2 Thiran all-pass filters. This is the same phaser used in EnvelopedSine.

- [Download EsPhaser 0.1.5 - VST® 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/L3Reverb0.1.0/EsPhaser0.1.5.zip) <img
  src="img/VST_Compatible_Logo_Steinberg_negative.svg"
  alt="VST compatible logo."
  width="60px"
  style="display: inline-block; vertical-align: middle;">
- [Download Presets (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EsPhaser0.1.0/EsPhaserPresets.zip)

EsPhaser requires CPU which supports AVX or later SIMD instructions.

The package includes following builds:

- Windows 64bit
- Linux 64bit
- macOS 64bit

macOS build isn't tested because I don't have Mac. If you found a bug, please file a issue to [GitHub repository](https://github.com/ryukau/VSTPlugins) or send email to `ryukau@gmail.com`.

Linux build is built on Ubuntu 18.0.4 and tested on Bitwig 3.1.2 and Reaper 6.03. Bitwig 3.1.2 seems to have a bug that occasionally blackouts GUI.

## Installation
### Plugin
Place `*.vst3` directory to:

- `/Program Files/Common Files/VST3/` for Windows.
- `$HOME/.vst3/` for Linux.
- `/Users/$USERNAME/Library/Audio/Plug-ins/VST3/` for macOS.

DAW may provides additional VST3 directory. For more information, please refer to the manual of the DAW.

### Presets
Extract preset zip, then place preset directory to the OS specific path:

- Windows : `/Users/$USERNAME/Documents/VST3 Presets/Uhhyou`
- Linux : `$HOME/.vst3/presets/Uhhyou`
- macOS : `/Users/$USERNAME/Library/Audio/Presets/Uhhyou`

Preset directory name must be the same as the plugin. Make `Uhhyou` directory if it does not exist.

### Windows Specific
If DAW doesn't recognize the plugin, try installing C++ redistributable (`vc_redist.x64.exe`). Installer can be found in the link below.

- [The latest supported Visual C++ downloads](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)

### Linux Specific
On Ubuntu 18.0.4, those packages are required.

```bash
sudo apt install libxcb-cursor0  libxkbcommon-x11-0
```

If DAW doesn't recognize the plugin, take a look at `Package Requirements` section of the link below and make sure all the VST3 related package is installed.

- [VST 3 Interfaces: Setup Linux for building VST 3 Plug-ins](https://steinbergmedia.github.io/vst3_doc/vstinterfaces/linuxSetup.html)

REAPER on Linux may not recognize the plugin. A workaround is to delete a file `~/.config/REAPER/reaper-vstplugins64.ini` and restart REAPER.

## Color Configuration
At first time, create color config file to:

- `/Users/USERNAME/AppData/Roaming/UhhyouPlugins/style/style.json` on Windows.
- `$XDG_CONFIG_HOME/UhhyouPlugins/style/style.json` on Linux.
  - If `$XDG_CONFIG_HOME` is empty, make `$HOME/.config/UhhyouPlugins/style/style.json`.
- `/Users/$USERNAME/Library/Preferences/UhhyouPlugins/style/style.json` on macOS.

Below is a example of `style.json`.

```json
{
  "fontPath": "",
  "foreground": "#ffffff",
  "foregroundButtonOn": "#000000",
  "foregroundInactive": "#8a8a8a",
  "background": "#353d3e",
  "boxBackground": "#000000",
  "border": "#808080",
  "borderCheckbox": "#808080",
  "unfocused": "#b8a65c",
  "highlightMain": "#368a94",
  "highlightAccent": "#2c8a58",
  "highlightButton": "#a77842",
  "highlightWarning": "#8742a7",
  "overlay": "#ffffff88",
  "overlayHighlight": "#00ff0033"
}
```

Hex color codes are used.

- 6 digit color is RGB.
- 8 digit color is RGBA.

First letter `#` is conventional. Plugins ignore the first letter of color code, thus `?102938`, `\n11335577` are valid.

Do not use characters outside of `0-9a-f` for color value.

- `fontPath`: Absolute path to *.ttf font file. Not implemented in VST 3 version.
- `foreground`: Text color.
- `foregroundButtonOn`: Text color of active toggle button. Recommend to use the same value of `foreground` or `boxBackground`.
- `foregroundInactive`: Text color of inactive components. Currently, only used for TabView.
- `background`: Background color.
- `boxBackground`: Background color of inside of box shaped components (Barbox, Button, Checkbox, OptionMenu, TextKnob, VSlider).
- `border`: Border color of box shaped components.
- `borderCheckbox`: Border color of CheckBox.
- `unfocused`: Color to fill unfocused components. Currently, only used for knobs.
- `highlightMain`: Color to indicate focus is on a component. Highlight colors are also used for value of slider components (BarBox and VSlider).
- `highlightAccent`: Same as `highlightMain`. Used for cosmetics.
- `highlightButton`: Color to indicate focus is on a button.
- `highlightWarning`: Same as `highlightMain`, but only used for parameters which requires extra caution.
- `overlay`: Overlay color. Used to overlay texts and indicators.
- `overlayHighlight`: Overlay color to highlight current focus.

## Controls
Knob and number slider can do:

- <kbd>Ctrl</kbd> + <kdb>Left Click</kbd>: Reset value.
- <kbd>Shift</kbd> + <kbd>Left Drag</kbd>: Fine adjustment.

## Caution
When stage is set to 4096, it will be CPU intensive.

Output varies in different sample rate.

Output may be loud when changing Cas. Offset. Use  <kbd>Shift</kbd> + <kbd>Left Drag</kbd> to slowly change the value, or insert limiter to prevent hard clipping.

## Block Diagram
If the image is small, use <kbd>Ctrl</kbd> + <kbd>Mouse Wheel</kbd> or "View Image" on right click menu to scale.

Diagram only shows overview. It's not exact implementation.

![](img/esphaser.svg)

## Parameters
Stages

:   Number of all-pass filter.

Mix

:   Mixing ratio of dry/wet signal of phaser. `Dry : Wet` becomes `0 : 1` when turned the knob to rightmost.

Freq

:   LFO frequency.

Spread

:   Spread frequency between LFOs.

    Equation for difference of LFO phase in 1 sample:

    ```
    deltaPhase = 2 * pi * Freq / ((1 + LfoIndex * Spread) * sampleRate)
    ```

Feedback

:   Amount of feedback. Feedback is disabled when the knob is pointing to 12 o'clock. It becomes negative feedback when turned to left and positive feedback when turned to right.

Range

:   Range of all-pass filter modulation by LFO.

Min

:   Minimum value of all-pass filter modulation by LFO.

Cas. Offset

:   Phase offset between 16 LFO.

L/R Offset

:   LFO phase offset between L/R channels.

Phase

:   LFO phase. This can be used to make sound with automation. Turning `Freq` to leftmost sets LFO frequency to 0.

    Equation for phase offset:

    ```
    LfoPhaseOffset = Phase + (L/R Offset) + LfoIndex * (Cas. Offset)
    ```

## Change Log
- 0.1.5
  - Added check that DSP is initialized or not.
- 0.1.4
  - Added color configuration.
- 0.1.3
  - Reverted parameter smoother to the old one which works with variable size audio buffer.
- 0.1.2
  - Fixed a bug that cause crash when drawing string.
- 0.1.1
  - Changed display method for pop-up which shows up by clicking plugin title.
- 0.1.0
  - Initial release.

### Old Versions
- [EsPhaser 0.1.4 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/ColorConfig/EsPhaser0.1.4.zip)
- [EsPhaser 0.1.3 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LatticeReverb0.1.0/EsPhaser0.1.3.zip)
- [EsPhaser 0.1.2 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/DrawStringFix/EsPhaser0.1.2.zip)
- [EsPhaser 0.1.0 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EsPhaser0.1.0/EsPhaser0.1.0.zip)

## License
EsPhaser is licensed under GPLv3. Complete licenses are linked below.

- [https://github.com/ryukau/VSTPlugins/tree/master/License](https://github.com/ryukau/VSTPlugins/tree/master/License)

If the link above doesn't work, please send email to `ryukau@gmail.com`.

### About VST
VST is a trademark of Steinberg Media Technologies GmbH, registered in Europe and other countries.
