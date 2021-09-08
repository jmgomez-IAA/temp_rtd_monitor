#!/bin/python3 

from __future__ import print_function
import serial, time, io, datetime
from serial import Serial

try :
	ser = serial.Serial(
    	port = '/dev/ttyUSB1',\
    	baudrate = 9600,\
    	parity=serial.PARITY_NONE,\
    	stopbits=serial.STOPBITS_ONE,\
    	bytesize=serial.EIGHTBITS,\
    	timeout=0)

#	ser = serial.Serial(
#    	port = '/dev/ttyUSB1',\
#    	baudrate = 9600,\
#    	parity=serial.PARITY_ODD,\
#    	stopbits=serial.STOPBITS_ONE,\
#    	bytesize=serial.SEVENBITS,\
#    	timeout=0)

except serial.SerialException as e:
	print ("Port {} unavailable serial device", tty_port)
	sys.exit()


time.sleep(1)

if ser.isOpen():

	print("Connected to: " + ser.portstr)
	
	#flush input buffer, discarding all its contents
	ser.flushInput()
    #flush output buffer
	ser.flushOutput()

	while True:
#		# NB: for PySerial v3.0 or later, use property `in_waiting` instead of function `inWaiting()` below!
		if (ser.inWaiting()>0): #if incoming bytes are waiting to be read from the serial input buffer
			in_bin = ser.read(ser.inWaiting()) #read the bytes,  format binary array
			#print(in_bin, end='\t') 		
			#print(in_bin)
			print(in_bin.decode("utf-8")[0:][:-5])
			#print(in_bin.decode('Ascii'))			
		
		time.sleep(1)



	ser.close()