##
# Zheng, Yixing
# September 12, 2016
#
# A program that displays a smile face which somewhat looks like me after doing
# calculate homework
##

# Import graphics window function from graphics 
from graphics import GraphicsWindow

# Created a window and a canvas
win = GraphicsWindow()
canvas = win.canvas()

# Set title 
win.setTitle('I Love CS 122')

# Adjust the height and width of the window as well as the canvas
height = canvas.height() * 2 / 3
width = canvas.width()

# Set canvas outline and color
canvas.setOutline('black')
canvas.setFill(255, 255, 0)

# Adjust the position of the canvas and draw an oval
x = width / 2 - height / 2
y = canvas.height() / 2 - height / 2
canvas.drawOval(x, y, height, height)

# Adjust the oval color and position
canvas.setFill('white')
canvas.drawOval(x + height / 5, y + height / 5, height / 5, height / 3)
canvas.drawOval(x + 3 * height / 5, y + height / 5, height / 5, height / 3)
canvas.setFill('black')
canvas.drawOval(x + height / 4, y + height / 4, height / 10, height / 10)
canvas.drawOval(x + 2.58 * height / 4, y + height / 4, height / 10, height / 10)

# Draw an arc
canvas.setFill("red")
canvas.drawArc(x + 40, y + height/ 4, height - 80, 0, -180)

# Make the windows wait so it stays on the screen
win.wait()
