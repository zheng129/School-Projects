/**
 * A "driver program" to test Stack class implemented with linked nodes
 * 
 * @author Yixing Zheng
 */
import java.util.EmptyStackException;
import java.util.Scanner;
import java.util.InputMismatchException;

public class StackManager {

	/**The main method used to test and drive the program
	 * 
	 */
	public static void main(String[] args) {

		//make Stack of Strings 
		Stack stack2 = new StackOfInvoices();
		//data fields
		double total;
		String customer = "";
		int invoiceNumber = 1;
		// set up scanner
		Scanner keyboard = new Scanner(System.in);

		// user's choice for Menu
		Integer choice = new Integer(6);
		// choice for ending program
		final Integer QUIT = new Integer(0);
		// if the user does not want to QUIT, keep looping
		while (!choice.equals(QUIT)) {
			// get the user's choice
			choice = StackManager.displayMenu();

			// add an invoice to the stack
			if (choice.equals(1)) {

				System.out.print("Enter Total: ");
				total = keyboard.nextDouble();
				keyboard.nextLine();	
				System.out.print("Enter Customer: ");
				customer = keyboard.nextLine();
				Invoice input = new Invoice(total, customer, invoiceNumber);
				invoiceNumber = invoiceNumber + 1;
				stack2.push(input);
				stack2.size();
			}
			// remove an invoice from the stack
			else if (choice.equals(2)) {
				stack2.pop();
			}
			// Peek and print into the stack
			else if (choice.equals(3)) {
				System.out.println(stack2.peek());
			}
			// Print the number of elements in the stack
			else if (choice.equals(4)) {
				System.out.println(stack2.size());
			}
			// Print and empty all the elements in the stack
			else if (choice.equals(5)) {
				stack2.emptyAndPrint();
			}
			// error message
			else if (!choice.equals(QUIT)) {
				System.out.println("ERROR: Please enter an integer in the range from 0 to 5");
			}
		}// end of "while"
	}

	/**A method displaying the menu for users and receiving choices of users
	 * 
	 * @return choiceOfUser that reveal what users choose
	 */
	public static Integer displayMenu() {
		//data fields
		Integer choiceOfUser = new Integer(6);
		// set up scanner
		Scanner keyboardInput = new Scanner(System.in);

		// display menu
		System.out.println();
		System.out.println("\t What do you want to do?");
		System.out.println("\t 1. Add an invoice to the stack");
		System.out.println("\t 2. Remove an invoice from the stack");
		System.out.println("\t 3. Peek and print into the stack");
		System.out.println("\t 4. Print the number of elements in the stack");
		System.out.println("\t 5. Print and empty all the elements in the stack");
		System.out.println("\t 0. End this program ");
		// get input from user
		try {
			// non-integer input will throw InputMismatchException
			choiceOfUser = keyboardInput.nextInt();
		} catch (InputMismatchException exception) {
			// Already have error message in main() method,
			// as choiceOfUser = 0
		}
		System.out.println();
		return choiceOfUser;
	}
}//end of class
