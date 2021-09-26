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

public class Prob10 {

	private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";
	
	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob10.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int shift = Integer.parseInt(input.readLine());
				String ciphertext = input.readLine();
				String plaintext = "";
				
				for(int i = 0; i < ciphertext.length(); i++) {
					char cipherLetter = ciphertext.charAt(i);
					
					if(cipherLetter == ' ') {
						plaintext += " ";
						continue;
					}
					
					int value = ALPHABET.indexOf(cipherLetter);
					value -= shift;
					
					if(value < 0) {
						value += 26;
					}
					else if(value >= 26) {
						value -= 26;
					}
					
					plaintext += ALPHABET.charAt(value);
				}
				
				System.out.println(plaintext);
			}
		}
	}

}
