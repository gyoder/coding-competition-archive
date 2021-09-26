/*
 * GoofyGorillas.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob03 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)){
			int testCases = Integer.parseInt(input.nextLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				String text = input.nextLine();
				String[] parts = text.split(" ");
				
				if(Boolean.parseBoolean(parts[0]) == Boolean.parseBoolean(parts[1])) {
					System.out.println("true");
				}
				else {
					System.out.println("false");
				}
			}
		}
	}

}
