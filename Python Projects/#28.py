##
# Zheng, Yixing
# October 2, 2016
# CS 122
#
# A program that converts positive integer into Roman number system 
##

# Get input and make sure the input is in right form
while True:
    try:
        x = input("Enter a positive integer from 1 - 3999 (without space): ")
        intX = int(x)
        if (intX) == 0 or 0 > (intX):
            print("The number has to grater than 1 ")
        elif (intX) > 3999:
            print("the number cannot be no more than 3999")
        else:
            if len(x) == 1:
                if intX == 1:
                    first = "I"
                elif intX == 2:
                    first = "II"
                elif intX == 3:
                    first = "III"
                elif intX == 4:
                    first = "IV"
                elif intX == 5:
                    first = "V"
                elif intX == 6:
                    first = "VI"
                elif intX == 7:
                    first = "VII"
                elif intX == 8:
                    first = "VIII"
                elif intX == 9:
                    first = "IX"
                print(first)
                break
            
            if len(x) == 2:
                a = int(x[0])
                b = int(x[1])
                if a == 0:
                    first = ""
                elif a == 1:
                    first = "X"
                elif a == 2:
                    first = "XX"
                elif a == 3:
                    first = "XXX"
                elif a == 4:
                    first = "XL"
                elif a == 5:
                    first = "L"
                elif a == 6:
                    first = "LX"
                elif a == 7:
                    first = "LXX"
                elif a == 8:
                    first = "LXXX"
                elif a == 9:
                    first = "XC"

                if b == 0:
                    first1 = ""
                if b == 1:
                    first1 = "I"
                elif b == 2:
                    first1 = "II"
                elif b == 3:
                    first1 = "III"
                elif b == 4:
                    first1 = "IV"
                elif b == 5:
                    first1 = "V"
                elif b == 6:
                    first1 = "VI"
                elif b == 7:
                    first1 = "VII"
                elif b == 8:
                    first1 = "VIII"
                elif b == 9:
                    first1 = "IX"
                print(first + first1)
                break
            
            if len(x) == 3:
                a = int(x[0])
                b = int(x[1])
                c = int(x[2])
                if a == 0:
                    first = ""
                if a == 1:
                    first = "C"
                elif a == 2:
                    first = "CC"
                elif a == 3:
                    first = "CCC"
                elif a == 4:
                    first = "CD"
                elif a == 5:
                    first = "D"
                elif a == 6:
                    first = "DC"
                elif a == 7:
                    first = "DCC"
                elif a == 8:
                    first = "DCCC"
                elif a == 9:
                    first = "CM"

                if b == 0:
                    first1 = ""
                elif b == 1:
                    first1 = "X"
                elif b == 2:
                    first1 = "XX"
                elif b == 3:
                    first1 = "XXX"
                elif b == 4:
                    first1 = "XL"
                elif b == 5:
                    first1 = "L"
                elif b == 6:
                    first1 = "LX"
                elif b == 7:
                    first1 = "LXX"
                elif b == 8:
                    first1 = "LXXX"
                elif b == 9:
                    first1 = "XC"

                if c == 1:
                    first2 = "I"
                elif c == 2:
                    first2 = "II"
                elif c == 3:
                    first2 = "III"
                elif c == 4:
                    first2 = "IV"
                elif c == 5:
                    first2 = "V"
                elif c == 6:
                    first2 = "VI"
                elif c == 7:
                    first2 = "VII"
                elif c == 8:
                    first2 = "VIII"
                elif c == 9:
                    first2 = "IX"
                print(first + first1 + first2)
                break

            if len(x) == 4:
                a = int(x[0])
                b = int(x[1])
                c = int(x[2])
                d = int(x[3])
                if a == 0:
                    first = ""
                if a == 1:
                    first = "M"
                elif a == 2:
                    first = "MM"
                elif a == 3:
                    first = "MMM"

                if b == 0:
                    first1 = ""
                if b == 1:
                    first1 = "C"
                elif b == 2:
                    first1 = "CC"
                elif b == 3:
                    first1 = "CCC"
                elif b == 4:
                    first1 = "CD"
                elif b == 5:
                    first1 = "D"
                elif b == 6:
                    first1 = "DC"
                elif b == 7:
                    first1 = "DCC"
                elif b == 8:
                    first1 = "DCCC"
                elif b == 9:
                    first1 = "CM"

                if c == 0:
                    first2 = ""
                elif c == 1:
                    first2 = "X"
                elif c == 2:
                    first2 = "XX"
                elif c == 3:
                    first2 = "XXX"
                elif c == 4:
                    first2 = "XL"
                elif c == 5:
                    first2 = "L"
                elif c == 6:
                    first2 = "LX"
                elif c == 7:
                    first2 = "LXX"
                elif c == 8:
                    first2 = "LXXX"
                elif c == 9:
                    first2 = "XC"

                if d == 0:
                    first3 = ""
                elif d == 1:
                    first3 = "I"
                elif d == 2:
                    first3 = "II"
                elif d == 3:
                    first3 = "III"
                elif d == 4:
                    first3 = "IV"
                elif d == 5:
                    first3 = "V"
                elif d == 6:
                    first3 = "VI"
                elif d == 7:
                    first3 = "VII"
                elif d == 8:
                    first3 = "VIII"
                elif d == 9:
                    first3 = "IX"
                print(first + first1 + first2 + first3)
                break
    except ValueError:
        print(" Please enter a positive integer! ")
