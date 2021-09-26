/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob11 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int bits = Integer.parseInt(input.nextLine());
				int maximum = 1;
				
				for(int i = 0; i < bits; i++) {
					maximum *= 2;
				}
				
				for(int i = 0; i < maximum; i++) {
					String str = "";
					int remaining = i;
					for(int powerOfTwo = maximum / 2; powerOfTwo > 0; powerOfTwo /= 2) {
						if(remaining >= powerOfTwo) {
							str += "1";
							remaining -= powerOfTwo;
						}
						else {
							str += "0";
						}
					}
					System.out.println(str);
				}
			}
		}
	}

}
