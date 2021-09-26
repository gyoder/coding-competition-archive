
/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.File;

public class Prob23 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob23.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String[] dims = input.readLine().split(" ");

				int width = Integer.parseInt(dims[0]);
				int height = Integer.parseInt(dims[1]);

				char[][] map = new char[height][];

				int startRow = -1;
				int startCol = -1;
				final List<Point> exits = new ArrayList<>();

				for (int rowNum = 0; rowNum < height; rowNum++) {
					map[rowNum] = new char[width];
					char[] rowData = input.readLine().toCharArray();
					int colNum = 0;

					for (; colNum < rowData.length; colNum++) {
						map[rowNum][colNum] = rowData[colNum];
						if (rowData[colNum] == 'o') {
							startRow = rowNum;
							startCol = colNum;
						} else if (rowData[colNum] == 'X') {
							exits.add(new Point(rowNum, colNum));
						}
					}
					for (; colNum < width; colNum++) {
						map[rowNum][colNum] = ' ';
					}
				}

				List<Path> paths = new ArrayList<>();

				paths.add(new Path(map, startRow, startCol, 0));

				List<Path> solutions = new ArrayList<>();

				while (solutions.isEmpty()) {
					List<Path> newPaths = new ArrayList<>();

					while (!paths.isEmpty()) {
						Path nextPath = paths.remove(0);

						Path up = nextPath.moveUp();
						Path down = nextPath.moveDown();
						Path left = nextPath.moveLeft();
						Path right = nextPath.moveRight();

						if (up != null && !up.isGoingInCircles()) {
							newPaths.add(up);
							if (up.isDone()) {
								solutions.add(up);
							}
						}
						if (down != null && !down.isGoingInCircles()) {
							newPaths.add(down);
							if (down.isDone()) {
								solutions.add(down);
							}
						}
						if (left != null && !left.isGoingInCircles()) {
							newPaths.add(left);
							if (left.isDone()) {
								solutions.add(left);
							}
						}
						if (right != null && !right.isGoingInCircles()) {
							newPaths.add(right);
							if (right.isDone()) {
								solutions.add(right);
							}
						}
					}
					
					paths.addAll(newPaths);
				}
				
				Path solution = null;
				
				if (solutions.size() == 1) {
					solution = solutions.get(0);
				} else if (!solutions.isEmpty()) {
					double minTiebreaker = Double.MAX_VALUE;

					for (Path possible : solutions) {
						Point location = possible.getPosition();
						double tiebreaker = getDistance(location, new Point(0, 0));
						if (minTiebreaker > tiebreaker) {
							minTiebreaker = tiebreaker;
							solution = possible;
						}
					}
				} 

				for (int row = 0; row < height; row++) {
					String output = new String(solution.getMap()[row]);
					while(output.endsWith(" ")) {
						output = output.substring(0, output.length() - 1);
					}
					System.out.println(output);
				}
			}
		}
	}

	protected static double getDistance(Point p1, Point p2) {
		int x = p2.row - p1.row;
		int y = p2.col - p1.col;
		return Math.sqrt((x * x) + (y * y));
	}

	private static final class Point {
		public final int row;
		public final int col;

		public Point(int row, int col) {
			this.row = row;
			this.col = col;
		}
	}

	private static final class Path {
		private final char[][] map;
		private final Point position;
		private final int distance;
		private final boolean done;

		public Path(char[][] map, int row, int col, int distance) {
			this.map = map;
			this.position = new Point(row, col);
			this.distance = distance;

			if (row > 0 && this.map[row - 1][col] == 'X') {
				this.done = true;
			} else if (row + 1 < this.map.length && this.map[row + 1][col] == 'X') {
				this.done = true;
			} else if (col > 0 && this.map[row][col - 1] == 'X') {
				this.done = true;
			} else if (col + 1 < this.map[row].length && this.map[row][col + 1] == 'X') {
				this.done = true;
			} else {
				this.done = false;
			}
		}

		public Path moveUp() {
			if (this.position.row > 0 && this.map[this.position.row - 1][this.position.col] == ' ') {
				char[][] newMap = copyMap();

				newMap[this.position.row - 1][this.position.col] = '.';

				return new Path(newMap, this.position.row - 1, this.position.col, this.distance + 1);
			}
			return null;
		}

		public Path moveDown() {
			if (this.position.row + 1 < this.map.length && this.map[this.position.row + 1][this.position.col] == ' ') {
				char[][] newMap = copyMap();

				newMap[this.position.row + 1][this.position.col] = '.';

				return new Path(newMap, this.position.row + 1, this.position.col, this.distance + 1);
			}
			return null;
		}

		public Path moveLeft() {
			if (this.position.col > 0 && this.map[this.position.row][this.position.col - 1] == ' ') {
				char[][] newMap = copyMap();

				newMap[this.position.row][this.position.col - 1] = '.';

				return new Path(newMap, this.position.row, this.position.col - 1, this.distance + 1);
			}
			return null;
		}

		public Path moveRight() {
			if (this.position.col + 1 < this.map[this.position.row].length
					&& this.map[this.position.row][this.position.col + 1] == ' ') {
				char[][] newMap = copyMap();

				newMap[this.position.row][this.position.col + 1] = '.';

				return new Path(newMap, this.position.row, this.position.col + 1, this.distance + 1);
			}
			return null;
		}
		
		public boolean isGoingInCircles() {
			int touchedCount = 0;
			
			if (this.position.row > 0 && this.map[this.position.row - 1][this.position.col] == '.') {
				touchedCount++;
			}
			if (this.position.row + 1 < this.map.length && this.map[this.position.row + 1][this.position.col] == '.') {
				touchedCount++;
			}
			if (this.position.col > 0 && this.map[this.position.row][this.position.col - 1] == '.') {
				touchedCount++;
			}
			if (this.position.col + 1 < this.map[this.position.row].length
					&& this.map[this.position.row][this.position.col + 1] == '.') {
				touchedCount++;
			}
			
			return touchedCount > 1;
		}

		public char[][] getMap() {
			return this.map;
		}

		public boolean isDone() {
			return this.done;
		}

		public Point getPosition() {
			return this.position;
		}

		// public int getDistance() {
		// return this.distance;
		// }

		private char[][] copyMap() {
			char[][] newMap = new char[this.map.length][];
			for (int i = 0; i < this.map.length; i++) {
				newMap[i] = new char[this.map[i].length];
				for (int j = 0; j < this.map[i].length; j++) {
					newMap[i][j] = this.map[i][j];
				}
			}
			return newMap;
		}
	}

}
