# Part 05 : Oscilloscope

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development

### Following steps were followed to obtain the I2C trace
1) The connection is made between the rp2040 microcontroller and APDS9960 sensor. The readings is taken from the I2C pins of the APDS9960. 
![lab2b_part5](https://user-images.githubusercontent.com/23244847/200086779-c38a05cd-15aa-45f3-8261-61d4e5f9dad8.png)

2) The code is run to activate the I2C communication between the board and sensor.
3) The readings are taken using 2 methods. The normal probe readings and Logic Analyzer Probe Cable. The readings were taken by probing the SCL, SDA and GND pins of the APDS9960 sensor.

A) Probe Cable
While probe gives readings, it does incorporated noise in it but has better resolution as well regarding the signals. Thus, it is better suited for analog signals. Following results obtained can be seen.
       
![scope_0](https://user-images.githubusercontent.com/23244847/200087927-df6bc93b-1107-44ef-930e-0031545f9545.png)
![scope_1](https://user-images.githubusercontent.com/23244847/200088119-da9be578-a129-45ea-bcb9-6624f0b398a4.png)

B) Logic Analyzer Probe Connector
Logic Analyzer probe is better suited to measure the digtal signals as it filters 1) Filters out the noise 2) Have multiple probe to observe more signals. Following results were obtained: 

![scope_3](https://user-images.githubusercontent.com/23244847/200088433-7867e978-9a74-4c21-af83-c66c4b38b816.png)
