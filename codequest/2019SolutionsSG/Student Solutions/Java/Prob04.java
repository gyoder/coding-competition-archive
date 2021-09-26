
import java.util.Scanner;

abstract class BasePlate01 {

	
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

public class Prob04 extends BasePlate01{

	private static BasePlate01 _instance = new Prob04();
	
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
		int mph = Integer.parseInt(lineArr[0]);
		boolean bool2 = parseBool(lineArr[1]);
		
		int limitMph = (bool2) ? 60 + 5 : 60;
		int bigLimitMph = (bool2) ? 80 + 5 : 80;
		
		if(mph > limitMph){
			if(mph > bigLimitMph){
				System.out.println("big ticket");
			}else{
				System.out.println("small ticket");
			}
			
		}else{
			System.out.println("no ticket");
		}
		
	}
}
