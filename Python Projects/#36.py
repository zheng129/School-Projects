##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that draws a pie chart of the areas of all continents
##ssss

# Import database
from matplotlib import pyplot

# Plot data on the graph
labels = "Asia", "Africa", "North America", "South America", "Oceania", "Antarctica", "Europe"
sizes = [16920000, 11730000, 9460000, 6890000, 3478200, 5300000, 3930000]
colors = ["white", "yellowgreen", "gold", "lightcoral", "lightskyblue", "red", "pink"]
explode = [0.1, 0, 0, 0, 0, 0, 0]

# Draw the pir chart
pyplot.pie(sizes, explode = explode, labels = labels, colors = colors,
           autopct = "%s%s"% ("mi",chr(178)), shadow = True, startangle = 90)
# Do not know how to show numbers in autopct
# It asks for a number instead of a list

# set aspect ratio to be equal so that pir is drawn as a circle
pyplot.axis("equal")

# Set title of the figure
pyplot.title("Area of continents")

# Display the graph
pyplot.show()
