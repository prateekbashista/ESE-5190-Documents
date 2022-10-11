# ESE 5190 RP2040 Qt Py Board Setup Guide

### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2
- Memory  -  C: 256 Gb(36 GB Left) (Relevant) | D: 1TB

### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development


#### Following Steps need to be followed to successfully get a working board interface and a serial console to view the results

#### A) Setting up the Serial Console - PuTTY

   1) Download PuTTY from putty.org website.
   2) You will come across the following interface after succesfull installation.
   
![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/53a1edeef07725327bd3cc7d03579aea864eac69/putty%20nominal.png)

   3) Enter the following configuration as stated by Adafruit Organisation on the following website regarding seting up other serial consoles than MU REPL
      - Link: https://learn.adafruit.com/welcome-to-circuitpython/advanced-serial-console-on-windows 
      - Serial Line: COM# (# = COM number on which the board is situated in your laptop - Visible in Device Manager)
      - Connection Type: Serial
      - Speed: 115200
      - Save the following session for easy access each time Name: " Qt Py Board" in Saved Sessions Dialog Box

![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/a0ed3d065518e1bae71b322aa95fe7b5ac253d7c/putty%20saved%20state.png)

   5) Click Open    
   6) Your Serial Console is setup.
   
#### B) Setting up the board to work with C/C++

Following softwares were installed to make the board programming compatible ,and we can build the programs so that executable .uf2 files can be generated and uploaded to the for programming.
1) ARM GNU Toolchain  - Compatible development tools for C/C++/ARM languages targeting ARM chipset - Installed "arm-gnu-toolchain-12.2.MPACBTI-Bet1-mingw-w64-i686-arm-none-eabi.exe"
2) CMake - open source software for build automation - Installed 	"cmake-3.24.2-windows-x86_64.msi"
3) Build Tools for Visual Studio 2022 - Development tools for C/C++. It provides us with developer comand prompt thorugh which we can set environment variables etc and launch the VS Code in that configuration.
4) Python - Installed - Version 3.10
5) Git - Version control software - Installed
6) Launch Visual Studio 2022 Developer Command Window

![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/a0ed3d065518e1bae71b322aa95fe7b5ac253d7c/Screenshot%202022-10-10%20200523.png)

7) Run the following Commands in command prompt to acquire pico sdk. This will contain both pico-sdk as well as pico-examples directories.

```
D:\> git clone -b master https://github.com/raspberrypi/pico-sdk.git
D:\> cd pico-sdk
D:\> git submodule update --init
D:\> cd ..
D:\> git clone -b master https://github.com/raspberrypi/pico-examples.git
```

8) Launch VS code thorugh that command prompt using C:> code command.
10) Inside, VS Code , Install CMake tools by Microsoft Corporation.
11) Go to extension settings.

![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/690c17d34e3590003041c7f9ea7a94c7432b8852/Screenshot%202022-10-10%20200852.png)

13) Scroll down to CMake: Configure Environment. Set Item to "PICO_SDK_PATH" and Value to "..\..\pico-sdk"
14) Scorll down to CMake: Generator. Set Value to "NMake Makefiles'.
15) Go back to home. You will get a dialog box in bottom right of the screen asking " would like to configure project "pico-examples" ". CLick Yes.

![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/690c17d34e3590003041c7f9ea7a94c7432b8852/Screenshot%202022-10-10%20201802.png)

17) In compiler choices , select "GCC for arm-none-eabi".
18) After configuration is done, look for a build button on bottom blue bar of the VS Code Window like as follows. Press build.

![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/690c17d34e3590003041c7f9ea7a94c7432b8852/Screenshot%202022-10-10%20202028.png)

20) This Step will build the entire pico_examples directory and save the build files namely .uf2, .elf,.bin to build folder inside the said folder.

#### C) Burning the Program to Microcontroller
1) From the previous labs configuration, the board would still appear to be circuit py. In this configuration , if we put the .uf2 files inside, it will not be programmed as it will still be reading from the .py file. To change that we have to reset the board and go into bootloader mode.
2) Connect the board. Hold BOOT button. While holding, press the RESET button. The board will disconnect from the computer and reconnect.
3) It will appear as RP1-RP2 in your drives sections with 128 MB of memeory. Now the board is ready.

![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/690c17d34e3590003041c7f9ea7a94c7432b8852/Screenshot%202022-10-10%20203111.png)

5) Now go to pico-examples foler\build\hello_world\usb\hello_usb.uf2
6) Copy the above file and drop in the board memory.
7) The board will automatically disapper fromt the list of drives.
8) Board is now running the program. To check, Open PuTTY. select saved states and load the pre saved QTPY board configuration from earlier. If not saved, enter the above mentioned details again. Recheck COM# Port. Click Open.
9) Following ouptut will appear. 


![This is an image](https://github.com/prateekbashista/ESE-5190-Documents/blob/690c17d34e3590003041c7f9ea7a94c7432b8852/output.png)


The board is configured for working with C++ SDK and programmed accordingly without the use of Python or MU Editor.
      



