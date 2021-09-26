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

public class Prob16 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob16.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int numKeys = Integer.parseInt(input.readLine());
				String cipherText = input.readLine();
				
				for(int i = 0; i < numKeys; i++) {
					String keyText = input.readLine();
					
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
