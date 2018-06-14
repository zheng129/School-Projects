import java.util.EmptyStackException;

/**
 * A class contains all the methods of stack
 * 
 * @author Yixing Zheng
 */
public class StackOfInvoices implements Stack {

	// data fields
	private Node top = null;
	// Total number of items, which is used
	// for error checking and node removal.
	final int MAX_SIZE = new Integer(5);

	/**Constructor*/
	public StackOfInvoices(){
		//data fields already initialized
	}

	/**Pushes an item onto the top of this stack 
	 * @param inv the invoice that is pushed on the stack
	 */
	public void push(Invoice inv) {
		if(size() == MAX_SIZE){
			throw new IllegalStateException("Cannot add to full stack");
		}
		//top is assigned a Node, 
		//which points to the new invoice
		//and the previous top Node.  
		top = new Node(inv,top);

	}

	/**Removes the object at the top of stack 
	 * and returns the address of this object
	 * @return an addressed to the top invoice on the stack 
	 * @exception EmptyStackException if the stack is empty
	 */
	public Invoice pop() {
		//check to see if stack is empty		 
		if(this.isEmpty()){
			throw new EmptyStackException(); 
		}
		//Store a temporary variable 
		//that points to the top of stack.		
		Invoice poped = top.getInvoice();
		// Print out the invoice that removed
		System.out.println(top.toString());
		//Take the first element off the stack, 
		//by pointing the top to the next node.			
		top = top.getNext();
		//Return pointer (address) to top element in stack			
		return poped;
	}

	/**Looks at the object at the top of the stack 
	 * without removing it from the stack.
	 * @return an addressed to the top invoice on the stack 
	 * @exception EmptyStackException if the stack is empty
	 */  
	public String peek() throws EmptyStackException {
		//check to see if empty
		if(this.isEmpty()){
			throw new EmptyStackException();
		}
		//return pointer (address) to top element in stack
		//but do NOT take it off the stack!			
		return top.toString();
	}

	/**pop and print one element at the time until the stack is empty
	 * 
	 */
	public void emptyAndPrint() {
		//check to see if stack is empty
		if(this.isEmpty()){
			throw new EmptyStackException();
		}
		while(!this.isEmpty()){
			pop();
		}
	}

	/**The size of the stack
	 * 
	 * @return the number of elements in the stack
	 */
	public int size() {
		int count = 0;
		for (Node node = top; node != null; node = node.getNext()) {
			count++;
		}
		return count;

	}

	/**Tests if the stack is empty
	 * @return true/false if empty/not empty
	 */  
	public boolean isEmpty() {
		return top == null;
	}
}//end of class
