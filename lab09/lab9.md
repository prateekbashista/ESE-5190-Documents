# Part 09

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development


For this implementation, the major functionality according to us is getting the colour and brightness data from the apds9960 sensor and transalting it to LED values 
on the NEOPIXEL LED. The data recieved from the sensor and passed on to the led differ and thus to get proper value, the values in 8 different registers are appended and 
bit shifted appropirately to implement fucntionality.

Steps: 
1) The sensor and ALS engine is switched on and communication is estabilished using the i2c.
2) 1 colour data is recieved from 8 different registers that give low and high value of each of the colour and the clear channel which acts the brightness gauge.
3) The data is reappropriated and mapped from 0 to 255. 
4) The data is appended together and put in GRB format and sent to the NEOPIXEL led.




https://user-images.githubusercontent.com/23244847/202836333-0e006836-a055-43d0-86c5-a31f79909ba2.mp4

