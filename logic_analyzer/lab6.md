# Part 06 #

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development

The work for this lab is based on the logic analyser example of the pio.  The major change was changing the clock divider value to get more accurate samples and capturing the right amount of samples to get a better waveform. 

For the testbench , an interface of python loaded rp2040 and apds9960 sensor was used . The circuit was implementing the firefly functionality. 

One of the major observatioon that can be made from the waveform is that , we see a clock frequency only when data is being transferred. 



https://user-images.githubusercontent.com/23244847/202834004-294521aa-17b7-4507-ab45-f1cfe79eb679.mp4

