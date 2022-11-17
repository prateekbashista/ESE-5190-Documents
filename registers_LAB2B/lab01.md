# Part 01 : Registers

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development

### Following steps were taken to toggle the Neopixel LED through the Boot button
1) A structure is declared which lets us create a custon datatype to store the state of the boot button. following structure declares the 
```
typedef struct{
    uint32_t stat;
}boot_stat;
```
2) When button is pressed , the register toggles the value obj.stat. 
3) This value is passed to the if-else conditional statement.
4) The LED lights up when the button is pressed through the 
