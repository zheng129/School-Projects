##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that read a line of input as string and print results
##

# Define data fields
letter = []
letter1 = []
vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"]
digitCounter = 0
newstring = ""
positionCounter = 0

# Get input
string = input("Enter a string: ")
string = string.replace(" ","")

# Print only the uppercase letters in string
for i in string:
    if i.isupper():
        i = [i]
        letter = letter + i
print("The uppercase letter in string {} is/are {}".format(string, letter))

# Print every second letter of the string
for i in string[: : 2]:
    i = [i]
    letter1 = letter1 + i
print("The every second letter of the string {} is/are {}".format(string, letter1))

# Print the string with all vowels replaced by an underscore
for i in string:
    if i in vowels:
        i = "_"
    newstring = newstring + i
print("The string {} with vowels replaced by '_' is {}".format(string,newstring))

# Print the number of digits in the string
for i in string:
    if i.isdigit():
        digitCounter += 1
print("The number of digits in string {} is {}".format(string, digitCounter))

# Print the position of all vowels in the string
for i in newstring:
    if (i != "_"):
        positionCounter = positionCounter + 1
    elif (i == "_"):
        positionCounter = positionCounter + 1
        print("The positions of all vowels are {}".format(positionCounter))
