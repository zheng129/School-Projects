##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that read a sequence of integer inputs and print results
##

# Define data fields
sequence = []
countEven= 0
countOdd = 0
total = 0
previous = 0

# Get input
while True:
    ints = input("Enter an integer (Enter nothing to stop input): ")
    if ints != "":
        ints = int(ints)
    else:
        break
    ints = [ints]
    sequence = sequence + ints

# Compute the smallest and largest of the inputs
for i in sequence:
    smallest = sequence[0]
    if i < smallest:
        smallest = i
        
for i in sequence:
    largest = sequence[0]
    if i > largest:
        largest = i
print("The largest integer is {}\nThe smallest integer is {}".format(largest, smallest))

# Compute the number of even and odd inputs
for i in sequence:
    if (i % 2 == 0):
        countEven += 1
    if (i % 2 == 1):
        countOdd += 1
print("The number of even inputs is {}\nThe number of odd inputs is {}".format(countEven, countOdd))

# Compute the cumulative totals
for i in sequence:
    total += i
    print("The current total is {}".format(total))

# Compute all adjacent duplicates
for i in sequence[1:]:
    previous = sequence[0]
    if (i != previous):
        previous = i
    else:
        print(i)

