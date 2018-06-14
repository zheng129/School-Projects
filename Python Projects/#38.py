##
# Zheng, Yixing
# September 12, 2016
#
# A program that calculates the total reistence
##

# Get input
resistor1 = input("Enter value R1: ")
resistor2 = input("Enter value R2: ")
resistor3 = input("Enter value R3: ")

# Convert str to float
resistor1 = float(resistor1)
resistor2 = float(resistor2)
resistor3 = float(resistor3)

# Calculate equivelent
equivalent = ((resistor2 * resistor3) / (resistor2 + resistor3)) + resistor1
equivalent = round(equivalent, 3)

# Print out result
print("The total equivalent is", equivalent)
