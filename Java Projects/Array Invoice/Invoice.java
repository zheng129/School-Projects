/**
 *A class that Represents a list of invoice
 * 
 * @author Yixing Zheng
 */
public class Invoice {

	// initialize data fields to default
	private double total;
	private String customer;
	private int invoiceNumber;

	/**
	 * Initializes respective data fields
	 * 
	 * @param t
	 *            is the total of invoice
	 * @param c
	 *            is the name of customer
	 * @param i
	 *            is the number of invoice
	 * @exception ItemException
	 *                if total is less than 1 (one)
	 *                if total is more than 20,000 (twenty thousand)
	 */
	public Invoice (double t, String c, int i){
		// cannot have 0 or negative number of items
		if (t < 1) {
			throw new InvoiceException("Cannot have less than 1 total.");
		}
		// cannot have 20000 or more items
		else if (t > 20000)
			throw new InvoiceException("Cannot have more than 20,000 total.");
		// change data fields
		customer = c;
		invoiceNumber = i;
		total = t;
	}

	/**
	 * This Is A "Mutator" Method - Used To Set A Data Field.
	 * 
	 * @param t
	 *            is the total
	 * @exception ItemException
	 *                if t is less than 1 (one)
	 *                if total is more than 20,000 (twenty thousand)
	 */
	public void setTotal(double t) throws InvoiceException {
		if (t < 1) {
			throw new InvoiceException("Cannot have less than 1 item.");
		}
		else if (t > 20000)
			throw new InvoiceException("Cannot have more than 20,000 total.");
		//change data field
		total = t;

	}

	/**
	 * This Is An "Accessor" Method - Used To Get A Data Field.
	 * 
	 * @return the total of items
	 */
	public double getTotal(){
		return total;
	}

	/**
	 * This Is An "Accessor" Method - Used To Get A Data Field.
	 * 
	 * @return the name of customer
	 */
	public String getCustomer(){
		return customer;
	}

	/**
	 * This Is An "Accessor" Method - Used To Get A Data Field.
	 * 
	 * @return the name of customer
	 */
	public int getInvoiceNumber(){
		return invoiceNumber;
	}

	/**
	 * Automatically called by println() or print()
	 * 
	 * @return three data fields separted by a comma (,)
	 */
	public String toString(){
		return invoiceNumber + " , " + getTotal() + " , " + customer;
	}
	
	String spell(double total){
		total = getTotal();
		return "I don't know how to do this one.";
	}
	
	/**
	 * An Exception for use with the Invoice class
	 * 
	 * @author Yixing Zheng
	 */
	public class InvoiceException extends RuntimeException {
		/**
		 * Constructor
		 * 
		 * @param message Describes the cause of the error
		 */
		public InvoiceException(String message) {
			super(message);
		}
	}

}//end of class


