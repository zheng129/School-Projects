/**
 * Driver class for the books
 * 
 * @author Yixing Zheng
 */

import java.util.InputMismatchException;
import java.util.Scanner;

public class Bookstore {

	/**The main method used to test and drive the program
	 * 
	 */
	public static void main(String[] args) {

		BSTree tree = new BSTree();

		//data fields
		String title = new String ("title");
		int key = 0;
		int quantity = 0;
		int bought = 0;
		int sold = 0;

		// user's choice for Menu
		Integer choice = new Integer(5);
		// choice for ending program
		final Integer QUIT = new Integer(0);

		// set up scanner
		Scanner keyboard = new Scanner(System.in);

		while (!choice.equals(QUIT)) {
			// get the user's choice
			choice = Bookstore.displayMenu();
			switch(choice){

			// add a new book to the tree
			case 1: 
				System.out.println("Enter the key (ISBN) of the book: ");
				try {
					// non-integer input will throw InputMismatchException
					key = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer in the range from 1 to 200");
					System.exit(0);
				}
				System.out.println("Enter the numbers of the book: ");
				try {
					// non-integer input will throw InputMismatchException
					quantity = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer as quantity of a book.");
					System.out.println("Notice: The book will be added with a 0 quantity.");
				}
				keyboard.nextLine();
				System.out.println("Enter the title of the book: ");
				title = keyboard.nextLine();
				Book input = new Book(title, key, quantity);
				tree.add(input);
				System.out.println("The book you just added was: " + input + ".");
				break;

				// add more copies to a book already in the tree
			case 2: 
				System.out.println("Enter the key (ISBN) of the book you purchased: ");
				try {
					// non-integer input will throw InputMismatchException
					key = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer in the range from 1 to 200");
					System.exit(0);
				}
				Book book = new Book(key);
				Book bookiwant = tree.get(book);
				System.out.println("Enter the number of the book you purchased: ");
				try {
					// non-integer input will throw InputMismatchException
					bought = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer as quantity of a book.");
				}
				quantity = tree.get(book).getQuantity() + bought;
				bookiwant.setQuantity(quantity);
				System.out.println("Now you have " + quantity + " copies of " + tree.get(book).getTitle() + ".");
				break;

				// remove some copies from a book already in the tree
			case 3:
				System.out.println("Enter the key (ISBN) of the book you sold: ");
				try {
					// non-integer input will throw InputMismatchException
					key = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer in the range from 1 to 200");
					System.exit(0);
				}
				Book book1 = new Book(key);
				Book bookiwant1 = tree.get(book1);
				System.out.println("Enter the number of the book you sold: ");
				try {
					// non-integer input will throw InputMismatchException
					sold = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer as quantity of a book.");
				}
				quantity = tree.get(book1).getQuantity() - sold;
				if(quantity < 0){
					int numbers = quantity;
					System.out.println("You have only " + bookiwant1.getQuantity() + " copies can be sold, "
							+ "and now you have sold them all.");
					System.out.println("Reminder: You also need " + (numbers * -1) + " more copies in order to finish this transaction.");
					bookiwant1.setQuantity(0);
				}
				else {
					bookiwant1.setQuantity(quantity);
					System.out.println("Now you have " + quantity + " copies of " + tree.get(book1).getTitle() + ".");
				}
				break;

				// print out all the book(s) you have in the tree
			case 4:
				tree.printBSTree();
				break;

				// delete a book from your tree
			case 5:
				System.out.println("Enter the key (ISBN) of the book you want to remove: ");
				try {
					// non-integer input will throw InputMismatchException
					key = keyboard.nextInt();
				} catch (InputMismatchException exception) {
					System.out.println("ERROR: Please enter an integer in the range from 1 to 200");
					System.exit(0);
				}
				Book book2 = new Book(key);
				Book bookiwant2 = tree.get(book2);
				tree.remove(bookiwant2);
				System.out.println("The book " + bookiwant2 + " has been removed successfully");
				System.out.println("The root book of your tree is:");
				tree.printBSTree();
				System.out.println("All the books you currently have in preorder:\n" + tree.preOrder());
				break;

				// default case for integers inputed that not in the range
			default: 
				if (choice > 6|| choice < 0){
					System.out.println("ERROR: Please enter an integer in the range from 0 to 5");
				}
			}
		}
	}

	/**A method displaying the menu for users and receiving choices of users
	 * 
	 * @return choiceOfUser that reveal what users choose
	 */
	public static Integer displayMenu() {
		//data fields
		Integer choiceOfUser = new Integer(5);
		// set up scanner
		Scanner keyboardInput = new Scanner(System.in);

		// display menu
		System.out.println();
		System.out.println("\t What do you want to do?");
		System.out.println("\t 1. Add new books to the tree");
		System.out.println("\t 2. Buy a book that already in the tree");
		System.out.println("\t 3. Sell a book that already in the tree");
		System.out.println("\t 4. Show all the books in the tree");
		System.out.println("\t 5. remove a book from the tree");
		System.out.println("\t 0. End this program ");
		// get input from user
		try {
			// non-integer input will throw InputMismatchException
			choiceOfUser = keyboardInput.nextInt();
		} catch (InputMismatchException exception) {
			System.out.println("ERROR: Please enter an integer in the range from 0 to 5");
			System.exit(0);
		}
		System.out.println();
		return choiceOfUser;
	}
}
