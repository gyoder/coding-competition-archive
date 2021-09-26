import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Prob23 {
	
	static class Point {
		int x, y;
		Point prev;
		int len;

		public Point(int x, int y, Point p, int len) {
			this.x = x;
			this.y = y;
			this.prev = p;
			this.len = len;
		}
		
		@Override
		public boolean equals(Object o) {
			Point b = (Point) o;
			if (this.x == b.x && this.y == b.y) {
				return true;
			}
			return false;
		}
		
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for (int i = 0; i < n; i++) {
			int width = scan.nextInt();
			int height = scan.nextInt();
			scan.nextLine();
			int[][] map = new int[height][width];
			ArrayDeque<Point> s = new ArrayDeque<>();
			for (int j = 0; j < height; j++) {
				String inStr = scan.nextLine();
				for (int k = 0; k < inStr.length(); k++) {
					if (inStr.charAt(k) == '#') {
						map[j][k] = 0;
					} else if (inStr.charAt(k) == 'X') {
						map[j][k] = 1;
					} else if (inStr.charAt(k) == 'o') {
						map[j][k] = 2;
						s.add(new Point(k, j, null, 0));
					} else {
						map[j][k] = 3;
					}
				}
				if (inStr.length() < map[0].length) {
					for (int l = inStr.length(); l < map[0].length; l++) {
						map[j][l] = 5;
					}
				}
			}
			ArrayList<Point> exits = new ArrayList<>();
			ArrayList<Point> visited = new ArrayList<>();
			while (!s.isEmpty()) {
				Point cur = s.poll();
				// System.out.println("Cur: " + cur.x + ", " + cur.y + ": " + cur.len);
				if (map[cur.y][cur.x] == 1) {
					// System.out.println("Found solution at " + cur.x + ", " + cur.y + ": " + cur.len);
					exits.add(cur);
				}
				if (isInBounds(cur.x-1, cur.y, map) && (map[cur.y][cur.x-1] == 3 || map[cur.y][cur.x-1] == 1) && !visited.contains(new Point(cur.x-1, cur.y, null, 0))) {
					s.add(new Point(cur.x-1, cur.y, cur, cur.len + 1));
					visited.add(s.peek());
				}
				if (isInBounds(cur.x, cur.y+1, map) && (map[cur.y+1][cur.x] == 3 || map[cur.y+1][cur.x] == 1) && !visited.contains(new Point(cur.x, cur.y+1, null, 0))) {
					s.add(new Point(cur.x, cur.y+1, cur, cur.len+1));
					visited.add(s.peek());
				}
				if (isInBounds(cur.x+1, cur.y, map) && (map[cur.y][cur.x+1] == 3 || map[cur.y][cur.x+1] == 1 ) && !visited.contains(new Point(cur.x+1, cur.y, null, 0))) {
					s.add(new Point(cur.x+1, cur.y, cur, cur.len+1));
					visited.add(s.peek());
				}
				if (isInBounds(cur.x, cur.y-1, map) && (map[cur.y-1][cur.x] == 3 || map[cur.y-1][cur.x] == 1 )&& !visited.contains(new Point(cur.x, cur.y-1, null, 0))) {
					s.add(new Point(cur.x, cur.y-1, cur, cur.len+1));
					visited.add(s.peek());
				}
				// printArray(map, visited);
			}

			Point curSol = exits.get(0);
			/*for (int k = 0; k < exits.size(); k++) {
				System.out.println("KN: " + exits.get(k).x + ", " + exits.get(k).y + ": " + exits.get(k).len);
			}*/
			for (int k = 0; k < exits.size(); k++) {
				if (exits.get(k).len > curSol.len) {
					exits.remove(k);
					k = 0;
				}
				if (exits.get(k).len < curSol.len) {
					exits.remove(curSol);
					curSol = exits.get(0);
				}
			}
			// System.out.println(exits);
			
			curSol = exits.get(0);
			for (Point e : exits) {
				if ( e.x * e.x + e.y * e.y < curSol.x * curSol.x + curSol.y * curSol.y) {
					// System.out.println("Changing sol");
					curSol = e;
				}
			}

			// System.out.println("Solution: " + curSol.x + ", " + curSol.y);
			// backtrack
			while (curSol.prev.prev != null) {
				map[curSol.prev.y][curSol.prev.x] = 4;
				curSol = curSol.prev;
			}
			printArray(map, new ArrayList<>());
			
		}
	}
	
	public static boolean isInBounds(int x, int y, int[][] map) {
		if (y < map.length && x < map[0].length && y >= 0 && x >= 0) {
			return true;
		}
		return false;
	}
	
	public static void printArray(int[][] arr, ArrayList<Point> visited) {
		for (int r = 0; r < arr.length; r++) {
			for (int c = 0; c < arr[0].length; c++) {
				if (visited.contains(new Point(c, r, null, 0))) {
					System.out.print('v');
				} else if (arr[r][c] == 0) {
					System.out.print('#');
				} else if (arr[r][c] == 1) {
					System.out.print('X');
				}  else if (arr[r][c] == 2) {
					System.out.print('o');
				}  else if (arr[r][c] == 3) {
					System.out.print(' ');
				} else if (arr[r][c] == 4) {
					System.out.print('.');
				}
			}
			System.out.println();
		}
	}

}
