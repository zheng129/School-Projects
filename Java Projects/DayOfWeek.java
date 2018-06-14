//Yixing Zheng
import java.util.*;
public class DayOfWeek {

	public static void main(String[] args) {
		Scanner scanner;
		scanner = new Scanner (System.in); 
		
		int Day,Week,Month,Year,Century;
		
		System.out.print("Enter year  (yyyy): ");
		Year = scanner.nextInt();
		
		System.out.print("Enter month (1-12): ");
		Month = scanner.nextInt();
		
		System.out.print("Enter day   (1-31): ");
		Day = scanner.nextInt();
		
		// Check if the year is a leap year
		boolean isLeapYear = (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

		switch (Month){
		case 1: if(Day < 31){}
				else{Month=0;}
				break;
		case 2:
				break;
		case 3: if(Day < 31){}
				else{Month=0;}		
				break;
		case 4: if(Day < 30){}
				else{Month=0;}
				break;
		case 5: if(Day < 31){}
				else{Month=0;}
				break;
		case 6: if(Day < 30){}
				else{Month=0;}
				break;
		case 7: if(Day < 31){}
				else{Month=0;}
				break;
		case 8: if(Day < 31){}
				else{Month=0;}
				break;
		case 9: if(Day < 30){}
				else{Month=0;}
				break;
		case 10: if(Day < 31){}
				else{Month=0;}
				break;
		case 11: if(Day < 30){}
				else{Month=0;}
				break;
		case 12: if(Day < 31){}
				else{Month=0;}
				break;
		default: Month=0;
				break;}
		
		if(Month==1 || Month==2){
			Month=Month+12;
			Year--; 			}
		
		Century = Year/100;
		Year = Year%100;
		
		if(Month != 0){
			Week = (Day + (26 * (Month + 1)) / 10 + Year + Year / 4 + Century / 4 + 5 * Century) % 7;
			
			switch (Week){
			case 0: System.out.println("Day of the week is Saturday");	
					break;
					
			case 1: System.out.println("Day of the week is Sunday");
					break;
					
			case 2: System.out.println("Day of the week is Monday");
					break;
					
			case 3: System.out.println("Day of the week is Tuesday");
					break;
					
			case 4: System.out.println("Day of the week is Wednesday");
					break;
					
			case 5: System.out.println("Day of the week is Thursday");
					break;
					
			case 6: System.out.println("Day of the week is Friday");
					break;
					
			default: System.out.println("No such a day exists");
					break;			}
		}
		else{
			System.out.println("Not a real date");
		

		}
	}

}
