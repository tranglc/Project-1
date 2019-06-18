#!/usr/bin/env python3
import datetime as dt
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import bluetooth
import time


#BLE Comunication
bd_addr ="00:21:13:05:E1:45"
port = 1

sock=bluetooth.BluetoothSocket(bluetooth.RFCOMM )
sock.connect((bd_addr,port))

# Create figure for plotting
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
xs = []
ys = []
# This function is called periodically from FuncAnimation
def animate(i, xs, ys):

    # Read Lux from BH1750
	time.sleep(.02)
	sock.send("e")
	time.sleep(.02)
	lux=int(sock.recv(10))
	time.sleep(.1)
	print(lux)

	# Add x and y to lists
	xs.append(dt.datetime.now().strftime('%H:%M:%S,%m/%d/%Y'))
	ys.append(lux)

	# Limit x and y lists to 20 items
	xs = xs[-20:]
	ys = ys[-20:]

	# Draw x and y lists
	ax.clear()
	ax.plot(xs, ys,'-o',alpha=0.8)
	# Format plot
	plt.style.use('ggplot')
	plt.xticks(rotation=45, ha='right')
	plt.subplots_adjust(bottom=0.30)
	plt.title('Light Intensity:'+' '+str(lux)+' (lux) at '+dt.datetime.now().strftime('%H:%M:%S,%m/%d/%Y'))
	plt.ylabel('Light Intensity (LUX)')

# Set up plot to call animate() function periodically
ani = animation.FuncAnimation(fig, animate, fargs=(xs, ys), interval=1000)
plt.show()
