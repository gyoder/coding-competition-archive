package com.lmco.global.codequest.problems.solutions.twenty;

import java.util.Scanner;

public class ProbB {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());
			for (int testcase = 0; testcase < testCases; testcase++) {
				// read in the input string and break apart the numbers
				String dataString = input.nextLine();
				String[] data = dataString.split(":");
				
				// convert the data into decimal numbers
				double velocity = Double.parseDouble(data[0]);
				double distance = Double.parseDouble(data[1]);
				
				// seconds = meters / (meters/second)
				// seconds = meters * (second/meter)
				double timeToCrash = distance / velocity;
				
				// check outcome; 1 second or lest; swerve
				if(timeToCrash <= 1.0) {
					System.out.println("SWERVE");
				}
				// 5 seconds or less; brake
				else if(timeToCrash <= 5.0) {
					System.out.println("BRAKE");
				}
				// more than 5 seconds; safe
				else {
					System.out.println("SAFE");
				}
			}
		}
	}

}
