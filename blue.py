import time
import serial
ser = serial.Serial('/dev/ttyACM0',9600)
time.sleep(1)
ser.write('b')
