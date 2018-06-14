##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program with loops that compute numbers
##

# Define data fields
total = 0
total1 = 0
power = 0
total2 = 0
total3 = 0

# Compute the sum of all even numbers between 2 and 100(inclusive)
for i in range(2, 101, 2):
    total += i
print("The sum of all even numbers between 2 and 100(inclusive) is {}".format(total))

# Compute the sum of all squares between 1 and 100(inclusive)
for i in range(1, 101):
    total1 += (i**(1/2))
print("The sum of all squares between 1 and 100(inclusive) is {}".format(total1))

# Compute all powers of 2 from 2**0 up to 2**20
for i in range(0, 21):
    power = 2**i
    print("The {} power of 2 is {}".format(i, power))

# Compute the sum of all odd numbers between a and b(inclusive), where a and b are inputs
a = int(input("Enter a number: "))
b = int(input("Enter a number: "))
for i in range(a, b + 1, 1):
    if (i % 2 == 1):
        total2 += i
print("The sum of all odd numbers between a and b(inclusive) is {}".format(total2))
# Compute the sum of all odd digits of an input
integer = int(input("Enter a number: "))
c = integer
while(c > 0):
    digit = c % 10
    if (digit % 2 == 1):
        total3 += digit
    c = c // 10
print("The sum of all odd digits of {} is {}".format(integer, total3))
