/* CaughtSpeeding.java
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

public class Prob04 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob04.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String text = input.readLine();
				String[] data = text.split(" ");
				
				int speed = Integer.parseInt(data[0]);
				boolean birthday = Boolean.parseBoolean(data[1]);
				
				if(speed <= 60 || (birthday && speed <= 65)) {
					System.out.println("no ticket");
				}
				else if(speed <= 80 || (birthday && speed <= 85)) {
					System.out.println("small ticket");
				}
				else {
					System.out.println("big ticket");
				}
			}
		}
	}

}
