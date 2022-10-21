# ESE 5190 Board Proposal and LED Function Test

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development


#### LED Function

1) Objective : Make Relevant LED Blink based on key mapped to the colour. For our circuit character 'r' is mapped to red and 'b' is mapped to blue.
2) Circuit Diagram:

![lab-2b-circuit](https://user-images.githubusercontent.com/23244847/197116735-ea21a7ba-a966-4016-b69e-690f608dcaa9.png)

3) Following code snippet elaborates on the logic : We are getting the character input from the user, based on wether its 'r' , 'b' or other char, we switch on red or blue led or kee the led off.

```
 while (true) {
        char c = getchar_timeout_us(5000);
        if(c=='r'){
        printf("Red On!!\n");
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        }
       else if(c=='b'){
        printf("Blue on!!\n");
        gpio_put(LED_PIN2, 1);
        sleep_ms(250);
        gpio_put(LED_PIN2, 0);
        sleep_ms(250); 
        }
    }
```
4) Video Demonstration



https://user-images.githubusercontent.com/23244847/197117846-75629789-27d3-4636-8afc-0967eac939e2.mp4



### BOARD PROPOSAL

From the above circuit implementation, I notice that the there is some lag between implementation of code of if condition, when both the buttons are pressed together. This can be developed into a mini game.

Rules of the game :
1) First person to press the button wins the point. 
2) First person to reach 3 points with the match. 

Estimated Circuit Diagram:

![lab2b-board-proposal](https://user-images.githubusercontent.com/23244847/197123995-1cebceab-6340-4f40-b3cf-60121fe0fdec.png)

Parts Required: 
1) 6 LEDS  - 3 Red & 3 Blue
2) Jumper Wires
3) Resistors
4) Push Buttons



