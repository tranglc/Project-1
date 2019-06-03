#!/usr/bin/env python3

import bluetooth
import time

#BLE Comunication
bd_addr ="00:21:13:05:E1:45"
port = 1
sock=bluetooth.BluetoothSocket(bluetooth.RFCOMM )
sock.connect((bd_addr,port))

sock.send("a")
time.sleep(.20)
sock.send("b")
time.sleep(.20)

# Display Lux
while True:
	sock.send("d")
	time.sleep(.02)
	sock.send("e")
	time.sleep(.02)
	lux=str(sock.recv(10))
	time.sleep(.1)
	print("Gia tri Lux: " + lux[2:8])