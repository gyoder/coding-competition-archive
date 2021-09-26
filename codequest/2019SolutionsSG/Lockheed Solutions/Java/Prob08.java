/* FoveatedRendering.java
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

public class Prob08 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob08.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String text = input.readLine();
				String[] data = text.split(" ");
				
				int xTarget = Integer.parseInt(data[0]);
				int yTarget = Integer.parseInt(data[1]);
				
				for(int x = 0; x < 20; x++) {
					for(int y = 0; y < 20; y++) {
						if(y != 0) {
							System.out.print(" ");
						}
						
						if(xTarget == x && yTarget == y) {
							System.out.print("100");
						}
						else if(Math.abs(x - xTarget) <= 1 && Math.abs(y - yTarget) <= 1) {
							System.out.print("50");
						}
						else if(Math.abs(x - xTarget) <= 2 && Math.abs(y - yTarget) <= 2) {
							System.out.print("25");
						}
						else {
							System.out.print("10");
						}
					}
					
					System.out.println();
				}
			}
		}
	}

}
