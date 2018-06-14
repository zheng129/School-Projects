import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *Calculates and displays series of functions 
 *by recursive methods
 * 
 * @author Yixing Zheng
 * @author William McDaniel Albritton provides functions for factorial and power
 */
public class AllRecursive {

	/**
	 * Program starts here
	 * 
	 */

	public static void main(String[] args) {

		// initialize variables
		Integer x = new Integer(1);
		Integer y = new Integer(1);
		Integer result;
		Scanner keyboard = new Scanner(System.in);

		// user's choice for Menu
		Integer choice = new Integer(9);
		// choice for ending program
		final Integer QUIT = new Integer(8);
		// if the user does not want to QUIT, keep looping
		while (!choice.equals(QUIT)) {
			// get the user's choice
			choice = AllRecursive.displayMenu();

			// add the two input numbers
			if (choice.equals(1)) {
				// ask user to input two numbers
				System.out.print("Enter the first number you want to add: ");
				try {
					x = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.print("Enter the second number you want to add: ");
				try {
					y = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.println("The answer is : " + AllRecursive.add(x, y)); //return address A
			}
			// subtract the two input numbers
			else if (choice.equals(2)) {
				// ask user to input two numbers
				System.out.print("Enter the first number you want to subtract: ");
				try {
					x = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.print("Enter the second number you want to subtract: ");
				try {
					y = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.println("The answer is : " + AllRecursive.subtract(x, y)); //return address B
			}
			// multiply the two input numbers
			else if (choice.equals(3)) {
				// ask user to input two numbers
				System.out.print("Enter the first number you want to multiply: ");
				try {
					x = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.print("Enter the second number you want to multiply: ");
				try {
					y = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.println("The answer is : " + AllRecursive.multiply(x, y)); //return address C
			}
			// divide the two input numbers
			else if (choice.equals(4)) {
				// ask user to input two numbers
				System.out.print("Enter the numerator: ");
				try {
					x = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.print("Enter the denominator: ");
				try {
					y = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				result = AllRecursive.divide(x, y); //return address D
				if (result.equals(-1)){
					System.out.println("ERROR: by mathematical definition, denominator can't be 0.");
				}
				else if (result.equals(-2)){
					System.out.println("ERROR: The result of your inputs cannot be displayed as a whole number.");
				}
				else{
					System.out.println("The answer is : " + AllRecursive.divide(x, y));
				}
			}
			// power the two input numbers
			else if (choice.equals(5)) {
				// ask user to input two numbers
				System.out.print("Enter the base number: ");
				try {
					x = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				System.out.print("Enter the exponent: ");
				// error checking to see if y is an integer
				try {
					y = keyboard.nextInt();
				}
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				// call recursive method
				result = AllRecursive.power(x, y); //return address E
				// error checking to see if it is non-negative
				if (result.equals(-1)) {
					System.out.println("ERROR: Negative integers are undefined for this power function!");
				}
				else {
					System.out.println(x + "^" + y + " = " + result);
				}
			}

			// calculate the factorial of the input
			else if (choice.equals(6)) {

				// ask user to input two numbers
				System.out.print("Enter the number you want to do factorial: ");
				//error checking to see if it is an integer
				try {
					x = keyboard.nextInt();
				} 
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				// call recursive method   
				result = AllRecursive.factorial(x); //return address F
				// error checking to see if it is non-negative
				if (result.equals(-1)) {
					System.out.println("ERROR: Negative integers are undefined for factorials!");
				}
				if (result.equals(-2)){
					System.out.println("ERROR: The input for factorial can not be more than 25.");
				}
				else{ 
					System.out.println(x + "! = " + result);
				}
			}

			// calculate the summation of the input
			else if (choice.equals(7)) {
				// ask user to input two numbers
				System.out.print("Enter the number you want to do summation: ");
				// error checking to see if it is an integer
				try {
					x = keyboard.nextInt();
				} 
				catch (InputMismatchException exception) {
					System.out.println("Your input is not an integer");
					System.exit(8); // end program
				}
				// call recursive method   
				result = AllRecursive.summation(x); //return address G
				// error checking to see if it is non-negative
				if (result.equals(-1)) {
					System.out.println("ERROR: Negative integers are undefined for summation!");
				}
				else{ 
					System.out.println("The summation of " + x + " is "+ result + ".");
				}
			}
			// error message
			else if (choice == 0) {
				System.out.println("ERROR: Please enter an integer in the range from 1 to 8");
			}
			// error message
			else if (!choice.equals(QUIT)) {
				System.out.println("ERROR: Please enter an integer in the range from 1 to 8");
			}
		}// end of "while"
	}

	/**A method displaying the menu for users and receiving choices of users
	 * 
	 * @return choiceOfUser that reveal what users choose
	 */
	public static Integer displayMenu() {
		//data fields
		Integer choiceOfUser = new Integer(8);
		// set up scanner
		Scanner keyboardInput = new Scanner(System.in);

		// display menu
		System.out.println();
		System.out.println("\t What do you want to do?");
		System.out.println("\t 1. Add (two numbers)");
		System.out.println("\t 2. Subtract (two numbers)");
		System.out.println("\t 3. Multiply (two numbers)");
		System.out.println("\t 4. Divide (two numbers)");
		System.out.println("\t 5. Power (two numbers)");
		System.out.println("\t 6. Factorial (one numbers)");
		System.out.println("\t 7. Summation (one numbers)");
		System.out.println("\t 8. Exit");
		// get input from user
		try {
			// non-integer input will throw InputMismatchException
			choiceOfUser = keyboardInput.nextInt();
		} catch (InputMismatchException exception) {
			System.out.println("Your input is not an integer");
		}
		System.out.println();
		return choiceOfUser; //return address H
	}

	/**
	 * Computes the addition of two nonnegative numbers with recursion
	 * 
	 * @param x is a nonnegative integer
	 * @param y is a nonnegative integer
	 * @return the result of x plus y, or -1 for negative integers (error)
	 */
	public static Integer add(Integer x, Integer y) {
		// base case #1: check for negative integers
		if (x < 0 || y < 0) {
			System.out.println("All inputs should not be negative");
			return -1; // error condition
		}
		// base case #2: by mathematical definition, 0 + 0 = 0
		if (x == 0) {
			return y;
		}
		else {
			return add(--x , ++y); //return address I
		}
	}// end of recursive

	/**
	 * Computes the subtraction of two nonnegative numbers with recursion
	 * 
	 * @param x is a nonnegative integer
	 * @param y is a nonnegative integer
	 * @return the result of x minus y, or -1 for negative integers (error)
	 */
	public static Integer subtract(Integer x, Integer y) {
		// base case #1: check for negative integers
		if (x < 0 || y < 0) {
			System.out.println("All inputs should not be negative");
			return -1; // error condition
		}
		// base case #2:by mathematical definition, x - 0 = x
		if (y == 0) {
			return x;
		}
		if (y > x){
			return subtract((y - 1), (x - 1)) * -1;
		}
		else{
			return subtract((x - 1), (y - 1)); //return address J
		}
	}// end of recursive

	/**
	 * Computes the multiplication of two nonnegative numbers with recursion
	 * 
	 * @param x is a nonnegative integer
	 * @param y is a nonnegative integer
	 * @return the result of x times y, or -1 for negative integers (error)
	 */
	public static Integer multiply(Integer x, Integer y) {
		// base case #1: check for negative integers
		if (x < 0 || y < 0) {
			System.out.println("All inputs should not be negative");
			return -1; // error condition
		}
		// base case #2: by mathematical definition, x * 0 = 0
		if (x == 0) {
			return 0;
		}
		// base case #3: by mathematical definition, y * 0 = 0
		if (y == 0)
			return 0;
		// recursive case: return x + (method call for x * y-1)
		return x + multiply(x, y - 1); //return address K
	}// end of recursive


	/**
	 * Computes the division of two nonnegative numbers with recursion
	 * 
	 * @param x is a nonnegative integer
	 * @param y is a nonnegative integer
	 * @return the result of x divide by y, or -1 for negative integers (error)
	 */
	public static Integer divide(Integer x, Integer y) {
		// base case #1: check for negative integers
		if (x < 0 || y < 0) {
			System.out.println("All inputs should not be negative");
			return -1; // error condition
		}
		// base case #2: by mathematical definition, denominator can't be 0
		if (y == 0) {
			return -1;
		}
		// base case #3: by mathematical definition, 0 / y = 0
		if (x == 0){
			return 0;
		}
		if (y > x){
			return -2;//error condition
		}
		// recursive case: return (method call for x - y, y) + 1
		return divide(x - y, y) + 1; //return address L
	}// end of recursive

	/**
	 * Computes the power of a nonnegative numbers with recursion
	 * 
	 * @param x is a nonnegative integer (base)
	 * @param y is a nonnegative integer (exponent)
	 * @return the result of x to the power of y (x^y), or -1 for negative integers (error)
	 */
	public static Integer power(Integer x, Integer y) {
		// base case #1: check for negative integers
		if (x < 0 || y < 0) {
			return -1; // error condition
		}
		// base case #2: by mathematical definition, x^0 = 1
		if (y.equals(0)) {
			return 1;
		}
		// recursive case: return x * (method call for y-1)
		// we must make the problem smaller by subtracting one!
		return x * AllRecursive.power(x, y - 1); //return address M
	}// end of recursive

	/**
	 * Computes the factorial of a nonnegative number with recursion
	 * @param number is a nonnegative integer
	 * @return the factorial of number, or -1 for negative integers (error)
	 */
	public static Integer factorial(Integer number) {
		//base case #1: check for negative integers
		if(number < 0){
			return -1; //error condition
		}
		//base case #2: by mathematical definition, 0! = 1
		else if(number.equals(0) || number.equals(1)){
			return 1;
		}
		//base case #3: number cannot be more than 25.
		else if (number > 25) {
			return -2;//error condition
		}
		else{
			//recursive case: return n * (method call for n-1)
			//we must make the problem smaller by subtracting one! 
			return number * AllRecursive.factorial(number - 1); //return address N
		}
	}//end of recursive

	/**
	 * Computes the summation of a nonnegative number with recursion
	 * @param number is a nonnegative integer
	 * @return the summation of number, or -1 for negative integers (error)
	 */
	public static Integer summation(Integer number) {
		//base case #1: check for negative integers
		if(number < 0){
			return -1; //error condition
		}
		//base case #2: by mathematical definition, 1 -> 0 = 1
		else if(number == 0){
			return 1;
		}
		else{
			//recursive case: return n + (method call for n-1)
			//we must make the problem smaller by subtracting one! 
			return number + AllRecursive.summation(number - 1); //return address O
		}
	}//end of recursive
}
