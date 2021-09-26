/*
 * ProbA.cs
 *
 * Copyright (c) 2020 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */
using System;

/**
 * Class CodeQuest
 * 
 * This class is used to run the Not So Self-Driving test problem.
 * You are strongly encouraged to use this as a template
 * for use in solving other problems.
 */
class CodeQuest {
	// This is the Main method, which is the entry 
	// point for your program. Without this, your
	// program can't be run.
	static void Main(string[] args) {
		// This line reads the first line of the input and
		// converts it to an integer. All inputs start with
		// the number of test cases, so this line should be
		// at the beginning of every solution you write.
		int numTestCases = Convert.ToInt32(Console.ReadLine());
		
		// You'll want to do something for each test case.
		// This for loop controls that behavior. This line
		// is the last one that will be common to all problems.
		for(int testCase = 0; testCase < numTestCases; testCase = testCase + 1){
			// Inside the for loop, we need to read the input line
			string text = Console.ReadLine();
			// then split out the separate numbers
			string[] data = text.Split(new Char[]{':'});
			
			// convert them to actual numbers
			double velocity = Convert.ToDouble(data[0]);
			double distance = Convert.ToDouble(data[1]);
			
			double time = distance / velocity;
			
			if(time <= 1.0){
				Console.WriteLine("SWERVE");
			}
			else if(time <= 5.0){
				Console.WriteLine("BRAKE");
			}
			else{
				Console.WriteLine("SAFE");
			}
		}
	}
}