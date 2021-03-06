Serial Port on Linux
====================
If you don't feel like recompiling the kernel, this is a quick workaround
for viewing serial output on Linux:
 - program the launchpad
 - unplug it
 - press and hold the reset button
 - plug launchpad back in
 - wait for permissions on /dev/ttyACM0 to settle
 - run "minicom -b 9600 -D /dev/ttyACM0"
 - release reset button

If you're feeling brave, have a look at these posts:

 - [RF24 with msp430...](http://programmablehardware.blogspot.ie/2014/07/rf24-with-msp430-revisited.html)
 - [Fix a Linux Kernel bug...](https://orenkishon.wordpress.com/2014/06/29/msp430-ez430-rf2500-linux-support-guide/)
