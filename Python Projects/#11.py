# Zheng, Yixing
# CS 122, August, 31, 2016
#
# Integer input
# Getting input in the numbers of gallons of gas in the tank
# And the fuel efficiency in miles per gallon
# And the price of gas per gallon
# And then print the cost per 100 miles and how far the car can go with the gas in tank

# Getting input
gasInTank = input("Please enter the number of gallons of gas remained in the tank: ")
milesPerGallon = input("Please enter the fuel efficiency in miles per gallon: ")
gasPrice = input("Please enter the price of gas per gallon: ")

# Convert strings to integers/float for gas price
gasInTank = int(gasInTank)
milesPerGallon = int(milesPerGallon)
gasPrice = float(gasPrice)

# Calculating the results
# Could use a optimization on limiting the decimals to only two for cost
cost = 100 / milesPerGallon * gasPrice
milesCanDrive = gasInTank * milesPerGallon

# Print out the results
print("For driving 100 miles, the cost based on current situation is:", cost, "dollars")
print("The gas remined in your tank is:", gasInTank, "gallons,", "and it will support you to drive:", milesCanDrive, "miles")

