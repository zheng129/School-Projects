##
# Zheng, Yixing
# September 12, 2016
#
# Translate pseudocode into Python program on extract dollars and cents from a float
##

# Getting input
totalPrice = float(input("Please enter a price: "))

# Converting float to integer
dollars = int(totalPrice)

# Calculating the results
cents = (totalPrice - dollars) * 100 + 0.5

# Convert 'cents' to int to store
cents = int(cents)

# output result
print("A price of", totalPrice, "yields values", dollars,
      "dollars and", cents, "cents.")

