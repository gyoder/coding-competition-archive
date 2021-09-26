
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

public class Prob21 {

	public static void main(String[] args) throws Exception {
		try (BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream(new File("Prob21.in.txt"))))) {
			int testCases = Integer.parseInt(input.readLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String[] roomInfo = input.readLine().split(" ");

				Point spy = new Point(roomInfo[0], roomInfo[1]);
				Point camera = new Point(roomInfo[2], roomInfo[3]);
				int walls = Integer.parseInt(roomInfo[4]);

				Double a = null;
				Double c = null;
				if (spy.x != camera.x) {
					a = Double.valueOf((double) (spy.y - camera.y) / (double) (spy.x - camera.x));
					if (spy.y == camera.y) {
						c = Double.valueOf(spy.y);
					} else {
						c = Double.valueOf(spy.y - (a.doubleValue() * spy.x));
					}
				}

				boolean lineOfSightBlocked = false;

				for (int i = 0; i < walls; i++) {
					String[] wallInfo = input.readLine().split(" ");

					if (!lineOfSightBlocked) {
						Point wallStart = new Point(wallInfo[0], wallInfo[1]);
						Point wallEnd = new Point(wallInfo[2], wallInfo[3]);

						Double wallA = null;
						Double wallC = null;
						if (wallStart.x != wallEnd.x) {
							wallA = Double
									.valueOf((double) (wallStart.y - wallEnd.y) / (double) (wallStart.x - wallEnd.x));
							if (wallStart.y == wallEnd.y) {
								wallC = Double.valueOf(wallStart.y);
							} else {
								wallC = Double.valueOf(wallStart.y - (wallA.doubleValue() * wallStart.x));
							}
						}

						if (a == null && wallA == null) {
							continue;
							// both lines are vertical and thus parallel
						} else if (a == null) {
							// spy-camera line is vertical
							double yIntersect = wallA.doubleValue() * spy.x + wallC.doubleValue();
							if (yIntersect >= Math.min(spy.y, camera.y) && yIntersect <= Math.max(spy.y, camera.y)
									&& yIntersect >= Math.min(wallStart.y, wallEnd.y)
									&& yIntersect <= Math.max(wallStart.y, wallEnd.y)) {
								lineOfSightBlocked = true;
							}
						} else if (wallA == null) {
							// wall line is vertical
							double yIntersect = a.doubleValue() * wallStart.x + c.doubleValue();
							if (yIntersect >= Math.min(wallStart.y, wallEnd.y)
									&& yIntersect <= Math.max(wallStart.y, wallEnd.y)
									&& yIntersect >= Math.min(spy.y, camera.y)
									&& yIntersect <= Math.max(spy.y, camera.y)) {
								lineOfSightBlocked = true;
							}
						} else if (wallA.doubleValue() != a.doubleValue()) {
							// lines are not parallel and may intersect
							// ax + c = wallA*x + wallC
							// ax + c - wallC = wallA*x
							// (a - wallA)x + c - wallC = 0
							// (wallC - c) / (a - wallA) = x
							double xIntersect = (wallC.doubleValue() - c.doubleValue())
									/ (a.doubleValue() - wallA.doubleValue());
							if (xIntersect >= Math.min(spy.x, camera.x) && xIntersect <= Math.max(spy.x, camera.x)
									&& xIntersect >= Math.min(wallStart.x, wallEnd.x)
									&& xIntersect <= Math.max(wallStart.x, wallEnd.x)) {
								lineOfSightBlocked = true;
							}
						}
					}
				}

				System.out.println(lineOfSightBlocked ? "NO" : "YES");
			}
		}
	}

	private static final class Point {
		public final int x;
		public final int y;

		public Point(String x, String y) {
			this.x = Integer.parseInt(x);
			this.y = Integer.parseInt(y);
		}
	}

}
