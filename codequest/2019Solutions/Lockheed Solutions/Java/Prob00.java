import java.util.Scanner;

/*
 * HelloWorld.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

/**
 * Hello World - Problem 0
 * 
 * This program can be used as a template for other CodeQuest problems.
 */
public class Prob00 {

	/**
	 * Every CodeQuest solution must include a main() method; how else 
	 * will we run your code? 
	 * 
	 * If you want to test your program before sending it in for judging,
	 * remember that all input this year comes from System.in. You can use
	 * these commands from your operating system's command line, replacing
	 * "Prob00" with the name of your source code file (assuming your 
	 * source code and input file are in the same location).
	 * 
	 * javac Prob00.java
	 * java Prob00 < Prob00.in.txt
	 * 
	 * If you're using an IDE like Eclipse or Netbeans, you can configure
	 * them to run your program as well.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		// First, connect to the standard input channel
		// This "try-with-resources" block will automatically close
		// the Scanner when we're done using it (even if your program
		// throws an Exception).
		try (Scanner input = new Scanner(System.in)){
			// Next, read the number of test cases
			int testCases = Integer.parseInt(input.nextLine());
			
			// Now perform each test case. This for loop is the last part
			// common to all problems; the contents of this for loop will
			// change depending on what problem you're solving.
			for(int testcase = 0; testcase < testCases; testcase++) {
				// For Problem 0, we're just reading in text and
				// passing it directly to the standard output
				System.out.println(input.nextLine());
			}
		}
	}

}
