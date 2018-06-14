/*
Lab 4
Yixing Zheng, zheng129@mail.chapman.edu
Bailey Anderson, ander412@mail.chapman.edu
Akash Arora, arora110@mail.chapman.edu
Brendan Copp, copp102@mail.chapman.edu
Due: 12/7/2017
The purpose of this program is to print out a table of temperture in both fahrenheit and celsius
*/
#include <stdio.h>

int main(){
  // celsius = (5/9)*(fahr- 32)
  int fahrenheit; // define fahrenheit
  double celsius; // define celsius

  printf("%3s %s\n", "F", "C"); // prints out the units for the temperture table
  for (fahrenheit = 200; fahrenheit >= 0; fahrenheit -= 10){ // in this case, the table of temperture starts from 200 fahrenheit
    celsius = (fahrenheit - 32) * (5.0/9.0); // calculates the celsius
    printf("%3d ", fahrenheit); // prints out fahrenheit
    printf("%.2f\n", celsius); // prints out celsius
  }
  return 0;
}
