//Yixing Zheng
public class MathMethods implements MathOperations {

	@Override
	public double add(double dNum1, double dNum2) {
		return dNum1 + dNum2;
	}

	@Override
	public double absoluteValue(double dNum) {
		return Math.abs(dNum);
	}

	@Override
	public boolean isEven(int iNum) {
		if ( (iNum & 1) == 0 ) { 
			return true; }
		else { 
			return false; }
	}
}
