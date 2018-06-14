##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that reads a month and print out the days of the month
##

# Define data field
longMonth = 31
shortMonth = 30

# Get input
month = int(input("Enter a month: "))

# Calculate the result
if month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12:
    print("{:d} {:s}".format(longMonth, "days"))
elif month == 2:
    print("February has 28 days in a common year and 29 days in Leap Years.")
else:
    print("{:d} {:s}".format(shortMonth, "days"))
