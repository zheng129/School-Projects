/**
 * An Abstract class for Huffman tree
 * 
 * @author Yixing Zheng
 *
 */
abstract class HTree implements Comparable<HTree> {
	
	// data fields
	public final int frequency; // the frequency of this tree
	public HTree(int freq) { frequency = freq; }

	/**
	 * Method to compare objects
	 * 
	 * @param tree
	 * 			is a second tree
	 * @return the difference of frequencies
	 */
	public int compareTo(HTree tree) {
		return frequency - tree.frequency;
	}
}// end of class