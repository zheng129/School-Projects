##
# Zheng, Yixing
# October 11, 2016
# CS 122
#
# A program that translate pseudocode for randomly permuting the characters in a string
# into a Python program
##

# Import random function
from random import randint as r

# Define data field
randomPositionI = 0
randomPositionJ = 0
first = ""
middle = ""
last = ""

# Get input
word = input("Enter a word: ")

# Translate the pseudocode into Python program
for i in range(0, len(word)):
    randomPositionI = r(0, len(word))
    randomPositionJ = r(0, len(word))
    
    if randomPositionJ > randomPositionI and randomPositionJ < len(word) and randomPositionI < len(word):
        first = word[:randomPositionI]
        #print("first is ", first)
        middle = word[randomPositionI + 1:randomPositionJ]
        #print("middle is ", middle)
        last = word[randomPositionJ + 1:]
        #print("last is ", last)
        print(first, word[randomPositionJ], middle, word[randomPositionI], last)
