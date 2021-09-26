import java.util.Scanner;
import java.util.regex.Pattern;

public class Prob19 {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int numLoops = sc.nextInt();
		sc.nextLine();
		for(int qq = 0; qq < numLoops; qq++) {
			int numAddrs = sc.nextInt();
			String[][] addr = new String[numAddrs][4];
			sc.nextLine();
			for(int i = 0; i < numAddrs; i++) {
				String[] next = sc.nextLine().split(Pattern.quote("."));
				for(int x = 0; x < next.length; x++) {
					String binaryString = Integer.toBinaryString(Integer.valueOf(next[x]));
					while(binaryString.length() < 8) {
						binaryString = "0" + binaryString;
					}
					addr[i][x] = binaryString;
				}
			}
			boolean done = false;
			int len = 0;
			String[] match = new String[4];
			for(int x = 0; x < match.length; x++) {
				match[x] = "";
			}
			for(int i = 0; i < addr[0].length; i++) {
				for(int c = 0; c < addr[0][i].length(); c++) {
					char seek = addr[0][i].charAt(c);
					for(int j = 0; j < addr.length; j++) {
						if(addr[j][i].length() <= c || addr[j][i].charAt(c) != seek) {
							done = true;
							break;
						}
					}
					if(done) {
						break;
					} else {
						match[i] += seek;
						len++;
					}
				}
				if(done) {
					break;
				}
			}
			
			String result = "";
			for(int i = 0; i < match.length; i++) {
				while(match[i].length() < 8) {
					match[i] += "0";
				}
			}
			int resultTemp = 0;
			int res = 0;
			for(int outer = 0; outer < match.length; outer++) {
				res = 0;
				int mult = 128;
				for(int cAt = 0; cAt < match[outer].length(); cAt++) {
					if(match[outer].charAt(cAt) == '1') {
						res += mult;
					}
					mult /= 2;
				}
				result += res + ".";
			}
//			for(int outer = 0; outer < match.length; outer++) {
//				for(int cAt = 0; cAt < match[outer].length(); cAt++) {
//					int dig = match[outer].charAt(cAt) - '0';
//					resultTemp += dig * Math.pow(2, 8-match[outer].length());
//				}
//				result += resultTemp + ".";
//				resultTemp = 0;
//			}
			result = result.substring(0, result.length() - 1);
			System.out.println(result + "/" + len);
		}
		sc.close();
	}

}
