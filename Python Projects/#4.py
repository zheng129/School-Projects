##
# Zheng, Yixing
# September 20, 2016
# CS 122
#
# A program that takes three numbers to determind whether they are all same or
# all different or neither
##

# Get input and convert them into float from str
number1 = float(input("Please enter the first number: "))
number2 = float(input("Please enter the second number: "))
number3 = float(input("Please enter the third number: "))

# Determine whether the numbers are all same or all different or neither and print out results
if number1 == number2:
    if number1 == number3:
        print("They are all the same!")

if number1 != number2:
    if number1 != number3:
        if number2 != number3:
            print("They are all differnet!")
            
if number1 == number2:
    if number1 != number3:
        print("They are neither all same nor all different.")

if number1 == number3:
    if number2 != number3:
        print("They are neither all same nor all different.")

if number2 == number3:
    if number1 != number3:
        print("They are neither all same nor all different.")
