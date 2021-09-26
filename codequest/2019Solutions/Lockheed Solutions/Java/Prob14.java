/* HomewardBound.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.ArrayList;
import java.util.Scanner;

public class Prob14 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int pairs = Integer.parseInt(input.nextLine());
				
				ArrayList<ArrayList<String>> lists = new ArrayList<>();
				
				for(int i = 0; i < pairs; i++) {
					String pair = input.nextLine();
					String[] data = pair.split(" ");
					String origin = data[0];
					String destination = data[1];
					
					// see if this pair attaches to anything
					ArrayList<String> preceding = null;
					ArrayList<String> anteceding = null;
					for(ArrayList<String> list : lists) {
						if(list.get(list.size() - 1).equals(origin)) {
							preceding = list;
						}
						else if(list.get(0).equals(destination)) {
							anteceding = list;
						}
					}
					
					if(preceding != null && anteceding != null) {
						// we've found the link between two existing lists
						preceding.addAll(anteceding);
						lists.remove(anteceding);
					}
					else if(preceding == null && anteceding == null) {
						ArrayList<String> newList = new ArrayList<>();
						newList.add(origin);
						newList.add(destination);
						lists.add(newList);
					}
					else {
						if (preceding != null) {
							// add destination to the end of the existing list
							preceding.add(destination);
						}
						if(anteceding != null) {
							// add origin to beginning of the existing list
							anteceding.add(0, origin);
						}
					}
				}
				
				// by this point we should have a single list
				ArrayList<String> route = lists.get(0);
				for(int i = route.size() - 1; i >= 0; i--) {
					System.out.println(route.get(i));
				}
			}
		}
	}

}
