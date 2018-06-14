//Yixing Zheng
import java.util.Scanner;
public class QuadraticEquation {

	public static void main(String[] args) {
		Scanner scanner; // Variable to reference Scanner object
		scanner = new Scanner (System.in); // Scanner object created

		Double a,b,c,d;
		System.out.println("Enter a, b, c --->");
		a = scanner.nextDouble();
		b = scanner.nextDouble();
		c = scanner.nextDouble();
		d = (Math.pow(b * b - 4 * a * c, 0.5));

		if(d > 0){
			System.out.println("The roots are " + (((-b) + d) / 2 * a) + " and " + (((-b) - d) / 2 * a));
					}
		else if(d == 0){
			System.out.println("The root is " + (((-b) + d) / 2 * a));
								}
		else{
			System.out.println("The equation has no real roots");
		}

	}
}
