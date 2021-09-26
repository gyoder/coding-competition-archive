/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob06 {
	
	private static final double EARTH_RADIUS = (40075 / 2.0) / Math.PI;

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());
			
			for (int testcase = 0; testcase < testCases; testcase++) {
				int orbitHeight = Integer.parseInt(input.nextLine());
				
				double totalRadius = EARTH_RADIUS + orbitHeight;
				
				double distance = totalRadius * 2.0 * Math.PI;
				distance = Math.round(distance * 10.0) / 10.0;
				
				System.out.println(distance);
			}
		}
	}

}
