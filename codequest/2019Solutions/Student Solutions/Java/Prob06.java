 import java.util.Scanner;

public class Prob06 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)){
			int testCases = Integer.parseInt(input.nextLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				String in = input.nextLine();
				run(in);
			}
		}
	}
	
	public static void run(String in) {
		int a = Integer.parseInt(in);
		String res = round(40075 + 2 * Math.PI * a, 1);
		System.out.println(res);
	}
	
	public static String round(double in, int places) {
		int factor = (int) Math.pow(10, places);
		double big = Math.round(in * factor) / (double) factor;
		String ret = String.valueOf(big);
		return ret;
	}

}
