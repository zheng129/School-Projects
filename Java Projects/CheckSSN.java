//Yixing Zheng
import java.util.*;
public class CheckSSN {

	public static void main(String[] args) {
		Scanner scanner; 
		scanner = new Scanner (System.in); 
		
		System.out.println("Enter a SSN");
		String ssn = scanner.nextLine();
		
		char n1 = ssn.charAt(3); 
	    char n2 = ssn.charAt(6);
		
	    
		if (ssn.length()!= 11){
			System.out.println(ssn + " is an invalid social security number");
			}
		else if (n2 == '-' && n1 == '-') {
			System.out.println(ssn + " is a valid social security number");
	}
		else{
			System.out.println(ssn + " is an invalid social security number");
		}
		}
}
