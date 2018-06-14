##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that reads in two float numbers and tests whether they are the same
# up to two decimal places
##

# Get input
float1 = float(input("Enter a floating-point number: "))
float2 = float(input("Enter a floating-point number: "))

# Round two floats to two decimal places
float1 = round(float1, 2)
float2 = round(float2, 2)

# Test if they the same
if float1 == float2:
    print("They are the same up to two decimal places.")
else:
    print("They are different.")
