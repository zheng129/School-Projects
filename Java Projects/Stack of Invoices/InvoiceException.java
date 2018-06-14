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
}//end of class
