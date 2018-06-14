##
# Zheng, Yixing
# September 12, 2016
#
# A program that calculates and prints the force on a pair of charged particles
##

# Import pi from math function 
from math import pi

# Define data field
E = 8.854 * 10 ** -12

# Get input
q1 = input("Please enter Q1 coulombs: ")
q2 = input("Please enter Q1 coulombs: ")
meters = input("Please enter y meters: ")

# Convert str to float
q1 = float(q1)
q2 = float(q2)
meters = float(meters)

# Calculate the force
force = ((q1 * q2) / (4 * pi * E * meters ** 2))

# Print out results
print("The force is", round(force, 5))
