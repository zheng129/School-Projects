/**
 * Driver class for the Huffman tree
 * 
 * @author Yixing Zheng
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Huffman extends HCode{

	/**
	 * The main method used to test and drive the program
	 */
	public static void main(String[] args) throws FileNotFoundException {

		// make a scanner
		File file = new File("frequencies.txt");
		Scanner sc = new Scanner(file);

		// data fields
		int[] frequency = new int [128];
		int counter = 0;
		int number = 0;
		String input = sc.nextLine();
		char letter = 0;
		HTree tree = null;

		while(sc.hasNextLine()) {
			if (counter % 2 == 0){
				letter = input.charAt(0);
			} else {
				number = Integer.parseInt(input);
				frequency[letter] = number;
				tree = buildTree(frequency);
			}
			counter++;
			input = sc.nextLine();
		}
		// print out results
		System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
		printCodes(tree, new StringBuffer());
	}
}// end of class

