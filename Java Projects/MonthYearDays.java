//Yixing Zheng
import java.util.*;
public class MonthYearDays {

	public static void main(String[] args) {
		Scanner scanner;
		scanner = new Scanner (System.in); 
		
		int Month,Year;
		
		System.out.print("Enter year  (yyyy): ");
		Year = scanner.nextInt();
		
		System.out.print("Enter month (1-12): ");
		Month = scanner.nextInt();
		
		// Check if the year is a leap year
		boolean isLeapYear = (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
		
		if(isLeapYear){
			switch(Month){
			case 1: System.out.print("January, " + Year + " has 31 days" );
			break;
			case 2: System.out.print("February, " + Year + " has 29 days" );
			break;
			case 3: System.out.print("March, " + Year + " has 31 days" );
			break;
			case 4: System.out.print("April, " + Year + " has 30 days" );
			break;
			case 5: System.out.print("May, " + Year + " has 31 days" );
			break;
			case 6: System.out.print("June , " + Year + " has 30 days" );
			break;
			case 7: System.out.print("July, " + Year + " has 31 days" );
			break;
			case 8: System.out.print("August, " + Year + " has 31 days" );
			break;
			case 9: System.out.print("September, " + Year + " has 30 days" );
			break;
			case 10: System.out.print("October, " + Year + " has 31 days" );
			break;
			case 11: System.out.print("November, " + Year + " has 30 days" );
			break;
			case 12: System.out.print("December, " + Year + " has 31 days" );
			break;}
						}
		
		else{
			switch(Month){
			case 1: System.out.print("January, " + Year + " has 31 days" );
			break;
			case 2: System.out.print("February, " + Year + " has 28 days" );
			break;
			case 3: System.out.print("March, " + Year + " has 31 days" );
			break;
			case 4: System.out.print("April, " + Year + " has 30 days" );
			break;
			case 5: System.out.print("May, " + Year + " has 31 days" );
			break;
			case 6: System.out.print("June , " + Year + " has 30 days" );
			break;
			case 7: System.out.print("July, " + Year + " has 31 days" );
			break;
			case 8: System.out.print("August, " + Year + " has 31 days" );
			break;
			case 9: System.out.print("September, " + Year + " has 30 days" );
			break;
			case 10: System.out.print("October, " + Year + " has 31 days" );
			break;
			case 11: System.out.print("November, " + Year + " has 30 days" );
			break;
			case 12: System.out.print("December, " + Year + " has 31 days" );
			break;}
		
						}
	}
}
