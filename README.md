# iRobot (Roomba) Virtual Wall for ATTiny13

Just a bit of code used for a simple DIY virtual wall for the iRobot.

Used the ATTiny13 because, well, it's tiny.. and I had a few laying around.  
The virtual wall device is nothing more than an IR led that oscillates at 38 KHz while it's "on" and switches between "on" and "off" every 1 milliseconds.

I've used an Arduino Uno dev board to burn the bootloader on the ATTiny13 and program the chip (see: https://bit.ly/2YhCD8U)  
Make sure its internal clock is set to 9.6 MHz otherwise the frequency of the IR led won't be 38 KHz.

