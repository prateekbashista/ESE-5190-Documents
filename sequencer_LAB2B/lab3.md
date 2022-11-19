# Part 03

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development


For this lab, the task was to implement a record functionality within the RP2040 module. This was successfully carried out as well as additional python functionality was added to store the input in a file. Also , 2 macros were added to the implementation.

The function of these macros is defined as follows: 

1) 'b' -  To go into the boot button pressed record mode.
2) 'p' - to play the recording.

Python file was used to implement the console functionality, as well as record the readings into a file.

In the file we can see that, as 'b' is invoked, the read fucntionality is used, and it record boot presses. AS we press the 'p' key , it invokes the macro, and plays the recording stored on our device. This video shows the full functionality of the board, from intial 2 macro implementation to final board intergration.

https://user-images.githubusercontent.com/23244847/202836009-6ce3bbf6-7148-42ac-8c48-86822dd7b02d.mp4

