---
lang: en
...

# LatticeReverb
![](img/latticereverb.png)

LatticeReverb is a reverb using lattice structure. Equipped with 16 delays per channel.

- [Download LatticeReverb 0.1.3 - VST® 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/L3Reverb0.1.0/LatticeReverb0.1.3.zip) <img
  src="img/VST_Compatible_Logo_Steinberg_negative.svg"
  alt="VST compatible logo."
  width="60px"
  style="display: inline-block; vertical-align: middle;">
- [Download Presets (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LatticeReverb0.1.0/LatticeReverbPresets.zip)

LatticeReverb requires CPU which supports AVX or later SIMD instructions.

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
<kbd>Right Click</kbd> on the controls pops up a context menu provided by DAW.

Knob and slider can do:

- <kbd>Ctrl</kbd> + <kbd>Left Click</kbd>: Reset value.
- <kbd>Shift</kbd> + <kbd>Left Drag</kbd>: Fine adjustment.

There is an additional control for number sliders used for `Octave`, `Seed` etc.

- <kbd>Middle Click</kbd> : Flip minimum and maximum.

Control with many blue vertical bars (BarBox) have some keyboard shortcuts. `LFO Wave` on Main tab and `Gain`, `Width`, `Pitch`, `Phase` on Wavetable tab are using BarBox. Shortcuts are enabled after left clicking BarBox and mouse cursor is on the inside of BarBox. Cheat sheet is available on Infomation tab.

| Input                                   | Control                               |
| --------------------------------------- | ------------------------------------- |
| <kbd>Ctrl</kbd> + <kbd>Left Drag</kbd>  | Reset to Default                      |
| <kbd>Shift</kbd> + <kbd>Left Drag</kbd> | Naive Draw (Skip bars between frames) |
| <kbd>Right Drag</kbd>                   | Draw Line                             |
| <kbd>a</kbd>                            | Alternate Sign                        |
| <kbd>d</kbd>                            | Reset Everything to Default           |
| <kbd>D</kbd>                            | Toggle Min/Mid/Max                    |
| <kbd>e</kbd>                            | Emphasize Low                         |
| <kbd>E</kbd>                            | Emphasize High                        |
| <kbd>f</kbd>                            | Low-pass Filter                       |
| <kbd>F</kbd>                            | High-pass Filter                      |
| <kbd>i</kbd>                            | Invert Value (Preserve minimum)       |
| <kbd>I</kbd>                            | Invert Value (Minimum to 0)           |
| <kbd>n</kbd>                            | Normalize (Preserve minimum)          |
| <kbd>N</kbd>                            | Normalize (Minimum to 0)              |
| <kbd>p</kbd>                            | Permute                               |
| <kbd>r</kbd>                            | Randomize                             |
| <kbd>R</kbd>                            | Sparse Randomize                      |
| <kbd>s</kbd>                            | Sort Descending Order                 |
| <kbd>S</kbd>                            | Sort Ascending Order                  |
| <kbd>t</kbd>                            | Subtle Randomize (Random walk)        |
| <kbd>T</kbd>                            | Subtle Randomize (Converge to 0)      |
| <kbd>z</kbd>                            | Undo                                  |
| <kbd>Z</kbd>                            | Redo                                  |
| <kbd>,</kbd> (Comma)                    | Rotate Back                           |
| <kbd>.</kbd> (Period)                   | Rotate Forward                        |
| <kbd>1</kbd>                            | Decrease                              |
| <kbd>2</kbd>-<kbd>9</kbd>               | Decrease 2n-9n                        |

## Caution
Output may change with different sample rate or buffer size.

Output may become loud when following steps are performed.

1. Set some of the `OuterFeed` or `InnerFeed` to close to minimum or maximum.
2. Input signals.
3. Change the value of `OuterFeed` or `InnerFeed` which was set at step 1.

## Block Diagram
If the image is small, use <kbd>Ctrl</kbd> + <kbd>Mouse Wheel</kbd> or "View Image" on right click menu to scale.

Diagram only shows overview. It's not exact implementation.

![](img/latticereverb.svg)

## Parameters
`Base` is value used in both left and right channel. `Base` value determines the character of reverb.

`Offset` is ratio of value between left and right channel. Changing `Offset` spreads reverb to stereo.

```
if (Offset >= 0) {
  valueL = Base
  valueR = Base * (1 - Offset)
}
else {
  valueL = Base * (1 + Offset)
  valueR = Base
}
```

Time

:   Delay time of all-pass filter.

OuterFeed

:   Feedback and feedforward gain of lattice structure.

InnerFeed

:   Feedback and feedforward gain of an all-pass filter.

### Multiplier
Multiplier for `Time`, `OuterFeed`, `InnerFeed`. Useful to shorten or lengthen reverb without changing much of the character.

### Panic!
Pressing `Panic!` button stops reverb output by setting multiplier of `Time`, `OuterFeed`, `InnerFeed` to 0.

Useful to stop sounds in case of blow up.

### Mix
Dry

:   Gain of input signal.

Wet

:   Gain of reverb signal.

### Stereo
Cross

:   Mixing ratio of stereo signal for odd stage in lattice structure.

    If the value is 0, signal from other channel will not be mixed. If the value is 0.5, mixing ratio of current channel and other channel becomes 1:1.

Spread

:   Mid-side (M-S) signal ratio.

    Following equations are used to calculate mid-side signal.

    ```
    mid  = left + right
    side = left - right

    left  = mid - Spread * (mid - side)
    right = mid - Spread * (mid + side)
    ```

### Misc.
Smooth

:    Transition time to change parameter value to current one. Unit is in second.

### Base
![](img/latticereverb.png)

`Base` tab provides controls for common values used in both channels.

Character of reverb is mostly determined by `Base` values.

### Offset
![](img/latticereverb_offset_tab.png)

`Offset` tab provides controls for ratio of value between left and right channel.

Changing values in `Offset` tab spreads reverb to stereo.

### Modulation
![](img/latticereverb_modulation_tab.png)

Time LFO

:   LFO modulation amount to `Time`.

    LFO waveform is noise (uniform pseudo random number). Smoothness of LFO is changed by `Time LFO Cutoff` and `Smooth`.

Time LFO Cutoff

:   Low-pass filter cutoff frequency for LFO.

Lowpass Cutoff

:   Cutoff frequency of low-pass filters placed for each stage of lattice structure.

    Useful to change the brightness of reverb.

## Change Log
- 0.1.3
  - Added check that DSP is initialized or not.
- 0.1.2
  - Added undo/redo to BarBox.
- 0.1.1
  - Added color configuration.
- 0.1.0
  - Initial release.

### Old Versions
- [LatticeReverb 0.1.2 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/L4Reverb0.1.0/LatticeReverb0.1.2.zip)
- [LatticeReverb 0.1.1 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/ColorConfig/LatticeReverb0.1.1.zip)
- [LatticeReverb 0.1.0 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LatticeReverb0.1.0/LatticeReverb0.1.0.zip)

## License
LatticeReverb is licensed under GPLv3. Complete licenses are linked below.

- [https://github.com/ryukau/VSTPlugins/tree/master/License](https://github.com/ryukau/VSTPlugins/tree/master/License)

If the link above doesn't work, please send email to `ryukau@gmail.com`.

### About VST
VST is a trademark of Steinberg Media Technologies GmbH, registered in Europe and other countries.
