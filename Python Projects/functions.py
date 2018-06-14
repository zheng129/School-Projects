##
# Zheng, Yixing
# October 23, 2016
# CS 122
#
# A program that define functions and test them inside this program
##

# Find the smallest of the three arguments
def smallest (x:int, y:int, z:int) -> int:
    '''
    Return the smallest argument from the values given
    >>> smallest(3, 4, 5)
    3
    >>> smallest(99, 101, 899)
    99
    '''
    if x < y:
        if y < z:
            return x
        else:
            if x < z:
                return x
            else:
                return z
    else:
        if z < y:
            return z
        else:
            return y
            
# Find the average of the arguments
def average (x:str = "num", y:str = "num", z:str = "num") -> "num":
    '''
    Return the average value from values x, y, and z
    >>> average(4, 3, 5)
    4.0
    >>> average(9, 9, 9)
    9.0
    '''
    return (x + y + z) / 3

# Determine whether the arguments are all the same
def allTheSame (x:str, y: str, z:str) -> bool:
    '''
    Return a bool value (True) if all arguments are the same
    >>> allTheSame("5", "5" ,"5")
    True
    >>> allTheSame("yi", "xing", "zheng")
    False
    '''
    if x == y and x == z:
        return True
    else:
        return False

# Determine whether the arguments are different
def allDifferent (x:str, y:str, z:str) -> bool:
    '''
    Return a bool value (True) if all arguments are different
    >>> allDifferent("5", "6" ,"7")
    True
    >>> allDifferent("7", "7" ,"7")
    False
    '''
    if x != y and x != z and y != z:
        return True
    else:
        return False
    
# Determine whether the arguments are sorted with the smallest one coming first
def sorted (x:int, y:int, z:int) -> bool:
    '''
    Return a bool value if all arguments are sorted
    >>> sorted(3, 7, 11)
    True
    >>> sorted(21, 9, 8)
    False
    '''
    if x < y or x < z:
        return True
    else:
        return False

# Fine the first digit of the int argument
def firstDigit (n:int) -> str:
    '''
    Return the first digit found in argument
    >>> firstDigit(3.1415926)
    '3'
    >>> firstDigit(0.11111)
    '0'
    '''
    n = str(n)
    firstDigit = n[0]
    return firstDigit
    
# Fine the last digit of the int argument
def lastDigit (n:int) -> str:
    '''
    Return the last digit found in argument
    >>> lastDigit(3.1415926)
    '6'
    >>> lastDigit(0.666667)
    '7'
    '''
    n = str(n)
    lastDigit = n[-1]
    return lastDigit
# Fine the number of digits in the argument
def numDigits (n:float) -> str:
    '''
    Return the number of digits in the argument
    >>> numDigits(3.14)
    3
    >>> numDigits(-3.1415926)
    8
    '''
    n = abs(n)
    n = str(n)
    if "." in n:
        return len(n) - 1
    else:
        return len(n)

# Test module
if __name__ == "__main__":
    
    import doctest
    doctest.testmod(verbose = True)
