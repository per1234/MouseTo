MouseTo
==========
Library for [Arduino](https://arduino.cc) Leonardo/Micro for moving the mouse pointer to absolute screen coordinates.


<a id="installation"></a>
#### Installation
- Download the most recent version of MouseTo here: https://github.com/per1234/MouseTo/archive/master.zip
- Using Arduino IDE 1.0.x:
  - Sketch > Import Library... > Add Library... > select the downloaded file > Open
- Using Arduino IDE 1.5+:
  - Sketch > Include Library > Add ZIP Library... > select the downloaded file > Open
- Running the example sketches:
  - **File > Examples > MouseTo**
  - Upload to device


<a id="usage"></a>
#### Usage
See the example sketches at **File > Examples > MouseTo** for demonstration of library usage.

**`MouseTo.moveTo(targetX, targetY)`** - Move mouse pointer to absolute screen coordinates. Note that screen coordinates start from the upper left corner.
- Parameter: **targetX** - X screen coordinate to move to.
  - Type: int
- Parameter: **targetY** - Y screen coordinate to move to.
  - Type: int
- Returns: `true` = target coordinates reached, `false` = target coordinates not yet reached
  - Type: boolean

**`MouseTo.setScreenResolution(x, y)`** - When `moveTo()` homes it assumes that the mouse pointer is at the lower right corner. The default values are set to home even with very high resolution(4K UHD). By setting the MouseTo screen resolution value to your actual resolution you can reduce the time `moveTo()` takes to reach the target coordinates.
- Parameter: **x** - X screen resolution. The default value is 3840.
  - Type: int
- Parameter: **y** - Y screen coordinate to move to. The default value is 2160.
  - Type: int
- Returns: none

**`MouseTo.getScreenResolutionX()`**
- Returns: X screen resolution.
  - Type: int

**`MouseTo.getScreenResolutionY()`**
- Returns: Y screen resolution.
  - Type: int

**`MouseTo.setCorrectionFactor(correctionFactorInput)`** - For some reason the screen distance moved is different from the distance arguments passed to `Mouse.move()`. In order for `moveTo()` coordinates to correspond with the screen coordinates you must set a correction factor. The correct value can be determined with **File > Examples > MouseTo > BasicUsage**.
- Parameter: **correctionFactorInput** - The default value is 1(no correction).
  - Type: float
- Returns: none

**`MouseTo.getCorrectionFactor()`**
- Returns: Correction factor.
  - Type: float

**`MouseTo.setMaxJump(maxJumpDistanceInput)`** - `Mouse.move()` only allows a maximum move of 127 pixels in each axis so longer mouse pointer movements require multiple calls. You will probably not need to change this from the default value but if `moveTo()` is not consistently reaching the target coordinates you could try other `maxJumpDistanceInput` values. You muist recalculate the correction factor whenever this is changed.
- Parameter: **maxJumpDistanceInput** - The maximum distance(x and y) the mouse pointer can move on each call to `moveTo()`. Allowable values are 1-127. The default value is 127, the maximum jump distance.
  - Type: int8_t
- Returns: none

**`MouseTo.getMaxJump()`**
- Returns: Maximum jump distance.
  - Type: int8_t


<a id="process"></a>
#### `MouseTo.moveTo()` Process
- Each call of `MouseTo.moveTo()` moves the pointer up to the maximum jump distance(set by `MouseTo.setMaxJump()`) in the x and y axes.
- Home mouse pointer to (0, 0).
- Once the mouse pointer is homed start moving to the target coordinates.
- Once the target coordinates are reached return `true`.


#### Help Wanted
If you can recommend any free programs, especially non-Windows, which display the mouse pointer position please [submit an issue](https://github.com/per1234/MouseTo/issues/new).


<a id="alternatives"></a>
#### Alternatives
- https://github.com/NicoHood/HID/blob/master/examples/Mouse/AbsoluteMouse/AbsoluteMouse.ino
- https://github.com/nospam2000/Arduino/commit/7b77d1e84d7b80819f049e5fd6e7bafa0d06521f#diff-0dd97502971c8a55546092b93abd32caR349
- https://github.com/keyboardio/Arduino/commit/a520873aba7f2c99eda6c9b1979df170939d9f68
- http://forum.arduino.cc/index.php?topic=94140.0
- https://www.pjrc.com/teensy/td_mouse.html

