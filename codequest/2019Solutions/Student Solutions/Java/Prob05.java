
import java.util.Scanner;

abstract class BasePlate02 {

	
	/**
	 * Get's all input from the System.in
	 * 
	 * @return 
	 */
	public void inputRead(){
		
		try (Scanner input = new Scanner(System.in)){
			
			int testCases = Integer.parseInt(input.nextLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				
				this.processLine(input.nextLine());
				
			}
			
		}
	
	}
	
	
	public abstract void processLine(String line);
	
	public boolean parseBool(String input){
	
		if(input.equals("true")){
			return true;
		}
		if(input.equals("false")){
			return false;
		}
		return false;
		
	}
	
	
}

public class Prob05 extends BasePlate02{

	private static BasePlate02 _instance = new Prob05();
	
	public static void main(String[] args){
		_instance.inputRead();	
	}
	
	
	/**
	 * Called every time a new input is read from.
	 * 
	 * Returns nothing.
	 */
	@Override
	public void processLine(String line) {
		
		String[] lineArr = line.split(" ");
		
		int inch1 = Integer.parseInt(lineArr[0]);
		int inch5 = Integer.parseInt(lineArr[1]);
		int length = Integer.parseInt(lineArr[2]);
		
		int totalInch1 = inch1;
		int totalInch5 = inch5 * 5;
		
		
		if((totalInch1 + totalInch5) == length){
			System.out.println("true");
			
		}else if((totalInch1 + totalInch5) >= length){
			boolean complete = false;
			
			while(!complete){
				
				if((totalInch1 + totalInch5 ) - length >= 5 && (totalInch5 >= 5)){
					totalInch5 = totalInch5 - 5;
					//System.out.println("INCH 5: " + String.valueOf(totalInch5));
					continue;
					
				} else if((totalInch1 + totalInch5) - length >= 1 && (totalInch1 >= 1)){
					totalInch1 = totalInch1 - 1;
					//System.out.println("INCH 1: " + String.valueOf(totalInch1));
					continue;
					
				} else if((totalInch1 + totalInch5) < 0){
					System.out.println("false");
					complete = true;
					break;
					
				}else if ((totalInch1 + totalInch5) == length){
					System.out.println("true");
					complete = false;
					break;
					
				} else {
					//System.out.println("Got here2." + String.valueOf(totalInch1 + totalInch5));
					System.out.println("false");
					complete = true;
					break;
				}
				
			}
			
		}else{
			
			System.out.println("false");
			
		}

		
	}
}
