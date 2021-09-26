/* MandelbrotSet.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob18 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String line = input.nextLine();
				String[] data = line.split(" ");
				
				double a = Double.parseDouble(data[0]);
				double b = Double.parseDouble(data[1]);
				double originalA = a;
				double originalB = b;
				
				String originalC = data[0] + "+" + data[1] + "i ";
				
				double absZ = Math.sqrt((a * a) + (b * b));
				
				int n = 1;
				
				while(n <= 50 && absZ < 100) {
					double newA = (a * a) - (b * b) + originalA;
					double newB = (2 * a * b) + originalB;
					
					a = newA;
					b = newB;
					absZ = Math.sqrt((a * a) + (b * b));
					n++;
				}
				
				if(n <= 10) {
					System.out.println(originalC + "RED");
				}
				else if(n <= 20) {
					System.out.println(originalC + "ORANGE");
				}
				else if(n <= 30) {
					System.out.println(originalC + "YELLOW");
				}
				else if(n <= 40) {
					System.out.println(originalC + "GREEN");
				}
				else if(n <= 50) {
					System.out.println(originalC + "BLUE");
				}
				else {
					System.out.println(originalC + "BLACK");
				}
			}
		}
	}

}
