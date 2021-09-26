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

public class Prob06 {
	
	private static final double EARTH_RADIUS = (40075 / 2.0) / Math.PI;

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob06.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());
			
			for (int testcase = 0; testcase < testCases; testcase++) {
				int orbitHeight = Integer.parseInt(input.readLine());
				
				double totalRadius = EARTH_RADIUS + orbitHeight;
				
				double distance = totalRadius * 2.0 * Math.PI;
				distance = Math.round(distance * 10.0) / 10.0;
				
				System.out.println(distance);
			}
		}
	}

}
