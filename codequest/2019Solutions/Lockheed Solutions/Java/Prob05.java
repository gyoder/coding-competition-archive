/*
 * BrickHouse.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob05 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)){
			int testCases = Integer.parseInt(input.nextLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				String text = input.nextLine();
				
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
