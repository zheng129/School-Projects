##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that calculates the income tax
##

# Define data field
incomeTax = 0
PRICE_DIFFERENCE1 = 50000
PRICE_DIFFERENCE2 = 25000
PRICE_DIFFERENCE3 = 25000
PRICE_DIFFERENCE4 = 150000
PRICE_DIFFERENCE5 = 250000
TAX_RATE1 = 0.01
TAX_RATE2 = 0.02
TAX_RATE3 = 0.03
TAX_RATE4 = 0.04
TAX_RATE5 = 0.05
TAX_RATE6 = 0.06

# Get input
income = int(input("Enter your income: "))

# Calculate the income tax and print out the result
if income < 50000:
    incomeTax = income * TAX_RATE1
if 50000 <= income:
    incomeTax = (PRICE_DIFFERENCE1 * TAX_RATE1) + ((income - 50000) * TAX_RATE2)
if 75000 < income:
    incomeTax = (PRICE_DIFFERENCE1 * TAX_RATE1) + (PRICE_DIFFERENCE2 * TAX_RATE2) + ((income - 75000) * TAX_RATE3)
if 100000 < income:
    incomeTax = (PRICE_DIFFERENCE1 * TAX_RATE1) + (PRICE_DIFFERENCE2 * TAX_RATE2) + (PRICE_DIFFERENCE3 * TAX_RATE3) + ((income - 100000) * TAX_RATE4)
if 250000 < income:
    incomeTax = (PRICE_DIFFERENCE1 * TAX_RATE1) + (PRICE_DIFFERENCE2 * TAX_RATE2) + (PRICE_DIFFERENCE3 * TAX_RATE3) + (PRICE_DIFFERENCE4 * TAX_RATE4) + ((income - 250000) * TAX_RATE5)
if income > 500000:
    incomeTax = (PRICE_DIFFERENCE1 * TAX_RATE1) + (PRICE_DIFFERENCE2 * TAX_RATE2) + (PRICE_DIFFERENCE3 * TAX_RATE3) + (PRICE_DIFFERENCE4 * TAX_RATE4) + (PRICE_DIFFERENCE5 * TAX_RATE5) + (income * TAX_RATE6)

print("Your tax is {:.2f}{:s}".format(incomeTax, "."))
