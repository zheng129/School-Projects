##
# Zheng, Yixing
# September 12, 2016
#
# A program that directs cashiers how to give change
##

# Define deta fields
CENTS_PER_QUARTER = 25
CENTS_PER_DIMES = 10
CENTS_PER_NICKELS= 5

# Getting input
amtDue = float(input("Please enter the amount due: "))
amtReceived = float(input("Please enter the amount received: "))

if amtReceived < amtDue:
    print("Opps, looks like that is not enought to pay off the bill")

# calculate changes
changes = amtReceived - amtDue
changes = round(changes, 2)

# Calculate the number of each kind of coin
dollars = int(changes)
cents = round((changes - dollars),2) * 100
quarters = cents // CENTS_PER_QUARTER
dimes = (cents % CENTS_PER_QUARTER) // CENTS_PER_DIMES
nickels = (cents % CENTS_PER_DIMES % CENTS_PER_DIMES) // CENTS_PER_NICKELS
remainCents = (cents % CENTS_PER_DIMES % CENTS_PER_DIMES % CENTS_PER_NICKELS )

# Print out results

print("Your changes is $", changes, "which is", dollars, "dollars,", quarters, "quarters,", dimes, "dimes,",nickels, "nickels and", remainCents, "pennies.")
