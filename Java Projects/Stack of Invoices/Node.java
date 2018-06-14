/**
 * A class holds nodes
 * 
 * @author Yixing Zheng
 */
public class Node {

	// data fields (reference variables)
	// data stores an object of any class
	private Invoice invoice;
	// next points to the next node
	private Node next;
	

	/**
	 * Constructor - Used To Create EAch Object & Initialize DAta Fields.
	 * 
	 * @param inv
	 *            initializes the data reference variable.
	 * @param next
	 *            initializes the next reference variable..
	 */
	public Node(Invoice inv, Node next){
		this.invoice = inv;
		this.next = next;
	}

	/**
	 * This Is An "Accessor" Method - Used To Get A Data Field.
	 * 
	 * @return invoice
	 */
	public Invoice getInvoice( ){
		return invoice;
	}

	/**
	 * This Is An "Accessor" Method - Used To Get A Data Field.
	 * 
	 * @return the address to the next node
	 */
	public Node getNext( ){
		return next;
	}

	/**
	 * This Is A "Mutator" Method - Used To Set A Data Field.
	 * 
	 * @param newInvoice
	 *           	is a pointer to an object.
	 */
	public void setInvoice(Invoice newInvoice){
		invoice = newInvoice;
	}   

	/**
	 * This Is A "Mutator" Method - Used To Set A Data Field.
	 * 
	 * @param nextNode
	 *            is a pointer to the next node.
	 */
	public void setNext(Node nextNode){
		next = nextNode;
	}
	
	/**
	 * Used to Display The Data Stored In Each Node.
	 * 
	 * @return a String for the invoice
	 */
	public String toString( ){
		return invoice.toString();
	}     
}//end of class
