/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob16 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int numKeys = Integer.parseInt(input.nextLine());
				String cipherText = input.nextLine();
				
				for(int i = 0; i < numKeys; i++) {
					String keyText = input.nextLine();
					
					System.out.print("[");
					
					for(int j = 0; j < 64; j++) {
						String cipherHex = cipherText.substring(j * 2, (j + 1) * 2);
						String keyHex = keyText.substring(j * 2, (j + 1) * 2);
						
						int cipherValue = Integer.parseInt(cipherHex, 16);
						int keyValue = Integer.parseInt(keyHex, 16);
						char plaintext = (char) (cipherValue ^ keyValue);
						
						System.out.print(plaintext);
					}
					
					System.out.println("]");
				}
			}
		}
	}

}
