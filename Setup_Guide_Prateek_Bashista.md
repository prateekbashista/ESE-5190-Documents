# ESE 5190 RP2040 Qt Py Board Setup Guide

#### System Details
- Processor - AMD Ryzen 5 4600 H
- RAM - 16 GB
- Operating System : Windows 11 Version 22H2
- Memory  -  C: 256 Gb(36 GB Left) (Relevant) | D: 1TB

#### References : 
1) Getting Started with PICO 
2) C/C++ SDK Development


Folowing Steps need to be followed to successfully get a working board interface and a serial console to view the results
A) Setting up the Serial Console - PuTTY

   1) Download PuTTY from putty.org website.
   2) You will come across the following interface after succesfull installation.
   --------------------------Add image -------------------------------\
   3) Enter the following configuration as stated by Adafruit Organisation on the following website regarding seting up other serial consoles than MU REPL
      Link: https://learn.adafruit.com/welcome-to-circuitpython/advanced-serial-console-on-windows 
      Serial Line: COM# (# = COM number on which the board is situated in your laptop - Visible in Device Manager)
      Connection Type: Serial
      Speed: 115200
      Save the following session for easy access each time Name: " Qt Py Board" in Saved Sessions Dialog Box
   4) Click Open
      Folowing Screen Should Appear:
      ---------------------------------------------Insert Image of Console-------------------\
      
   5) Your Serial Console is setup.
   
B) Setting up the board to work with C/C++

   1) 
      



