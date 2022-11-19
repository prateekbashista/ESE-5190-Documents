# Part 04

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development

For this functionality the major difference from part 3 is increasing the time between each of the LED invocations. A simple delay condition is used in this implementation to effectively make the led burn brighter or dimmer based on the user defined macros. 

As a result of this, 2 modes were added to the previous implementation, 

1) 'f' : - To toggle the led fast. Passes throught the stored input fast.
2) 's' : - to toggle the led slow. Passes through the stored input slowly.


As we see further in the video, we test the fucntionality of 'f ' and 's' macros. This replays the recording we took in slow and fast mode. This implemntation is fully accessible using python.




https://user-images.githubusercontent.com/23244847/202836119-70368bf0-b93f-4e2d-a8e6-c4f44046242e.mp4

