# capslock
This software is useful when you usually put your laptop to sleep by closing the lid, but there are times when you don’t want it to go to sleep even for a short trip, and it’s inconvenient to carry the laptop without closing the lid.

If you turn the CAPS LOCK key ON before closing the lid, the laptop will not go to sleep even if you close the lid.
When you turn the CAPS LOCK key back OFF, the laptop will go to sleep when you close the lid.

This software runs different batch files depending on whether the CAPS lock key is ON or OFF.
When it’s ON, CapsLock-ON.bat is executed.
When it’s OFF, CapsLock-OFF.bat is executed.

Each file contains commands to change the behavior when the laptop lid is closed.

CapsLock-ON.bat
  This setting disables the action that occurs when the laptop lid is closed (prevents the laptop from going to sleep).
CapsLock-OFF.bat
  This setting enables the action that occurs when the laptop lid is closed (sends the laptop to sleep).

You can freely edit the contents of each batch file, so you can write and use the commands you want to execute when the CAPS lock key is turned ON or OFF.


