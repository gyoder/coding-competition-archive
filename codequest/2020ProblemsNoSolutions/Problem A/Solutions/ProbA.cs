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
 * This class is used to run the HelloWorld test problem.
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
		
		// You'll want to do something for each test case
		// This for loop controls that behavior. This line
		// is the last one that will be common to all problems.
		for(int testCase = 0; testCase < numTestCases; testCase = testCase + 1){
			// Inside the for loop, you'll want to put the handling
			// for each test case. For Hello World, we're simply
			// echoing whatever input we receive.
			string text = Console.ReadLine();
			Console.WriteLine(text);
		}
	}
}