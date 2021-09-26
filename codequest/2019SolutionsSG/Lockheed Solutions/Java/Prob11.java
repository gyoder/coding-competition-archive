/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.File;

public class Prob11 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob11.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int bits = Integer.parseInt(input.readLine());
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
