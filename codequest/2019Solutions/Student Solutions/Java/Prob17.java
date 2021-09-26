import java.util.Arrays;
import java.util.Scanner;

public class Prob17 {
	public static void main(String[] args) {
		try {
			Scanner kb = new Scanner(System.in);
			int n = Integer.parseInt(kb.nextLine());
			for(int Z = 0; Z < n; Z++) {
				int times = Integer.parseInt(kb.nextLine());
				char[][] ch = new char[10][10];
				
				for(int q = 0; q < ch.length; q++) {
					String str = kb.nextLine();
					for(int r = 0; r < ch[0].length; r++) {
						ch[q][r] = str.substring(r,r+1).toCharArray()[0];
					}
				}

				for(int k = 0; k<times; k++) {
					char[][] boy = new char[10][10];
					for(int i=0; i<ch.length;i++) {
						for(int j = 0; j<ch[0].length;j++) {
							boy[i][j] = ch[i][j];
						}
					}
				for(int q = 0; q < ch.length; q++) {
					for(int r = 0; r < ch[0].length; r++) {
						int temp = 0;
						
						
						try {
						if(boy[q-1][r-1]=='1') {
							temp++;
						}
						} catch (Exception e){}
						try {
							if(boy[q-1][r]=='1') {
								temp++;
							}
							} catch (Exception e){}
						try {
							if(boy[q-1][r+1]=='1') {
								temp++;
							}
							} catch (Exception e){}
						try {
							if(boy[q][r-1]=='1') {
								temp++;
							}
							} catch (Exception e){}
						try {
							if(boy[q+1][r-1]=='1') {
								temp++;
							}
							} catch (Exception e){}
						try {
							if(boy[q+1][r]=='1') {
								temp++;
							}
							} catch (Exception e){}
						try {
							if(boy[q+1][r+1]=='1') {
								temp++;
							}
							} catch (Exception e){}
						try {
							if(boy[q][r+1]=='1') {
								temp++;
							}
							} catch (Exception e){}
						if(ch[q][r]=='0') {
							if(temp==3) {
								ch[q][r]='1';
							}
						}else if(ch[q][r]=='1') {
							if(temp==1||temp==0) {
								ch[q][r]='0';
							}else if(temp>=4) {
								ch[q][r]='0';
							}
						}
					}
				}
				}
				for(int q = 0; q < ch.length; q++) {
					String s = "";
					for(int r = 0; r < ch[0].length; r++) {
						s += ch[q][r];
					}
					System.out.println(s);
				}
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void print(char[][] ch) {
		for(int q = 0; q < ch.length; q++) {
			String s = "";
			for(int r = 0; r < ch[0].length; r++) {
				s += ch[q][r];
			}
			System.out.println(s);
		}
		System.out.println();
	}
}
