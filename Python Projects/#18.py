##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that prints multiplication table
##

# Defind data fields
n = 10

# Print out multiplication table
for row in range(1, n + 1):
    for col in range(1, n+1):
        print(row * col)
        
# The fancy way found online that provides exactly what the question needs
for row in range(1, n+1):
    print(*("{:3}".format(row * col) for col in range(1, n+1)))

