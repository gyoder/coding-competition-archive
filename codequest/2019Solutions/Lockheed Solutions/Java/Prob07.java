/* ImageCompression.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob07 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int numbers = Integer.parseInt(input.nextLine());
				
				double[] values = new double[numbers];
				double min = Double.MAX_VALUE;
				double max = Double.MIN_VALUE;
				
				for(int i = 0; i < numbers; i++) {
					double value = Double.parseDouble(input.nextLine());
					values[i] = value;
					
					if(value < min) {
						min = value;
					}
					if(value > max) {
						max = value;
					}
				}
				
				for(int i = 0; i < numbers; i++) {
					int conversion = (int) Math.round(((values[i] - min) / (max - min)) * 255);
					System.out.println(conversion);
				}
				
			}
		}
	}

}
