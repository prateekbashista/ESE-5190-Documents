import time, os, re, urllib
import msvcrt
import sys      # needed to end the program
import serial   # use pyserial to send commands to arduino
from datetime import datetime


PORT='COM5'     # This port will need to be adjusted to match your installation
BAUDRATE = 115200
TARGET = r"C:\Users\Prateek\Desktop\inout.txt"
ser = serial.Serial(PORT, 115200,timeout=10)
time.sleep(3)

while True:

    x = msvcrt.kbhit()
    ret = "" 
    if x:
        ret = ord(msvcrt.getch())
        x = chr(ret)

    print("User input:", x)
    #x = input()

    if x == 'b':
        print("recording b...")
        x = bytes(x, 'utf-8')
        ser.write(x)
        t=ser.readline()
        print(t)
        print("Waiting until t = 1")
        while t!=b'1\r\n':
            t=ser.readline()
            print(t)

        while t == b'1\r\n':
            print("Recording ones")
            txtfile=open(TARGET,"a")
            bit1 = ser.readline()
            print(bit1)
            txtfile.write(bit1.decode("utf-8"))
            txtfile.close()
            t=ser.readline()
            #time.sleep(0.05)

    elif x == 'p':
        x = bytes(x, 'utf-8')
        ser.write(x)
  
    elif x == 's':
        x = bytes(x, 'utf-8')
        ser.write(x)
    elif x == 'f':
        x = bytes(x, 'utf-8')
        ser.write(x)
    
    elif x == 'g':
        x = bytes(x, 'utf-8')
        ser.write(x)
    else:
        print("in else")
        bit0 = ser.readline()
        txtfile=open(TARGET,"a")
        txtfile.write(bit0.decode("utf-8"))
        txtfile.close()
        time.sleep(0.04)
        
time.sleep(0.1)           


            

