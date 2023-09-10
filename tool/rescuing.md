---
sort: 2
---
## Device no longer shows up or pushed bad config

The tool has the ability to detect devices in firmware update mode, and offer to fix them back up. For all supported arduinos except the Uno, you can just short reset to GND **twice** to get to this mode and it will stay in firmware update mode for a few seconds. As long as the config tool is open, this should be enough time to reprogram the device. There are a few differences to this (Uno and Pico) as shown below, as well as a guide for if this isn't working for a Pro Micro. (A.K.A. - a bad config was pushed)

# Arduino Uno 
You need to short the following reset pins to get into firmware update mode:

<img src="../assets/images/ArduinoUnoDFU.svg" width="50%">

# Pi Pico
Press the BOOTSEL button and hold it while you connect the other end of the micro USB cable to your computer:

<img src="../assets/images/pico-bootsel.png" width="50%">

# Pro Micro 

Short the rst pin to ground twice in quick succession, and the tool will detect the pro micro in bootloader mode

<img src="../assets/images/promicrorst.png" width="50%">

Note that when this is done, you only get around 8 seconds to reprogram the guitar, so you will need to be quick and its best to open the config tool first.