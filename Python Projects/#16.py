##
# Zheng, Yixing
# September 27, 2016
# CS 122
#
# A program that takes three strings and sorts them lexicographically
##

# Get input
str1 = input("Enter a string: ")
str2 = input("Enter a string: ")
str3 = input("Enter a string: ")

# Sort the strings lexicographically and print them out
if str1[0] < str2[0]: # 1 < 2
    if str2[0] < str3[0]: # 2 < 3
        print("{}\n{}\n{}".format(str1, str2, str3)) # 1 < 2 < 3
    else: # 3 < 2
        if str1[0] < str3[0]: # 1 < 2 ; 3 < 2 ; 1 < 3
            print("{}\n{}\n{}".format(str1, str3, str2))
        else: # 3 < 1 ; 3 < 2 ; 1 < 2
            print("{}\n{}\n{}".format(str3, str1, str2))
else: # 2 < 1
    if str1[0] < str3[0]: # 1 < 3
        print("{}\n{}\n{}".format(str2, str1, str3))
    else: # 3 < 1
        if str2[0] < str3[0]: # 2 < 1 ; 2 < 3 ; 3 < 1
            print("{}\n{}\n{}".format(str2, str3, str1))
        else: # 3 < 2
            print("{}\n{}\n{}".format(str3, str2, str1))
