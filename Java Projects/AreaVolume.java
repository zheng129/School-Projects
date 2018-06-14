//Yixing Zheng
import java.util.*;
public class AreaVolume {

	public static void main(String[] args) {
		Scanner scanner; // Variable to reference Scanner object
		scanner = new Scanner (System.in); // Scanner object created
		
		//area and volume of cube, sphere, cylinder, and regular tetrahedron
		
		//sphere v =4/3pi r*r*r a = 4 pi r*r
		//cylinder v = pi h*r*r  a = 2Pirh+2Pir*r
		//tetraedron V= edge*edge*edge/6√2 a=√3 edge*edge
		
		
		double L,H,R;
		double Pi = 3.14;
		
		//A&V for cube
		System.out.println("Enter length of the side for calculating area and volume of cube --->");
		L = scanner.nextDouble();
		
		System.out.println("The area of cube is " + 6 * L * L);
		System.out.println("The volume of cube is " + L * L * L);

		//A&V for sphere
		System.out.println("Enter radius for calculating area and volume of sphere --->");
		R = scanner.nextDouble();
		
		System.out.println("The area of sphere is " + 4/3 * Pi * Math.pow(R, 3) );
		System.out.println("The volume of sphere is " + 4 * Pi * Math.pow(R, 2));
		
		//A&V for cylinder
		System.out.println("Enter radius and height for calculating area and volume of cylinder --->");
		R = scanner.nextDouble();
		H = scanner.nextDouble();
		
		System.out.println("The area of cylinder is " + (2 * Pi * Math.pow(R, 2)) + 2 * Pi * R * H);
		System.out.println("The volume of cylinder is " + H * Pi * Math.pow(R, 2));
		
		//A&V for regular tetrahedron
		System.out.println("Enter length of the side for calculating area and volume of regular tetrahedron --->");
		L = scanner.nextDouble();
		
		System.out.println("The area of regular tetrahedron is " + Math.pow(3, 1/2) * Math.pow(L, 2));
		System.out.println("The volume of regular tetrahedron is " + Math.pow(L, 3) / 6 * Math.pow(2, 1/2) );
	
	}

}

