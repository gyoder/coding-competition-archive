
/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob12 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String[] info = input.nextLine().split(" ");
				int doors = Integer.parseInt(info[0]);
				int rounds = Integer.parseInt(info[1]);
				int opened = Integer.parseInt(info[2]);
				
				double maxProbability = 100.0 / doors;
				int doorsLeft = doors - 1;
				
				for(int i = 0; i < rounds; i++) {
					doorsLeft -= opened;
					double probabilityRemoved = maxProbability * opened;
					double probabilityAdded = probabilityRemoved / doorsLeft;
					maxProbability += probabilityAdded;
					doorsLeft--;
				}
				
				maxProbability = Math.round(maxProbability * 100.0) / 100.0;
				
				System.out.println(String.format("%.2f%%", Double.valueOf(maxProbability)));
			}
		}
	}

}
