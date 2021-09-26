/*
 * GoofyGorillas.java
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

public class Prob03 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob03.in.txt"))))){
			int testCases = Integer.parseInt(input.readLine());
			
			for(int testcase = 0; testcase < testCases; testcase++) {
				String text = input.readLine();
				String[] parts = text.split(" ");
				
				if(Boolean.parseBoolean(parts[0]) == Boolean.parseBoolean(parts[1])) {
					System.out.println("true");
				}
				else {
					System.out.println("false");
				}
			}
		}
	}

}
