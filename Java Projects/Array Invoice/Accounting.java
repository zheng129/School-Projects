/**
 * A "driver program" to test Invoice class implemented with arrays
 * 
 * @author Yixing Zheng
 */
import java.util.Scanner;
import java.util.InputMismatchException;

public class Accounting {

	/**The main method used to test and drive the program
	 * 
	 */
	public static void main(String[] args) {

		// Instantiate An Array.
		Invoice invoice[] = new Invoice[5];

		// Set size of grocery list to zero (0) items
		Integer size = new Integer(0);
		// set up scanner
		Scanner keyboard = new Scanner(System.in);

		// user's choice for Menu
		Integer choice = new Integer(4);
		// choice for ending program
		final Integer QUIT = new Integer(0);
		// if the user does not want to QUIT, keep looping
		while (!choice.equals(QUIT)) {
			// get the user's choice
			choice = Accounting.displayMenu();

			// add grocery item
			if (choice.equals(1)) {
				size = Accounting.add(invoice, size);
			}
			// display grocery item
			else if (choice.equals(2)) {
				Accounting.display(invoice, size);
			}
			// error message
			else if (!choice.equals(QUIT)) {
				System.out.println("ERROR: Please enter an integer in the range from 0 to 2");
			}
		}// end of "while"
	}

	/**A method displaying the menu for users and receiving choices of users
	 * 
	 * @return choiceOfUser that reveal what users choose
	 */
	public static Integer displayMenu() {

		//data fields
		Integer choiceOfUser = new Integer(3);
		// set up scanner
		Scanner keyboardInput = new Scanner(System.in);
		// display menu
		System.out.println();
		System.out.println("\t Invoice LIST MENU");
		System.out.println("\t Enter 1 to Add invoice");
		System.out.println("\t Enter 2 to print all invoices");
		System.out.println("\t Enter 0 to Quit");
		System.out.print("\tEnter your choice: ");
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

	/**
	 * Adds an item to an array 
	 * @param inv is the invoice list
	 * @param listSize is the size of the invoice list
	 * @return new size of the invoice list
	 */
	public static Integer add(Invoice[] inv, Integer listSize) {
		//check if listSize if more than 5
		// if so, reset the size to 0
		if(listSize == 5){
			listSize = 0;
		}
		//date field
		int invoiceNumber = listSize + 1;
		double total = 0;
		String customer = "";
		// set up scanner
		Scanner keyboard = new Scanner(System.in);
		// get input from user
		System.out.print("Enter Total: ");
		try {
			total = keyboard.nextDouble();
		}
		catch (InputMismatchException exception) {
			System.out.println("Your input is not an double number");
			System.exit(0); // end program
		}
		if(total > 20000){
			System.out.println("Your input cannot be more than 20000.0");
			System.exit(0); // end program
		}
		else if (total < 1){
			System.out.println("Your input cannot be less than 1");
			System.exit(0); // end program
		}
		customer = keyboard.nextLine();
		System.out.print("Enter Customer: ");
		customer = keyboard.nextLine();
		Invoice input = new Invoice(total, customer, invoiceNumber);
		// add to the end of the array
		inv[listSize] = input;
		System.out.println("The invoice you just added was " + input + ".");
		// add one to the size (one item to end of list)
		return listSize + 1;
	}

	/**
	 * Displays a invoice list
	 * 
	 * @param inv is the invoice list
	 * @param listSize is the size of the invoice list
	 */
	public static void display(Invoice[] inv, Integer listSize) {
		System.out.println("The invoice(s) you added is(are) :");
		// loop through the array
		for (int i = 0; i < listSize; i++) {
			//print all the invoices
			System.out.println(inv[i]);
		}
	}  
}

