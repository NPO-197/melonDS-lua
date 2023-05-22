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
`MakeCanvas(int x, int y, int width, int height)` creates a canvas at (0, 0) (the top left of the screen), with width and height of 100 pixels.

`canvas` contains the index of the canavs we just created. `SetCanvas(Canvas canvas)` sets the current canvas so all drawing functions know which canvas to draw to.

`function _Update()` is a special function that if defined in a lua script will be called once every frame. We don't need it in this example, but if you need to run some code, or update what is drawn to the screen every frame, this is the way to do it.

`ClearOverlay()` clears the canvas.

`Text(int x, int y, str text, int rgb, int font_size, str font_family)` draws the given `text` to the selected canvas at coordinate (`x`, `y`) (note that y is the bottom of the canvas and not the top, unlike in bizhawk) with color `rgb`, using `font_size` and `font_family`. QT5 uses a font matching algorithm to find the font family that matches the provided string.

`Flip()` flips between a display buffer and an image buffer. This is to prevent MelonDS from displaying a frame that the lua script hasn't finished drawing yet. **You must call flip after making any changes to the image buffer to be seen.**

### Other Functions

`GetMouse()` Similar to bizhawk's [input.getmouse()](https://tasvideos.org/Bizhawk/LuaFunctions)

~~`NextFrame()` blocks until a signal from the emulator thread that a frame has passed then continues. To help provide compatability with bizhawks implementation, prefer `function _Update()` instead of "while true" loops.~~

`StateSave(str filename)` / `StateLoad(str filename)` Creates / loads a savestate with the given filename.

`Readu8(int address)` / `Readu16(int address)` / `Readu32(int address)` Read unsigned data from RAM in the format specified.

`Reads8(int address)`/ `Reads16(int address)` / `Reads32(int address)` Read signed data from RAM in the format specified.

`MelonPrint(str text)` Print plain text to the console.

`MelonClear()` Clear the console.

`NDSTapDown(x, y)` Tap the screen at coordinate (x, y). Note that y = 0 is the top of the window, not the bottom.

`NDSTapUp()` Stop tapping the screen.

`FrameAdvance()` Advance the emulator by one frame.

`GetRegistersARM7() / GetRegistersARM9()` Get a table containing the values of the ARM7 or ARM9 processor's registers, respectively.

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

Tap the screen, releasing it one frame later.

```Lua
NDSTapDown(150, 300)
FrameAdvance()
NDSTapUp()
MelonPrint("Tapped")
```

Print the registers of both processors to the Lua console.
```Lua
r7 = GetRegistersARM7()
r9 = GetRegistersARM9()

for i = 0, 15 do
    MelonPrint("[ARM7] r" .. i .. ": " .. r7[i])
end

for i = 0, 15 do
    MelonPrint("[ARM9] r" .. i .. ": " .. r9[i])
end
```