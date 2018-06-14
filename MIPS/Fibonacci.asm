# Lab 2
# Yixing Zheng, zheng129@mail.chapman.edu
# Due: 12/5/2017
# The purpose of this program is to implement the Fibonacci numbers by a while loop
main: addi $a0, $0, 8 # n = 8, calculate fib(8) in this lab
     addi $t0, $0, -1 # jump-start loop with
     addi $t1, $0, 1 # fib(-1) and fib(0)

fib: beq $a0, $0, done # if $a0 == 0, returns the value of the sum
    add $t2, $t0, $t1 # calculates the sum of the last two numbers and store it in a temporary variable 
    add $t0, $0, $t1 # update n - 1 and store it for further calculation
    add $t1, $0, $t2 # update n - 2 and store it for further calculation
    addi $a0, $a0, -1 # decrease $a0, fib(n)
    j fib # jump back to top of the loop

done:
   addi $v0, $t1, 0 # when it is done, store the value of the total sum of the Fibonacci numbers into a variable
