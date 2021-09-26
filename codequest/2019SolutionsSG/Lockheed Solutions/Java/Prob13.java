
/* Template.java
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

public class Prob13 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob13.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String[] info = input.readLine().split(" ");

				int rows = Integer.parseInt(info[0]);
				int cols = Integer.parseInt(info[1]);
				int bombs = Integer.parseInt(info[2]);

				int[][] map = new int[rows][];
				for (int i = 0; i < rows; i++) {
					map[i] = new int[cols];
				}

				for (int i = 0; i < bombs; i++) {
					String[] location = input.readLine().split(" ");

					int row = Integer.parseInt(location[0]);
					int col = Integer.parseInt(location[1]);

					map[row][col] = Integer.MIN_VALUE;

					if (row != 0) {
						if (col != 0) {
							map[row - 1][col - 1]++;
						}
						map[row - 1][col]++;
						if (col != cols - 1) {
							map[row - 1][col + 1]++;
						}
					}
					if (col != 0) {
						map[row][col - 1]++;
					}
					if (col != cols - 1) {
						map[row][col + 1]++;
					}
					if (row != rows - 1) {
						if (col != 0) {
							map[row + 1][col - 1]++;
						}
						map[row + 1][col]++;
						if (col != cols - 1) {
							map[row + 1][col + 1]++;
						}
					}
				}

				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						if (map[i][j] >= 0) {

							System.out.print(map[i][j]);
						} else {
							System.out.print("*");
						}
					}
					System.out.println();
				}
			}
		}
	}

}
