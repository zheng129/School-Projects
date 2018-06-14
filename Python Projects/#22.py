##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that reads integer and displays astericks to fill a diamond shape
##

# Defind data fields
astericks = "*"
spaces = " "
# Get input
n = int(input("Enter an integer: "))

# Display the diamond
for i in range(n - 1):
    print((n - i) * spaces + (2*i + 1) * astericks)
for j in range(n - 1, -1, -1):
    print((n - j) * spaces + (2*j + 1) * astericks)
