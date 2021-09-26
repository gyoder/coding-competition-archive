import java.util.ArrayList;
import java.util.Scanner;

public class Prob14 {
	public static void main(String[] args) {
		try {
			Scanner kb = new Scanner(System.in);
			int n = Integer.parseInt(kb.nextLine());
			for(int Z = 0; Z < n; Z++) {
				int r = Integer.parseInt(kb.nextLine());
				String[][] str = new String[2][r];
				ArrayList<String> s1 = new ArrayList<String>();
				ArrayList<String> s2 = new ArrayList<String>();
				for(int i = 0; i < r; i++) {
					String[] in = kb.nextLine().split(" ");
					s1.add(in[0]);
					s2.add(in[1]);
				}
				String current = "";
				String next = "";
				while(s1.size() > 0) {
					for(int i = 0; i < s1.size(); i++) {
						if(!s1.contains(s2.get(i))) {
							current = s2.get(i);
							next = s1.get(i);
							System.out.println(current);
							s1.remove(i);
							s2.remove(i);
						}
					}
				}
				System.out.println(next);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
