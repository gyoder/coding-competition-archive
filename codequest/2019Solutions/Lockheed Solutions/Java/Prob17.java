/* GameOfLife.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.Scanner;

public class Prob17 {
	
	public static final int WORLD_SIZE = 10;

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				int generations = input.nextInt();
				input.nextLine(); // purge newline
				
				int[][] world = new int[WORLD_SIZE][];
				
				for(int x = 0; x < WORLD_SIZE; x++) {
					world[x] = new int[WORLD_SIZE];
					String text = input.nextLine();
					String[] cells = text.split("");
					
					for(int y = 0; y < WORLD_SIZE; y++) {
						world[x][y] = Integer.parseInt(cells[y]);
					}
				}
				
				for(int g = 0; g < generations; g++) {
					world = processGeneration(world);
				}
				
				for(int x = 0; x < WORLD_SIZE; x++) {
					for(int y = 0; y < WORLD_SIZE; y++) {
						System.out.print(world[x][y]);
					}
					System.out.println();
				}
			}
		}
	}

	private static int[][] processGeneration(int[][] input){
		int[][] output = new int[WORLD_SIZE][];
		
		for(int x = 0; x < WORLD_SIZE; x++) {
			output[x] = new int[WORLD_SIZE];
			
			for(int y = 0; y < WORLD_SIZE; y++) {
				int neighborCount = 0;
				
				if(x != 0) {
					if(y != 0 && input[x - 1][y - 1] == 1) {
						neighborCount++;
					}
					if(input[x - 1][y] == 1) {
						neighborCount++;
					}
					if(y != (WORLD_SIZE - 1) && input[x - 1][y + 1] == 1) {
						neighborCount++;
					}
				}
				if(y != 0 && input[x][y - 1] == 1) {
					neighborCount++;
				}
				if(y != (WORLD_SIZE - 1) && input[x][y + 1] == 1) {
					neighborCount++;
				}
				if(x != (WORLD_SIZE - 1)) {
					if(y != 0 && input[x + 1][y - 1] == 1) {
						neighborCount++;
					}
					if(input[x + 1][y] == 1) {
						neighborCount++;
					}
					if(y != (WORLD_SIZE - 1) && input[x + 1][y + 1] == 1) {
						neighborCount++;
					}
				}
				
				if(input[x][y] == 1 && (neighborCount == 2 || neighborCount == 3)) {
					output[x][y] = 1;
				}
				else if(input[x][y] == 0 && neighborCount == 3) {
					output[x][y] = 1;
				}
				else {
					output[x][y] = 0;
				}
			}
		}
		
		return output;
	}
}
