##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that prompts the user for an integer and then prints out all prime
# numbers up to that integer
##

# Get input
num = int(input("Enter an integer: "))

# Find all the prime numbers and print them out
for num in range(0, num + 1):
    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                break
        else:
            print(num)

