/**
 * code class for Huffman tree
 * 
 * @author Yixing Zheng
 */

import java.util.PriorityQueue;

public class HCode {

	/**
	 * A method to build the Huffman tree
	 * 
	 * @param charFreqs
	 * 			is the frequency of the character
	 * 
	 * @return A character of the PriorityQueue
	 *
	 */
	public static HTree buildTree(int[] charFreqs) {
		PriorityQueue<HTree> trees = new PriorityQueue<HTree>();

		for (int i = 0; i < charFreqs.length; i++)
			if (charFreqs[i] > 0)
				trees.offer(new HLeaf(charFreqs[i], (char)i));

		assert trees.size() > 0;

		while (trees.size() > 1) {

			HTree a = trees.poll();
			HTree b = trees.poll();

			trees.offer(new HNode(a, b));
		}
		return trees.poll();
	}

	/**
	 * A method to print out the Huffman tree
	 * 
	 * @param tree
	 * 			is the Huffman tree
	 * 
	 * @param prefix
	 * 			is a String to hold the values 0 or 1 for the Huffman tree
	 *
	 */
	public static void printCodes(HTree tree, StringBuffer prefix) {
		assert tree != null;
		if (tree instanceof HLeaf) {
			HLeaf leaf = (HLeaf)tree;

			// print out character, frequency, and code for this leaf (which is just the prefix)
			System.out.println(leaf.value + "\t" + leaf.frequency + "\t" + prefix);

		} else if (tree instanceof HNode) {
			HNode node = (HNode)tree;

			// traverse left
			prefix.append('0');
			printCodes(node.left, prefix);
			prefix.deleteCharAt(prefix.length()-1);

			// traverse right
			prefix.append('1');
			printCodes(node.right, prefix);
			prefix.deleteCharAt(prefix.length()-1);
		}
	}
}// end of class