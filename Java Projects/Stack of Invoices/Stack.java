
abstract interface Stack {

	abstract void push(Invoice inv);
	/* will add an invoice to the stack */ 

	abstract Invoice pop( );
	/* will remove one element from the stack */

	abstract String peek( );
	/* will print the invoice at the top of the stack */

	abstract void emptyAndPrint ( );
	/* will pop and print one element at the time until the stack is empty*/

	abstract int size( );
	/*returns the number of elements in the stack*/

	abstract boolean isEmpty( );
	/*returns true if the stack is empty or false otherwise */

} //ends class


