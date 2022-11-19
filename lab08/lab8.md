# Part 08

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development

The major functionality of part 08 was to make manual communication with APDS9960 sensor. To do so , register level invocation to apds9960 sensor was made. The objective was to switch on the 
board, the ALS engine and the proximity sensor engine. 

Steps:

1) Data sheet was used to get the registers that are need to switch on the sensor effectively and to switch on each individual components as well.
2) Registers were declared in a separate header file.
3) Appropriate values to the register was passed as to estabilish the proper functionality.
4) The data recieved was read, and values of the RED, green and blue was printed on the console as well the proximity sensor.




https://user-images.githubusercontent.com/23244847/202835706-ae06886f-9682-4008-8a0c-c9c791477194.mp4

