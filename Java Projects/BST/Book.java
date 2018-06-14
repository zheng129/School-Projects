/**
 * A book with title, key (ISBN), and quantity data fields
 * 
 * @author Yixing Zheng
 */
public class Book implements java.lang.Comparable<Book> {
	//data fields
	private String title = new String ("title");
	private int key = 0;
	private int quantity = 0;

	/**
	 * Constructor
	 * 
	 * @param Title
	 * 			is the book's title
	 * @param key
	 * 			is the book's ISBN
	 * @param quantity
	 * 			is the book's quantity
	 */
	public Book (String Title, int key, int quantity) throws BookException{
		// ISBN error checking
		// keep the key between 1 and 200
		if (key < 1 || key > 200){
			throw new BookException(
					"Please keep the Key (ISBN) as a number between 1 and 200.");
		}
		else if (quantity < 0) {
			throw new BookException("Cannot have less than 0 book.");
		}
		title = Title;
		this.key = key;
		this.quantity = quantity;
	}

	/**
	 * Overloaded constructor for String data input
	 * 
	 * @param Title
	 * 			is the book's title
	 * @param key
	 * 			is the book's ISBN
	 * @param quantity
	 * 			is the book's quantity
	 */
	public Book(String Title, String key, String quantity) throws BookException {
		// calls the 1st constructor
		// converts strings to appropriate data type
		this(Title, Integer.parseInt(key), Integer.parseInt(quantity));
	}

	/**
	 * Overloaded constructor for "searchKey" Book (only contains the ISBN, which is 
	 * the search key)
	 * @param key
	 * 			is the book's ISBN
	 */
	public Book(int key) throws BookException {
		// calls 1st constructor
		this("Search Key", key, 1);
	}

	/**
	 * Overloaded constructor for "searchKey" Book (only contains the ISBN, which is 
	 * the search key)
	 * @param key
	 * 			is the book's ISBN
	 */
	public Book(String key) throws BookException {
		// convert from String & call 1st constructor
		// put in placeholder values
		this("Search Key", Integer.parseInt(key), 1);
	}

	/**
	 * Automatically called by println() or print() method
	 * 
	 * @return a String of the book
	 */
	public String toString(){
		return title + " "+ key + " " + quantity;
	}

	/**
	 * Method to campare objects
	 * 
	 * @param book2
	 * 			is a second book
	 * @return 0 is equal, negative if(book1 < book2), positive if (book1 > book2)
	 */
	public int compareTo(Book book2){
		return this.key - book2.getKey();
	}

	/**
	 * Accessor method
	 * 
	 * @return the book's title
	 */
	public String getTitle(){
		return title;
	}

	/**
	 * Accessor method
	 * 
	 * @return the book's ISBN
	 */
	public int getKey(){
		return key;
	}

	/**
	 * Mutator method
	 * 
	 * @param quantity
	 *            is the book's quantity
	 */
	public void setQuantity(String quantity){
		// convert from string & call 1st setQuantity() method
		this.setQuantity(Integer.parseInt(quantity));
	}

	/**
	 * Mutator method
	 * 
	 * @param quantity
	 *            is the book's quantity
	 */
	public void setQuantity(int quantity) throws BookException{
		if (quantity < 0) {
			throw new BookException("Cannot have less than 0 item.");
		}
		this.quantity = quantity;
	}

	/**
	 * Accessor method
	 * 
	 * @return the book's quantity
	 */
	public int getQuantity(){
		return quantity;
	}

	/**
	 * Method main is used as a driver to test the class
	 * 
	 * @param args
	 *            is not used
	 */
	public static void main(String[] args) {
		// test constructors & toString method
		System.out.println("TEST constructors and toString() method:");
		Book book1 = new Book("nami",123, 123);
		System.out.println(book1.toString());
		Book book2 = new Book("7000", 67, 4);
		System.out.println(book2.toString());
		// variable "searchKey" only contains the ISBN search key
		Book searchKey = new Book(12);
		System.out.println(searchKey);

		// test compareTo method
		System.out.println("\nTEST compareTo() method");
		System.out.println("book1 = " + book1.toString());
		System.out.println("book2 = " + book2.toString());
		System.out.println("book1.compareTo(book2) = "
				+ book1.compareTo(book2));
		System.out.println("book2.compareTo(book1) = "
				+ book2.compareTo(book1));
		System.out.println("searchKey = " + searchKey);
		System.out.println("book2.compareTo(searchKey) = "
				+ book2.compareTo(searchKey));

		// test set method
		System.out.println("\nTEST set method:");
		book2.setQuantity(9000000);
		System.out.println("book2 = " + book2.toString());

		// check exceptions
		System.out.println("\nTEST exceptions:");
		try {
			book1 = new Book("hey",1000, 123);
		} catch (BookException exception) {
			System.out.println(exception.toString());
		}
		try {
			book1 = new Book("hey",100, -123);
		} catch (BookException exception) {
			System.out.println(exception.toString());
		}
	}// end main

}// end of class definition
