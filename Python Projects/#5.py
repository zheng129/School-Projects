##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that reads a set of floating-point values and print results
##

# Define data fields
sequence = []
counter = 0
total = 0
average = 0
theRange = 0

# Get input
while True:
    floats = input("Enter a float (Enter nothing to stop input): ")
    if floats != "":
        floats = float(floats)
    else:
        break
    floats = [floats]
    sequence = sequence + floats

# Compute the average of the values
for i in sequence:
    total += i
    counter += 1
average = total / counter
print("The average of sequence {} is {}".format(sequence,average))

# Compute the smallest of the value
for i in sequence:
    smallest = sequence[0]
    if i < smallest:
        smallest = i
print("The smallest integer is {}".format(smallest))

# Compute the largest of the value
for i in sequence:
    largest = sequence[0]
    if i > largest:
        largest = i
print("the largest integer is {}".format(largest))

# Compute the range
theRange = largest - smallest
print("The range between the largest and the smallest is {:.3f}".format(theRange))
