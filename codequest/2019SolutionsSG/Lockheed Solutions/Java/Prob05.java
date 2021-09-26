/*
 * BrickHouse.java
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

public class Prob05 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob05.in.txt"))))){
			int testCases = Integer.parseInt(input.readLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				String text = input.readLine();
				
				String[] parts = text.split(" ");
				int small = Integer.parseInt(parts[0]);
				int large = Integer.parseInt(parts[1]);
				int goal = Integer.parseInt(parts[2]);
				
				while(goal >= 5 && large > 0) {
					goal -= 5;
					large--;
				}
				
				while(goal >= 1 && small > 0) {
					goal--;
					small--;
				}
				
				if(goal == 0) {
					System.out.println("true");
				}
				else {
					System.out.println("false");
				}
			}
		}
	}

}
