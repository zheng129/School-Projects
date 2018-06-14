//Yixing Zheng
import java.util.*;
public class WindChill {

	public static void main(String[] args) {
		Scanner scanner; // Variable to reference Scanner object
		scanner = new Scanner (System.in); // Scanner object created
		
		
		double V,T;
		
		System.out.println("Enter the wind speed miles per hour --->");
		V = scanner.nextDouble();
		
		if(V >= 2){
			System.out.println("Enter the temperature in Fahrenheit --->");
			T = scanner.nextDouble();
			if(T > Math.abs(-58) );
			if(T < 41);
			System.out.println("The wind chill index is " + (35.74 + 0.6215 * T - 35.75 * Math.pow(V, 0.16) + 0.4275 * T * Math.pow(V, 0.16) ));
		}
		else{
			System.out.println("The wind speed should be equal or greater than 2, the temperature should be between -58 and 41");
		}
		
	}
	
}