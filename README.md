MouseTo
==========
Library for [Arduino](https://arduino.cc) Leonardo/Micro/Pro Micro for moving the mouse pointer to absolute screen coordinates.


<a id="installation"></a>
#### Installation
- Download the most recent version of MouseTo here: https://github.com/per1234/MouseTo/archive/master.zip
- Using Arduino IDE 1.0.x:
  - **Sketch > Import Library... > Add Library... >** select the downloaded file **> Open**
- Using Arduino IDE 1.5+:
  - **Sketch > Include Library > Add ZIP Library... >** select the downloaded file **> Open**
- Running the example sketches:
  - **File > Examples > MouseTo**
  - Upload to device


<a id="usage"></a>
#### Usage
See the example sketches at **File > Examples > MouseTo** for demonstration of library usage.

##### `#include <MouseTo.h>`
Allow access to the functions of the MouseTo library.

##### `MouseTo.setTarget(targetX, targetY[, homeFirst])`
Move mouse pointer to absolute screen coordinates. Note that screen coordinates start from the upper left corner.
- Parameter: **targetX** - X screen coordinate to move to.
  - Type: int
- Parameter: **targetY** - Y screen coordinate to move to.
  - Type: int
- Parameter(optional): **homeFirst** - Whether to home the mouse pointer before moving to the target. At a minimum the pointer must be homed before the first use of MouseTo in your code. If homing is not done after that time the accuracy of the mouse pointer movements might suffer, for example if the regular mouse connected to the computer is moved. The default value is `true`.
  - Type: boolean
- Returns: none

##### `MouseTo.getTargetX()`
Get the last X coordinate set by `MouseTo.setTarget()`.
- Returns: Target X coordinate.
  - Type: int

##### `MouseTo.getTargetY()`
Get the last Y coordinate set by `MouseTo.setTarget()`.
- Returns: Target Y coordinate.
  - Type: int

##### `MouseTo.move()`
Move mouse pointer to the target coordinates. Multiple calls to `MouseTo.move()` may be required before the target coordinates are reached.
- Returns: `true` = target coordinates reached, `false` = target coordinates not yet reached
  - Type: boolean

##### `MouseTo.setScreenResolution(x, y)`
When `MouseTo.move()` homes it assumes that the mouse pointer is at the lower right corner. The default values are set to home correctly even with very high resolution(4K UHD). By setting the MouseTo screen resolution value to your actual resolution you can reduce the time `MouseTo.move()` takes to reach the target coordinates.
- Parameter: **x** - X screen resolution. The default value is 3840.
  - Type: int
- Parameter: **y** - Y screen coordinate to move to. The default value is 2160.
  - Type: int
- Returns: none

##### `MouseTo.getScreenResolutionX()`
- Returns: X screen resolution.
  - Type: int

##### `MouseTo.getScreenResolutionY()`
- Returns: Y screen resolution.
  - Type: int

##### `MouseTo.setCorrectionFactor(correctionFactorInput)`
The screen distance moved is different from the distance arguments passed to `Mouse.move()`. In order for `MouseTo.move()` coordinates to correspond with the screen coordinates you must set a correction factor. The correct value can be determined with **File > Examples > MouseTo > BasicUsage**.
- Parameter: **correctionFactorInput** - The default value is 1(no correction).
  - Type: float
- Returns: none

##### `MouseTo.getCorrectionFactor()`
- Returns: Correction factor.
  - Type: float

##### `MouseTo.setMaxJump(maxJumpDistanceInput)`
`Mouse.move()` only allows a maximum move of 127 pixels in each axis so longer mouse pointer movements require multiple calls. Smaller values will require more calls to `MouseTo.move()` before the target coordinates are reached, larger values may lead to less accuracy. You must recalculate the correction factor whenever this is changed.
- Parameter: **maxJumpDistanceInput** - The maximum distance(x and y) the mouse pointer can move on each call to `MouseTo.move()`. Allowable values are 1-127. The default value is 10.
  - Type: int8_t
- Returns: none

##### `MouseTo.getMaxJump()`
- Returns: Maximum jump distance.
  - Type: int8_t

##### `MouseTo.home()`
Re-home the mouse before continuing to the target coordinates. This is useful for cases when `MouseTo.move()` completion was delayed long enough that the mouse pointer may have been moved.
- Returns: none


<a id="process"></a>
#### `MouseTo.move()` Process
- Each call of `MouseTo.move()` moves the pointer up to the maximum jump distance(set by `MouseTo.setMaxJump()`) in the x and y axes.
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


#### Contributing
Pull requests or issue reports are welcome! Please see the [contribution rules](https://github.com/per1234/MouseTo/blob/master/CONTRIBUTING.md) for instructions.
