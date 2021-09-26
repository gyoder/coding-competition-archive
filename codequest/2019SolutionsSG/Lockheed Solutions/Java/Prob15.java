/* LMCoin.java
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

public class Prob15 {
	
	public static final String CHARS = " abcdefghijklmnopqrstuvwxyz";

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob15.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String line = input.readLine();
				String[] values = line.split(" ");
				line = input.readLine();
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
