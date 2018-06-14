/**
 * Tree class for a Huffman node
 * 
 * @author Yixing Zheng
 */
class HNode extends HTree {

	// data fields
	public final HTree left, right; // subtrees

	/**
	 * Constructor
	 * 
	 * @param l
	 * 			is the left subtree
	 * @param r
	 * 			is the right subtree
	 */		
	public HNode(HTree l, HTree r) {
		super(l.frequency + r.frequency);
		left = l;
		right = r;
	}
}// end of class