import java.util.Scanner;

public class Prob18 {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int numLoops = sc.nextInt();
		sc.nextLine();
		for(int qq = 0; qq < numLoops; qq++) {
			String aa = sc.next();
			double a = Double.parseDouble(aa);
			String bb = sc.next();
			double b = Double.parseDouble(bb);
			double aPrev = a;
			double bPrev = b;
			int numIter = 1;
			while(Math.sqrt(Math.pow(aPrev, 2) + Math.pow(bPrev, 2)) < 100) {
				double aNext = Math.pow(aPrev, 2) - Math.pow(bPrev, 2) + a;
				double bNext = 2*aPrev*bPrev + b;
				numIter++;
				aPrev = aNext;
				bPrev = bNext;
				if(numIter > 51) {
					break;
				}
			}
			String color;
			if(numIter <= 10) {
				color = "RED";
			} else if(numIter <= 20) {
				color = "ORANGE";
			} else if(numIter <= 30) {
				color = "YELLOW";
			} else if(numIter <= 40) {
				color = "GREEN";
			} else if(numIter <= 50) {
				color = "BLUE";
			} else {
				color = "BLACK";
			}
			System.out.println((aa) + "+" + bb + "i" + " " + color);
		}
		sc.close();
	}

}
