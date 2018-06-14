##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that converts units
##

# Define data field
result = 0
G_PER_GAL = 3785.4118
KG_PER_GAL = 3.7854118
L_PER_GAL = 0.264172
ML_PER_GAL = 0.000264172

G_PER_OZ = 28.3495
KG_PER_OZ = 0.0283495
L_PER_OZ = 0.0295735
ML_PER_OZ = 29.5735

G_PER_LB = 453.592
KG_PER_LB = 0.453592
L_PER_LB = 0.47317
ML_PER_LB = 473.17

MM_PER_IN = 25.4
CM_PER_IN = 2.54
M_PER_IN = 0.0254
KM_PER_IN = 0.0000254

MM_PER_FT = 304.8
CM_PER_FT = 30.48
M_PER_FT = 0.3048
KM_PER_FT = 0.0003048

MM_PER_MI = 1609340
CM_PER_MI = 160934
M_PER_MI = 1609.34
KM_PER_MI = 1.60934

# Get input
print("Type in units for convertions. \nThis program can convert {:s}{:s}{:s}{:s}{:s}{:s}{:s}".format("fl.oz, ","gal, ","oz, ","lb, ","in, ","ft, ","mi."),
      "\nTo {:s}{:s}{:s}{:s}{:s}{:s}{:s}{:s}".format("ml, ","l, ","g, ","kg, ","mm, ","cm, ","m, ", "km."))
convertFrom = input("Convert from? ")
convertTo = input("Convert to? ")

while True:
     try:
         value = float(input("Please enter a value: "))
         break
     except ValueError:
         print("That was not a valid number. Please try again.")

# Check if convertion is compatible
if convertFrom == "oz" or convertFrom == "fl.oz" or convertFrom == "gal" or convertFrom == "lb":
    if convertTo == "mm":
        print("Can't convert volume to length.")
        exit()
    elif convertTo == "cm":
        print("Can't convert volume to length.")
        exit()
    elif convertTo == "m":
        print("Can't convert volume to length.")
        exit()
    elif convertTo == "km":
        print("Can't convert volume to length.")
        exit()

if convertFrom == "in" or convertFrom == "ft" or convertFrom == "mi":
    if convertTo == "ml":
        print("Can't convert length to volume.")
        exit()
    elif convertTo == "l":
        print("Can't convert length to volume.")
        exit()
    elif convertTo == "g":
        print("Can't convert length to volume.")
        exit()
    elif convertTo == "kg":
        print("Can't convert length to volume.")
        exit()

# Convert units and get result
if convertFrom == "oz" or convertFrom == "fl.oz":
    if convertTo == "ml":
        result = value * ML_PER_OZ
    if convertTo == "l":
        result = value * L_PER_OZ
    if convertTo == "g":
        result = value * G_PER_OZ
    if convertTo == "kg":
        result = value * KG_PER_OZ

if convertFrom == "gal":
    if convertTo == "ml":
        result = value * ML_PER_GAL
    if convertTo == "l":
        result = value * L_PER_GAL
    if convertTo == "g":
        result = value * G_PER_GAL
    if convertTo == "kg":
        result = value * KG_PER_GAL

if convertFrom == "lb":
    if convertTo == "ml":
        result = value * ML_PER_LB
    if convertTo == "l":
        result = value * L_PER_LB
    if convertTo == "g":
        result = value * G_PER_LB
    if convertTo == "kg":
        result = value * KG_PER_LB

if convertFrom == "in":
    if convertTo == "mm":
        result = value * MM_PER_IN
    if convertTo == "cm":
        result = value * CM_PER_IN
    if convertTo == "m":
        result = value * M_PER_IN
    if convertTo == "km":
        result = value * KM_PER_IN
        
if convertFrom == "ft":
    if convertTo == "mm":
        result = value * MM_PER_OZ
    if convertTo == "cm":
        result = value * CM_PER_OZ
    if convertTo == "m":
        result = value * M_PER_OZ
    if convertTo == "km":
        result = value * KM_PER_OZ
        
if convertFrom == "mi":
    if convertTo == "mm":
        result = value * MM_PER_MI
    if convertTo == "cm":
        result = value * CM_PER_MI
    if convertTo == "m":
        result = value * M_PER_MI
    if convertTo == "km":
        result = value * KM_PER_MI
        
# print out results
print("{:.10f} {:s} = {:.10f} {:s}".format(value, convertFrom, result, convertTo))
