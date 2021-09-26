/* LMCoin.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class LMCoin {
	
	public static final String CHARS = " abcdefghijklmnopqrstuvwxyz";

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String line = input.nextLine();
				String[] values = line.split(" ");
				line = input.nextLine();
				String[] times = line.split(" ");
				
				double hash = 0;
				
				for(int i = 0; i < values.length; i++) {
					String value = values[i];
					int numericValue = 0;
					
					for(int j = 0; j < value.length(); j++) {
						numericValue += CHARS.indexOf(value.charAt(j));
					}
					
					long timestamp = Long.parseLong(times[i]);
					
					hash = ((i + 1 + numericValue + timestamp + hash) * 50.0) / 147.0;
				}
				
				System.out.println(manualRound(hash));
			}
		}
	}

	private static long manualRound(double number) {
		double remainder = number % 1.0;
		long integer = (long) Math.floor(number);
		if(remainder > 0.5) {
			integer += 1;
		}
		return integer;
	}
}
