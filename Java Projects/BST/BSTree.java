/**
 * Book class for a binary search tree
 * 
 * @author Yixing Zheng
 *
 */
public class BSTree <Bnode extends java.lang.Comparable <Book>> {

	//data fields
	private BNode root = null;
	Book book;

	/**
	 * Get the information of search key
	 * 
	 * @param searchKey
	 * 			the item with the key value only
	 */
	public void nodeInformation(Book searchKey){
		// method get() returns the data stored at the current node
		Book book1 = this.get(searchKey);
		// display the data stored in the current node
		System.out.println("current node = " + book1);
		System.out.println();
	}// end of the nodeInformation() method

	/** constructor */
	public BSTree( ){
		// data fields already initialized
	}

	public String insertBNode(Book book, int key){
		if (book.getTitle() == "title"){
			System.out.println("Cannot have same title for a book.");
		}
		else if (key < 1 || key > 200){
			System.out.println("Please keep the Key (ISBN) between 1 and 200.");
		}
		return " ";	
	}

	/**
	 * adds a book to the tree
	 * 
	 * @param book
	 */
	public void add(Book book){
		// calls a recursive, private method
		//cannot get direct access to the root outside the class
		root = add(root, book);
	}

	/**
	 * adds a book to the tree
	 * 
	 * @param node
	 * 			is the root of the tree/subtree
	 * @param book
	 * 			is the object to be added
	 */
	private BNode add(BNode node, Book book){
		// base case: empty tree or end of a leaf
		if (node == null){
			return new BNode (null, book, null);
		}
		// base case: duplicate node, so throw exception
		else if (book.compareTo(node.getBook()) == 0){
			throw new BookException("No duplicate books are allowed!");
		}
		// recursive case: if book is less than current node
		// then more to left child node
		else if (book.compareTo(node.getBook()) < 0){
			// set the node's left child to the left subtree with book added
			node.setLChild(this.add(node.getLChild(), book));
			return node;
		}
		// recursive case: if book is more than current node
		// then more to right child node
		else {
			// set the node's right child to the right subtree with book added
			node.setRChild(this.add(node.getRChild(), book));
			return node;
		}
	}

	/**
	 * called automatically by println / print method
	 * 
	 * @return an preorder String of the tree
	 */
	public String toSring(){
		return this.preOrder(root);
	}

	/**
	 * preOrder traversal
	 * 
	 * @return an preorder String of the tree
	 */
	public String preOrder(){
		return this.preOrder(root);
	}

	/**
	 * preOrder display of nodes, with newline between each node
	 * 
	 * @param node
	 * 			is the root of the tree
	 * @return an preorder String of the tree
	 */
	private String preOrder(BNode node){
		String displayNodes = "";
		if (node != null) {
			displayNodes = displayNodes + node.toString() + "\n";
			displayNodes = displayNodes + this.preOrder(node.getLChild());
			displayNodes = displayNodes + this.preOrder(node.getRChild());
		}
		return displayNodes;
	}

	/**
	 * gets an item form the tree with the same search key
	 * 
	 * @param searchKey1
	 * 				is an object storing only the search key
	 */
	public Book get(Book searchKey1){
		// cannot get direct access to the root outside the class
		return this.get(root, searchKey1);
	}

	/**
	 * gets an item from the tree with the same search key
	 * 
	 * @param node
	 *            is the root of the tree/subtree
	 * @param searchKey2
	 *            is an object storing only the search key
	 */
	private Book get(BNode node, Book searchKey2) {
		// if not found, throw exception
		if (node == null) {
			throw new BookException("Item not found!");
		} 
		else {
			// if the search key matches, return the item's address
			if (searchKey2.compareTo(node.getBook()) == 0) {
				return node.getBook();
			}
			// if the search key of the searchKey is less than the node,
			// then search the left subtree
			else if (searchKey2.compareTo(node.getBook()) < 0) {
				return this.get(node.getLChild(), searchKey2);
			}
			// if the search key of the searchKey is greater than the node,
			// then search the right subtree
			else {
				return this.get(node.getRChild(), searchKey2);
			}
		}
	}

	/**
	 * Calls a recursive method that removes an item from the tree with the same
	 * search key
	 * 
	 * @param searchKey3
	 *            is an object storing only the search key
	 */
	public void remove(Book searchKey3) {
		root = this.remove(root, searchKey3);
	}

	/**
	 * Finds the item to be removed from the tree with the same search key
	 * 
	 * @param node
	 *            is the root of the tree/subtree
	 * @param searchKey4
	 *            is an object storing only the search key
	 */
	private BNode remove(BNode node, Book searchKey4) {
		// if item not found, throw exception
		if (node == null) {
			throw new BookException("Item not found!");
		}
		// if search key is less than node's search key,
		// continue to left subtree
		else if (searchKey4.compareTo(node.getBook()) < 0) {
			node.setLChild(this.remove(node.getLChild(), searchKey4));
			return node;
		}
		// if search key is greater than node's search key,
		// continue to right subtree
		else if (searchKey4.compareTo(node.getBook()) > 0) {
			node.setRChild(this.remove(node.getRChild(), searchKey4));
			return node;
		}
		// found node containing object with same search key,
		// so delete it
		else {
			// call private method remove
			node = this.remove(node);
			return node;
		}
	}

