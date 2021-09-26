import java.util.Scanner;

public class Pro10 {

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			int t = Integer.parseInt(sc.nextLine());
			for(int f = 0; f < t; f++){
				int shift = sc.nextInt();
				sc.nextLine();
				String str = sc.nextLine();
				String output = "";
				for(int i = 0; i < str.length(); i++) {
					char chara = str.charAt(i);
					if(chara == ' ') {
						output += (char)32;
					}
					else if ((chara - shift) < 97) {
						chara += 26;
						output += (char)(chara-shift);
					}
					else if ((chara - shift) > 122) {
						chara -= 26;
						output += (char)(chara-shift);
					}
					else output += (char)(chara-shift);
				}
				System.out.println(output);
			}
		}catch (Exception e){
			
		}

	}

}
