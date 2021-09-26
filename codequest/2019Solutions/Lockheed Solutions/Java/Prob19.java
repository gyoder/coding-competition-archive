/* NetworkRanger.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob19 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int numAddresses = Integer.parseInt(input.nextLine());
				
				byte[][] binaries = new byte[numAddresses][];
				
				for(int i = 0; i < numAddresses; i++) {
					binaries[i] = convertToBinary(input.nextLine());
				}
				
				int bit = 0;
				for(bit = 0; bit < 32; bit++) {
					boolean allMatch = true;
					byte bitToMatch = binaries[0][bit];
					
					for(int i = 1; i < numAddresses; i++) {
						if(binaries[i][bit] != bitToMatch) {
							allMatch = false;
							break;
						}
					}
					
					if(!allMatch) {
						break;
					}
				}
				
				byte[] rootAddress = new byte[32];
				for(int i = 0; i < bit; i++) {
					rootAddress[i] = binaries[0][i];
				}
				for(int i = bit; i < 32; i++) {
					rootAddress[i] = 0;
				}
				
				System.out.println(convertToAddress(rootAddress) + "/" + bit);
			}
		}
	}

	private static final byte[] convertToBinary(String address) {
		byte[] bits = new byte[32];
		String[] numbers = address.split("[.]");
		
		for(int numIdx = 0; numIdx < 4; numIdx++) {
			int bitOffset = numIdx * 8;
			int number = Integer.parseInt(numbers[numIdx]);
			int power = 128;
			for(int i = 0; i < 8; i++) {
				if(number >= power) {
					number -= power;
					bits[bitOffset + i] = 1;
				}
				
				power /= 2;
			}
		}
		
		return bits;
	}
	
	private static final String convertToAddress(byte[] binary) {
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		int num4 = 0;
		
		int power = 128;
		
		for(int i = 0; i < 8; i++) {
			num1 += (binary[i] * power);
			num2 += (binary[i + 8] * power);
			num3 += (binary[i + 16] * power);
			num4 += (binary[i + 24] * power);
			power /= 2;
		}
		
		return num1 + "." + num2 + "." + num3 + "." + num4;
	}
}
