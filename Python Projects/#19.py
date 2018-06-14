##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that prompts the user to provide a single character from the alphabet
# and print out if it is vowel or consonant
##

# Get input
character = input("Enter one character for testing if it is an vowel: ")

# check if the length of charater is more than one
if len(character) > 1:
    print("Error: Please enter only one character for testing.")
    exit()

# Check if the character is in the alphabet
for i in range(0, len(character)):
    if character in "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ":
        for i in range(0, len(character)):
            if character[i] in "aeiouAEIOU":
                print("{:s} is vowel{:s}".format(character, "."))
            else:
                print("{:s} is consonant{:s}".format(character, "."))
    else:
        print("The character is not in the alphabet!")
