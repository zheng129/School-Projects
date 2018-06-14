##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that reads a word and prints all substrings, sorted by lenth
##

# Define data fields
length = 1
pos = 0

# Get input
word = input("Enter a word: ")

# Take out substrings
for i in range(length, len(word) + 1):
    for j in range(pos, len(word) - i + 1):
        print(word[j : j + i])

