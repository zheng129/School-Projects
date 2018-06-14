##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that implements a program that prompts the user for an integer n and
# prints the nth Fibonacci number
##

# Define data fields
fnew = [0, 1]

# Get input
n = int(input("Enter an integer n for calculating nth Fibonacci number: "))

# Calculate the nth Fibonacci numbers
if n == 0:
    fnew = [0]
elif n == 1:
    fnew = [1]
    
for i in range(2, n + 1):
    fnew.append(fnew[-1] + fnew[-2])
         
print("The {}th Fibonacci number is {}".format(n, fnew[-1]))
