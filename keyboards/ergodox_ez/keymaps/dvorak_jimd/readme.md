# ErgoDox EZ Default Configuration

## Changelog

* Dec 2016:
  * Added LED keys
  * Refreshed layout graphic, comes from http://configure.ergodox-ez.com now.
* Sep 22, 2016:
  * Created a new key in layer 1 (bottom-corner key) that resets the EEPROM.
* Feb 2, 2016 (V1.1): 
  * Made the right-hand quote key double as Cmd/Win on hold. So you get ' when you tap it, " when you tap it with Shift, and Cmd or Win when you hold it. You can then use it as a modifier, or just press and hold it for a moment (and then let go) to send a single Cmd or Win keystroke (handy for opening the Start menu on Windows).

This is what we ship with out of the factory. :) The image says it all:

![Default](https://i.imgur.com/Be53jH7.png)

* Sep 2020:
  * Moved crtl and alt keys around
  * put a dedicated Win key below ctrl
  * shift is holding esc
  * moved brackets layer shift to right shift location
  * In game mode
    * moved the shifted numbers to the bottom row, for single key press access
    * moved alt to righthand, leftmost bottom row
    
## usage reminder

1. Open Mingw64 terminal
2. From root of qmk_firmware run `qmk compile` or `qmk flash` to compile and flash