	/**
	 * Removes leaf nodes, and nodes with one child node from the tree with the
	 * same search key & removes 2 child nodes too
	 * 
	 * @param node
	 *            is the root of the tree/subtree
	 */
	private BNode remove(BNode node) {
		// if node is a leaf,return null
		if (node.getLChild() == null && node.getRChild() == null) {
			return null;
		}
		// if node has a single right child node,
		// then return a reference to the right child node
		else if (node.getLChild() == null) {
			return node.getRChild();
		}
		// if node has a single left child node,
		// then return a reference to the left child node
		else if (node.getRChild() == null) {
			return node.getLChild();
		}
		// if the node has two child nodes
		else {
			// get next Smaller Item, which is Largest Item in Left Subtree
			// The next Smaller Item is stored at the rightmost node in the left
			// subtree.
			Book largestItemInLeftSubtree = this.getItemWithLargestSearchKey(node
					.getLChild());
			// replace the node's item with this item
			node.setBook(largestItemInLeftSubtree);
			// delete the rightmost node in the left subtree
			node.setLChild(this.removeNodeWithLargestSearchKey(node
					.getLChild()));
			return node;
		}
	}

	/**
	 * Returns the address of the item with the largest search key in the tree
	 * 
	 * @param node
	 *            is the root of the tree/subtree
	 */
	private Book getItemWithLargestSearchKey(BNode node) {
		// if no right child, then this node contains the largest item
		if (node.getRChild() == null) {
			return node.getBook();
		}
		// if not, keep looking on the right
		else {
			return this.getItemWithLargestSearchKey(node.getRChild());
		}
	}

	/**
	 * Removes the node with the largest search key
	 * 
	 * @param node
	 *            is the root of the tree/subtree
	 */
	private BNode removeNodeWithLargestSearchKey(BNode node) {
		// if no right child, then this node contains the largest item
		// so replace it with its left child
		if (node.getRChild() == null) {
			return node.getLChild();
		}
		// if not, keep looking on the right
		else {
			node.setRChild(this.removeNodeWithLargestSearchKey(node
					.getRChild()));
			return node;
		}
	}

	/**
	 * A method that prints all the books in the tree
	 * 
	 * @param root the books stored in the node
	 */
	private void printBSTree(BNode root) {
		if(root != null){
			System.out.println("The root book of your tree is:");
			System.out.println("The title of the book is " + root.getBook().getTitle() + ", the ISBN of the book is " + root.getBook().getKey() + 
					", and the quantity of the book is " + root.getBook().getQuantity() + ".");
			System.out.println("All the books you currently have in preorder:\n" + preOrder());
		}
		else {
			System.out.println("There is no book in the tree.");

		}
	}

	/**
	 * A overloaded method that can be called outside the class
	 * 
	 * @param root the books stored in the node
	 */
	public void printBSTree(){
		this.printBSTree(root);
	}

	/**
	 * Accessor method
	 * 
	 * @return the book's quantity
	 */
	public int getQuantity(){
		return book.getQuantity();
	}

	/**
	 * Mutator method
	 * 
	 * @param quantity
	 *            is the book's quantity
	 */
	public void setQuantity(int quantity){
		quantity = book.getQuantity();
	}

	/**
	 * Driver code to test class
	 * 
	 * @param commandlineArguments
	 *            are not used
	 */
	public static void main(String[] commandlineArguments) {
		// using BNode
		Book book1 = new Book ("a",3,1);
		Book book2 = new Book ("b",4,2);
		Book book3 = new Book ("c",5,3);
		Book book4 = new Book ("d",6,4);
		Book book5 = new Book ("e",7,5);
		Book book6 = new Book ("f",8,6);
		BSTree tree = new BSTree();

		System.out.println("TEST add() method:");
		tree.add(book1);
		tree.add(book3);
		tree.add(book2);
		tree.add(book6);
		tree.add(book4);
		tree.add(book5);
		System.out.println("preorder:\n" + tree.preOrder());

		// test get
		System.out.println("TEST get() method:");
		Book book7 = tree.get(book1);
		System.out.println(book7);
		Book book8 = tree.get(book3);
		System.out.println(book8);
		try {
			Book book9 = tree.get(book1);
			System.out.println(book9);
		} 
		catch (BookException exception) {
			System.out.println(exception.toString());
		}
		int key1 = tree.get(book3).getKey();
		System.out.println(key1);

		// test remove
		System.out.println("\nTEST remove() method:");
		tree.remove(book1);
		System.out.println("preorder:\n" + tree.preOrder());
		tree.remove(book2);
		System.out.println("preorder:\n" + tree.preOrder());
		tree.remove(book3);
		System.out.println("preorder:\n" + tree.preOrder());
		tree.printBSTree();

		//set and get quantity
		System.out.println(book1.getQuantity());
		book1.setQuantity(5);
		System.out.println(book1.getQuantity());
	}
}
