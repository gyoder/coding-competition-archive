
/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Prob24 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			List<Integer> allOptions = new ArrayList<>();
			for (int i = 1; i <= 9; i++) {
				allOptions.add(Integer.valueOf(i));
			}

			for (int testcase = 0; testcase < testCases; testcase++) {
				int[][] grid = new int[9][];
				List<List<List<Integer>>> cellOptions = new ArrayList<>();

				for (int i = 0; i < 9; i++) {
					List<List<Integer>> cellOptionRow = new ArrayList<>();
					for (int j = 0; j < 9; j++) {
						cellOptionRow.add(new ArrayList<>(allOptions));
					}
					cellOptions.add(cellOptionRow);
				}

				int numbersComplete = 0;

				for (int i = 0; i < 9; i++) {
					char[] values = input.nextLine().toCharArray();
					grid[i] = new int[9];
					for (int j = 0; j < 9; j++) {
						if (values[j] == '_') {
							grid[i][j] = 0;
						} else {
							int value = values[j] - 48;
							numbersComplete++;
							grid[i][j] = value;
							scratchOffNumber(i, j, value, cellOptions);
						}
					}
				}

				solve(grid, numbersComplete, cellOptions);

				for (int row = 0; row < 9; row++) {
					for (int col = 0; col < 9; col++) {
						System.out.print(grid[row][col] + "");
					}
					System.out.println();
				}
			}
		}
	}

	private static void scratchOffNumber(int row, int col, int value, List<List<List<Integer>>> cellOptions) {
		Integer bigValue = Integer.valueOf(value);

		cellOptions.get(row).set(col, null);

		for (int k = 0; k < 9; k++) {
			if (cellOptions.get(row).get(k) != null) {
				cellOptions.get(row).get(k).remove(bigValue);
			}
			if (cellOptions.get(k).get(col) != null) {
				cellOptions.get(k).get(col).remove(bigValue);
			}
			int subgridRow = ((row / 3) * 3) + (k / 3);
			int subgridColumn = ((col / 3) * 3) + (k % 3);
			if (cellOptions.get(subgridRow).get(subgridColumn) != null) {
				cellOptions.get(subgridRow).get(subgridColumn).remove(bigValue);
			}
		}
	}

	private static boolean solve(int[][] grid, int numbersPrefilled, List<List<List<Integer>>> cellOptions) {
		int numbersComplete = numbersPrefilled;

		while (numbersComplete < 81) {
			boolean numberSet = false;
			int minSize = 9;
			int minSizeRow = 9;
			int minSizeCol = 9;

			// fill in obvious choices; if a cell can only be one number, fill it in
			for (int row = 0; row < 9; row++) {
				for (int col = 0; col < 9; col++) {
					List<Integer> options = cellOptions.get(row).get(col);
					if (options != null) {
						if (options.size() == 1) {
							int value = options.get(0).intValue();
							grid[row][col] = value;
							scratchOffNumber(row, col, value, cellOptions);
							numberSet = true;
							numbersComplete++;
							break;
						} else if (options.size() == 0) {
							// solution is invalid; no options remain for this cell
							return false;
						} else if (options.size() < minSize) {
							minSize = options.size();
							minSizeRow = row;
							minSizeCol = col;
						}
					}
				}
				if (numberSet) {
					break;
				}
			}

			if (numberSet) {
				continue;
			}

			// if we get here, there were no obvious choices and we have to guess
			// copy everything and recursively call
			List<Integer> options = cellOptions.get(minSizeRow).get(minSizeCol);
			for (int i = 0; i < minSize; i++) {
				int optionValue = options.get(i).intValue();
				int[][] gridCopy = new int[9][];
				List<List<List<Integer>>> cellOptionsCopy = new ArrayList<>();

				for (int row = 0; row < 9; row++) {
					gridCopy[row] = new int[9];
					List<List<Integer>> cellOptionsRow = new ArrayList<>();
					for (int col = 0; col < 9; col++) {
						gridCopy[row][col] = grid[row][col];
						if (cellOptions.get(row).get(col) != null) {
							cellOptionsRow.add(new ArrayList<>(cellOptions.get(row).get(col)));
						} else {
							cellOptionsRow.add(null);
						}
					}
					cellOptionsCopy.add(cellOptionsRow);
				}

				// fill in the current guess
				gridCopy[minSizeRow][minSizeCol] = optionValue;
				scratchOffNumber(minSizeRow, minSizeCol, optionValue, cellOptionsCopy);

				// if that guess solved it, we're done
				if (solve(gridCopy, numbersComplete + 1, cellOptionsCopy)) {
					for (int row = 0; row < 9; row++) {
						for (int col = 0; col < 9; col++) {
							grid[row][col] = gridCopy[row][col];
						}
					}
					return true;
				}
			}

			return false;
		}

		return true;
	}
}
