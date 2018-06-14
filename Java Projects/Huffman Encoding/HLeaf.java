/**
 * a leaf class for Huffman tree
 * 
 * @author Yixing Zheng
 */

class HLeaf extends HTree {

	// data fields
	public final char value; // the character this leaf represents

	/**
	 * Constructor
	 * 
	 * @param freq
	 * 			is the frequency
	 * @param val
	 * 			is the value of the character
	 */
	public HLeaf(int freq, char val) {
		super(freq);
		value = val;
	}
}// end of class