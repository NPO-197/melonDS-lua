# Lua Script Overview
### Disclaimer 
Note this feature is still a work in progress. All lua functions and features are subject to change.
## Hello World Example
Quick example of a lua script that when run, will display "Hello World!" on screen.

```Lua
canvas = MakeCanvas(0,0,100,100)
SetCanvas(canvas)
function _Update()
    ClearOverlay()
    Text(0,10,"Hello World!",0xffffff,9,"Franklin Gothic Medium")
    Flip()
end
```
First we create a canvas at 0,0 (the top left of the screen), with width and height of 100 pixels.

`canvas` contains the index of the canavs we just created. `SetCanvas(canvas)` sets the current canavs so all drawing functions know which canvas to draw to.

`function _Update()` is a special function that if defined in a lua script will be called once every frame, we don't need it in this example, but if you need to run some code, or update what is drawn to the screen every frame, this is the way to do it.

`ClearOverlay()` clears the canavs

`Text()` draws the text to the selected canvas at a x,y (y is the bottom of the text not the top unlike in bizhawk) with rgb color font size and font family, qt5 uses a font matching algorithm to find the font family that matches the font provided. 

`Flip()` flips between a display buffer and an image buffer, this is to prevent MelonDS from displaying a frame that the lua script hasn't finished drawing yet, **you must call flip after making any changes to the image buffer to be seen.**

### Other Functions

`GetMouse()` similar to bizhawk's [input.getmouse()](https://tasvideos.org/Bizhawk/LuaFunctions)

~~`NextFrame()` blocks until a signal from the emulator thread that a frame has passed then continues. To help provide compatability with bizhawks implementation, prefer `function _Update()` instead of "while true" loops.~~

`StateSave()` / `StateLoad()` creates / loads a savestate from the given filename.

`Readu8(int address)` / `Readu16` / `Readu32` read unsigned data from RAM in format specified.
`Reads8(int address)`/ `Reads16` / `Reads32` read signed data from RAM in format specified

`MelonPrint` print plain text to console

`MelonClear` clear console 

## Other Examples

TODO: add more examples.

Report Mouse pos.
```Lua
SetCanvas(MakeCanvas(0,0,100,100))
function _Update()
    ClearOverlay()
    Pos=""..GetMouse().X..","..GetMouse().Y
    Text(0,10,"Pos:"..Pos,0xffffff,9,"Franklin Gothic Medium")
    Flip()
end

```