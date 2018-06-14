##
# Zheng, Yixing
# September 20, 2016
# CS 122
#
# A program that translates a card notation to full description of the card
##

# Define data field
D = "Diamonds"
H = "Hearts"
S = "Spades"
C = "Clubs"

A = "Ace"
J = "Jack"
Q = "Queen"
K = "King"

# Get input
print("%-14s %-24s %-14s %-14s" % ("A", "Ace", "D", "Diamonds"))
print("%-14s %-24s %-14s %-14s" % ("2 ... 10", "Card values", "H", "Hearts"))
print("%-14s %-24s %-14s %-14s" % ("J", "Jack", "S", "Spades"))
print("%-14s %-24s %-14s %-14s" % ("Q", "Queen", "C", "Clubs"))
print("%-14s %-24s" % ("K", "King"))
cardNotation = input("Please enter the card notation by rules above: ")

# Get rid of spacess
cardNotation = cardNotation.replace(" ", "")

# Get the value of the card
cardValue = cardNotation.replace("D", "")
cardValue = cardValue.replace("H", "")
cardValue = cardValue.replace("S", "")
cardValue = cardValue.replace("C", "")
num = cardValue

# Get the color of the card
cardColor = cardNotation.replace(cardValue, "")

# Translate the notation to full description of the card and print out the results
if cardColor == ("D"):
    if cardValue == ("A"):
        print("%s %s %s" % (A ,"of", D))
    elif cardValue == ("J"):
        print("%s %s %s" % (J ,"of", D))
    elif cardValue == ("Q"):
        print("%s %s %s" % (Q ,"of", D))
    elif cardValue == ("K"):
        print("%s %s %s" % (K ,"of", D))
    else:
        print("%s %s %s" % (num, "of", D))

if cardColor == ("H"):
    if cardValue == ("A"):
        print("%s %s %s" % (A ,"of", H))
    elif cardValue == ("J"):
        print("%s %s %s" % (J ,"of", H))
    elif cardValue == ("Q"):
        print("%s %s %s" % (Q ,"of", H))
    elif cardValue == ("K"):
        print("%s %s %s" % (K ,"of", H))
    else:
        print("%s %s %s" % (num, "of", H))

if cardColor == ("S"):
    if cardValue == ("A"):
        print("%s %s %s" % (A ,"of", S))
    elif cardValue == ("J"):
        print("%s %s %s" % (J ,"of", S))
    elif cardValue == ("Q"):
        print("%s %s %s" % (Q ,"of", S))
    elif cardValue == ("K"):
        print("%s %s %s" % (K ,"of", S))
    else:
        print("%s %s %s" % (num, "of", S))

if cardColor == ("C"):
    if cardValue == ("A"):
        print("%s %s %s" % (A ,"of", C))
    elif cardValue == ("J"):
        print("%s %s %s" % (J ,"of", C))
    elif cardValue == ("Q"):
        print("%s %s %s" % (Q ,"of", C))
    elif cardValue == ("K"):
        print("%s %s %s" % (K ,"of", C))
    else:
        print("%s %s %s" % (num, "of", C))
