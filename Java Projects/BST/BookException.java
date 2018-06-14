/**
 * A exception class for books
 * 
 * @author Yixing Zheng
 */
public class BookException extends RuntimeException {

	/**
	 * @param message 
	 * 			is the cause of the error
	 * 
	 */
	public BookException(String message){
		super(message);
	}
}// end class definition
