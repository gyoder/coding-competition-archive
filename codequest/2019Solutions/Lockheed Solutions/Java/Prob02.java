/* SumItUp.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob02 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String text = input.nextLine();
				
				String[] data = text.split(" ");
				
				if(data[0].equals(data[1])) {
					System.out.println(Integer.parseInt(data[0]) * 4);
				}
				else {
					System.out.println(Integer.parseInt(data[0]) + Integer.parseInt(data[1]));
				}
			}
		}
	}

}
