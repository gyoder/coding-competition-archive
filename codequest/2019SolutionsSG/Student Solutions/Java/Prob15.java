import java.util.Scanner;

public class Prob15 {
	
	private static int[] dVal;
	private static long[] timeStamp;
	private static int[] valSums;
	
	public static void main(String[] args) {
		try(Scanner input = new Scanner(System.in)) {
			int T = Integer.parseInt(input.nextLine());
			
			while(T-- > 0) {
				String[] data = input.nextLine().split(" ");
				//dVal = new int[data.length];
				String[] str = input.nextLine().split(" ");
				
				timeStamp = new long[str.length];
				
				for(int i= 0; i < timeStamp.length; i++) {
					timeStamp[i] = Long.parseLong(str[i]);
				}
				char[] c;
				valSums = new int[data.length];
				for(int i = 0; i < data.length; i++) {
					c = data[i].toUpperCase().toCharArray();
					int sum = 0;
					
					for(char ch : c) {
						sum += (int) ch - 64;
					}
					
					valSums[i] = sum;
				}

				double d = findHash(10) + 0.5;

				System.out.println((long) d);
			}
		}
	}
	
	public static double findHash(int n) {
		if(n == 0) {
			return 0;
		} else {
			return ((double) (valSums[n - 1] + timeStamp[n - 1] + n + findHash(n - 1)) * 50 ) / 147.0;
		}
	}
}
