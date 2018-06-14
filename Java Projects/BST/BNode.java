/**
 * Book class for a binary node
 * 
 * @author Yixing Zheng
 */
public class BNode {
	// data fields
	private Book book;
	private BNode left;
	private BNode right;

	/**
	 * Constructor
	 * 
	 * @param b
	 * 			is the address of the object that is stored by the node
	 * @param lChild
	 * 			is the address of the left child
	 * @param rChild
	 * 			is the address of the right child
	 */			
	public BNode(BNode lChild, Book b, BNode rChild){
		book = b;
		left = lChild;
		right = rChild;
	}

	/**
	 * Automatically called by println() or print() method
	 * 
	 * @return the item's toString method
	 */
	public String toString(){
		return book.toString();

	}

	/**
	 * Accessor method
	 * 
	 * @return the item's address
	 */
	public int getKey(){
		return book.getKey();
	}

	/**
	 * Accessor method
	 * 
	 * @return the item's address
	 */
	public Book getBook(){
		return book;
	}

	/**
	 * Mutator method
	 * 
	 * @param book
	 *            is the item's address
	 */
	public void setBook(Book book) {
		this.book = book;
	}

	/**
	 * Accessor method
	 * 
	 * @return the left child's address
	 */
	public BNode getLChild(){
		return left;
	}

	/**
	 * Accessor method
	 * 
	 * @return the right child's address
	 */
	public BNode getRChild(){
		return right;
	}

	/**
	 * Mutator method
	 * 
	 * @param newLChild
	 * 				is the left child's address
	 */
	public void setLChild(BNode newLChild){
		left = newLChild;
	}

	/**
	 * Mutator method
	 * 
	 * @param newLChild
	 * 				is the right child's address
	 */
	public void setRChild(BNode newRChild){
		right = newRChild;
	}

	/**
	 * Driver code to test class
	 * 
	 * @param commandlineArguments
	 *            are not used
	 */
	public static void main(String[] commandlineArguments) {
		// using BNode
		Book book1 = new Book ("a",3,5);
		Book book2 = new Book ("b",4,6);
		Book book3 = new Book ("c",5,7);
		System.out.println("test 3 BNode Book nodes:");
		BNode nodeA = new BNode (null, book1, null);
		BNode nodeB = new BNode (null, book2, null);
		BNode nodeC = new BNode (nodeA, book3, nodeB);
		System.out.println("root = " + nodeC.toString());
		System.out.println("left child = " + nodeC.getLChild().toString());
		System.out.println("right child = " + nodeC.getRChild().toString());
		//change left child's data to "X"
		BNode nodeX = nodeC.getLChild();
		System.out.println("NodeX = " + nodeX.toString());
		System.out.println(nodeA.toString());

		// test accessor and mutator methods
		System.out.println("\ntest accessor and mutator methods:");
		System.out.println("The key of book1 is " + book1.getKey());
		System.out.println("right child = " + nodeC.getRChild());
		System.out.println("(switch left and right child nodes)");
		nodeC.setLChild(nodeB);
		nodeC.setRChild(nodeA);
		System.out.println("left child = " + nodeC.getLChild());
		System.out.println("right child = " + nodeC.getRChild());
	}//end of main
}
