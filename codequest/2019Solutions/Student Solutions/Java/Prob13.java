 import java.util.Scanner;

public class Prob13 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)){
			int testCases = Integer.parseInt(input.nextLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				String in = input.nextLine();
				String[] spl = in.split(" ");
				int r = Integer.parseInt(spl[0]);
				int c = Integer.parseInt(spl[1]);
				int b = Integer.parseInt(spl[2]);
				int[] bombs = new int[b * 2];
				for (int i = 0; i < b; i++) {
					String s = input.nextLine();
					bombs[2 * i] = Integer.parseInt(s.split(" ")[0]);
					bombs[2 * i + 1] = Integer.parseInt(s.split(" ")[1]);
				}
				run(r, c, b, bombs);
			}
		}
	}
	
	private static void run(int r, int c, int b, int[] bombs) {
		char[][] arr = new char[r][c];
		for (int i = 0; i < bombs.length; i+=2) {
			arr[bombs[i]][bombs[i+1]] = '*';
		}
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				if(arr[i][j] != '*') arr[i][j] = (bombsNear(bombs, i, j)+"").charAt(0);
			}
		}
		String ret = "";
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				ret += arr[i][j];
			}
			ret+= "\n";
		}
		ret = ret.substring(0, ret.length() -1);
		System.out.println(ret);
		
	}
	
	public static int bombsNear(int[] bombs, int i, int j) {
		int ret = 0;
		for (int k = 0; k < bombs.length; k += 2) {
			int xdist = bombs[k] - i;
			int ydist = bombs[k+1]  - j;
			if(xdist >= -1 && xdist <= 1 && ydist >= -1 && ydist <= 1) ret++;
		}
		return ret;
	}
	
	public static String round(double in, int places) {
		int factor = (int) Math.pow(10, places);
		int i = (int) Math.floor(in);
		int dec = (int) (Math.round(in * factor) - i * factor);
		String de = String.valueOf(dec);
		while(de.length() < places) {
			de = "0" + de;
		}
		return i + "." + de;
	}
}
