/* CaughtSpeeding.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob04 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String text = input.nextLine();
				String[] data = text.split(" ");
				
				int speed = Integer.parseInt(data[0]);
				boolean birthday = Boolean.parseBoolean(data[1]);
				
				if(speed <= 60 || (birthday && speed <= 65)) {
					System.out.println("no ticket");
				}
				else if(speed <= 80 || (birthday && speed <= 85)) {
					System.out.println("small ticket");
				}
				else {
					System.out.println("big ticket");
				}
			}
		}
	}

}
