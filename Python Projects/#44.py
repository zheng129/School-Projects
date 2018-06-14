##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that prompts the user for a frequency value and prints a description
# of the corresponding part of the electromagnetic spectrum
##

# Get input
frequency = int(input("Enter the frequency: "))

# Determind the frequency is in which catalog and print out the result
if frequency < 3 * (10**9):
    print("It is Radio Waves.")
if 3 * (10**9) <= frequency < 3 * (10**11):
    print("It is Microwaves.")
if 3 * (10**11) <= frequency < 3 * (10**14):
    print("It is Infrared.")
if 4 * (10**14) <= frequency < 7.5 * (10**14):
    print("It is Visible light.")
if 7.5 * (10**14) <= frequency < 3 * (10**16):
    print("It is Ultravoilet.")
if 3 * (10**16) <= frequency < 3 * (10**19):
    print("It is X-rays.")
if frequency > 3 * (10**19):
    print("It is Gamma rays.")
