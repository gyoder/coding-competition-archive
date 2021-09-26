/* NoMoreShouting.java
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

public class Prob01 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob01.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				System.out.println(input.readLine().toLowerCase());
			}
		}
	}

}
