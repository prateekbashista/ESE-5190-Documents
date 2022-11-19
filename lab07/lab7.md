### LAB 07 ###

In this lab, the main objective was to integrate the boot button functionality through the PIO module. This is done by passing the boot button pin through the state machine declarations. Only simple change is declaring the new state machine and writing the adjoining assembly code in .pio file.

Following are the commands: 
```
PIO pio = pio0;
    int sm = 0;
    int sm1 = 1;
    uint offset = pio_add_program(pio, &ws2812_program);
    uint offset1 = pio_add_program(pio, &bootpin_program);


    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);
    bootpin_program_init(pio,sm1,offset1,boot);
    
```

Assembly code: 

```
.program bootpin

set pindirs, 0

.wrap_target
lable: 
    in pins, 1
    push
    jmp lable
.wrap
```
