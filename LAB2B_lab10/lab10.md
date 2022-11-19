### LAB 10 ###

The LAB 10 asks us to implement a experiment protoboard as well integrate the pio_sequencer from before to create a fully functional product. The proposal board previously mentioned 
is a simple game that lights the led of the user whosoever pushes their button first. The major challenge in this part was integrate the ful functionality of the game using pio SMs. For this task
3 state machines were used. 1 to toggle the led and the rest 2 for each of the button.

Next task was to integrate the whole board with pio sequencer: 
1) For this, a simple conditional was declared that invoked a user defined function.
2) This user defined function containes the pio enabled board from the previous.
3) Now , along with rest of the board, the "g" key press invokes the board mode, which gave the control to the custom board leds and buttons.
