//Yixing Zheng
abstract interface MathOperations{

/**
  * This method will receive two double numbers as a parameters
  * it will add them and return the result.
  */
   abstract double add(double dNum1, double dNum2 );

/**
  * This method will receive a double number as a parameter
  * it will calculate its absolute value and will return it
  */
   abstract double absoluteValue (double dNum );


/**
  * This method will receive an int number as a parameter
  * it will determine if the number is even or not and
  * it will return true if it is even or false otherwise
  */

   abstract boolean isEven(int iNum);

} //ends class
