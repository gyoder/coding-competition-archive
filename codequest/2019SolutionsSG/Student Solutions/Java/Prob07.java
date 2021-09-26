import java.util.Scanner;

public class Prob07 {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int num = Integer.parseInt(scan.nextLine());
		for(int i = 0;i<num;i++) {
			int num1 = scan.nextInt();
			double[] arr = new double[num1];
			for(int j=0;j<num1;j++) {
				arr[j] = scan.nextDouble();
			}
			double max = arr[0], min = arr[0];
			for(double temp : arr) {
				if(max < temp ) max = temp;
				if(min > temp) min = temp;
			}
			for(int j=0;j<num1;j++) {
				System.out.println(Math.round((arr[j]-min)/(max-min) * 255));
			}
			
			
		}
	}
}
