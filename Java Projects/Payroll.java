//Yixing Zheng
import java.util.*;
public class Payroll {

	public static void main(String[] args) {
		Scanner scanner;
		scanner = new Scanner (System.in);
		
		double Hours, PayRate, FederalTaxRate, StateTaxRate;
		
		System.out.println("Enter employee's name");
		String Name = scanner.nextLine();
		
		System.out.println("Enter number of hours worked in a week");
		Hours = scanner.nextDouble();
		
		System.out.println("Enter hourly pay rate");
		PayRate = scanner.nextDouble();
		
		System.out.println("Enter federal tax withholding rate");
		FederalTaxRate = scanner.nextDouble();
		
		System.out.println("Enter state tax withholding rate");
		StateTaxRate = scanner.nextDouble();
		
		double GrossPay= Hours * PayRate;
		double FederalWithholding = FederalTaxRate * GrossPay;
		double StateWithholding = StateTaxRate * GrossPay;
		double TotalDeduction = FederalWithholding + StateWithholding;
		double NetPay = ((Hours * PayRate) - ((Hours * PayRate)* 0.29));
		
		
		System.out.println("Employee Name: " + Name);
		System.out.printf("Pay Rate: $%5s", PayRate);
		
		
		System.out.printf("\nGross Pay: $%10s",GrossPay);
		System.out.println("\nDeductions:");
		
		System.out.println("   Federal Withholding:  " + "("+ (FederalTaxRate * 100) + "%)" + " $"+ FederalWithholding);
		System.out.println("   State Withholding: " +"(" + (StateTaxRate * 100)  + "%)" + " $"+ StateWithholding);
		System.out.printf("   Total Deduction: $%5s", TotalDeduction);
		System.out.printf("\nNet Pay : $%5s", NetPay);
		
	}

}
