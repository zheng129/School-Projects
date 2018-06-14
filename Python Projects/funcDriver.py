##
# Zheng, Yixing
# October 23, 2016
# CS 122
#
# The driver program for funtions
##

# import functions
import functions as f

# Define data fields
x = 0
y = 0
z = 0
choice = 0

# Get input
while True:
    print("This program provides many function to calculate: \n1. Find Smallest")
    choice = input("Enter your choice: ")
    if choice == 1:
        print("111")
        x = input("Enter the first number: ")
        y = input("Enter the seond number: ")
        z = input("Enter the third number: ")
        print(f.smallest(x, y, z))
        
#print(f.average(3,3,3))
