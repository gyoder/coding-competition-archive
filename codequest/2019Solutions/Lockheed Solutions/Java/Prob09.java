
/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Prob09 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			Pattern secondRegex = Pattern.compile(".*?(\\d+)s.*");
			Pattern minuteRegex = Pattern.compile(".*?(\\d+)m.*");
			Pattern hourRegex = Pattern.compile(".*?(\\d+)h.*");

			for (int testcase = 0; testcase < testCases; testcase++) {
				String data = input.nextLine();

				int sec = 0;
				int min = 0;
				int hour = 0;

				Matcher matcher = secondRegex.matcher(data);
				if (matcher.matches()) {
					sec = Integer.parseInt(matcher.group(1));
				}
				matcher = minuteRegex.matcher(data);
				if (matcher.matches()) {
					min = Integer.parseInt(matcher.group(1));
				}
				matcher = hourRegex.matcher(data);
				if (matcher.matches()) {
					hour = Integer.parseInt(matcher.group(1));
				}

				String output = String.format("%02d:%02d:%02d", Integer.valueOf(hour), Integer.valueOf(min),
						Integer.valueOf(sec));
				
				System.out.println(output);
			}
		}
	}

}
