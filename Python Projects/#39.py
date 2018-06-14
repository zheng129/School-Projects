##
# Zheng, Yixing
# September 12, 2016
#
# A program that calculates and prints the dew point value
##

# Import log function
from math import log

# Define data field
A = 17.27
B = 237.7

# Get input
relativeHumidity = float(input("Please enter relative humidity (between 0 and 1): "))
if relativeHumidity > 1:
    print("The relative humidity must between 0 and 1")
    exit()
elif relativeHumidity < 0:
    print("The relative humidity must between 0 and 1")
    exit()
    
temperature = input("Please enter temperature: ")

# Convert str to float
temperature = float(temperature)

# Calculate the dew point value
dewPointValue = (B * ((A * temperature / B + temperature) + log(relativeHumidity))) / (A - ((A * temperature / B + temperature) + log(relativeHumidity)))

# Print out the result
print("The dew point value is", dewPointValue)
