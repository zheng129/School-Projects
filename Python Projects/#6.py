# Zheng, Yixing
# CS 122, August, 31, 2016
#
# integer input
# Getting input in meters and converting it to miles, feet, and inches

# Getting input
meters = input("Please enter a measurement in meters: ")

# Converting string to integer
meters = int(meters)

# Calculating the results
miles = meters * 0.00062137
feet = meters * 3.2808
inches = meters * 39.370

# Print out the results
print("The measurement you entered is:", meters)
print(meters, "meter(s) converts to miles is:", miles, "miles")
print(meters, "meter(s) converts to feet is:", feet, "feet")
print(meters, "meter(s) converts to inches is:", inches, "inches")
