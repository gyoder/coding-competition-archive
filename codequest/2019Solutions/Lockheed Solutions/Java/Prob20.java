
/* Template.java
 *
 * Copyright (c) 2019 Lockheed Martin (LM) as an unpublished work. 
 * All Rights Reserved.
 *
 * This file does not contain any Lockheed Martin Proprietary Information.
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Prob20 {

	public static void main(String[] args) {
		try (Scanner input = new Scanner(System.in)) {
			int testCases = Integer.parseInt(input.nextLine());

			for (int testcase = 0; testcase < testCases; testcase++) {
				String[] counts = input.nextLine().split(" ");
				int known = Integer.parseInt(counts[0]);
				int unknown = Integer.parseInt(counts[1]);

				List<Bird> knownBirds = new ArrayList<>();

				for (int i = 0; i < known; i++) {
					String[] info = input.nextLine().split(" ");
					Bird bird = new Bird(info[0], Double.parseDouble(info[1]), Double.parseDouble(info[2]),
							Double.parseDouble(info[3]), Double.parseDouble(info[4]));
					knownBirds.add(bird);
				}

				for (int i = 0; i < unknown; i++) {
					List<Distance> distances = new ArrayList<>();
					String[] info = input.nextLine().split(" ");
					Bird bird = new Bird(null, Double.parseDouble(info[0]), Double.parseDouble(info[1]),
							Double.parseDouble(info[2]), Double.parseDouble(info[3]));

					for (int j = 0; j < known; j++) {
						Distance distance = knownBirds.get(j).getDistance(bird);
						distances.add(distance);
					}

					Collections.sort(distances);

					int aVotes = 0;
					int cVotes = 0;
					int pVotes = 0;
					int k = 5;
					String winner = null;
					int index = 0;

					for (; index < 5; index++) {
						Distance distance = distances.get(index);
						Bird knownBird = distance.bird;

						switch (knownBird.family) {
						case "Accipitridae":
							aVotes++;
							break;
						case "Cathartidae":
							cVotes++;
							break;
						case "Passeridae":
							pVotes++;
							break;
						}
					}

					if (aVotes >= (k / 2) + 1 && aVotes > cVotes && aVotes > pVotes) {
						winner = "Accipitridae";
					} else if (cVotes >= (k / 2) + 1 && cVotes > aVotes && cVotes > pVotes) {
						winner = "Cathartidae";
					} else if (pVotes >= (k / 2) + 1 && pVotes > cVotes && pVotes > aVotes) {
						winner = "Passeridae";
					}

					while (winner == null && index < known) {
						Distance distance = distances.get(index++);
						Bird knownBird = distance.bird;

						switch (knownBird.family) {
						case "Accipitridae":
							aVotes++;
							break;
						case "Cathartidae":
							cVotes++;
							break;
						case "Passeridae":
							pVotes++;
							break;
						}
						
						if (aVotes >= (k / 2) + 1 && aVotes > cVotes && aVotes > pVotes) {
							winner = "Accipitridae";
						} else if (cVotes >= (k / 2) + 1 && cVotes > aVotes && cVotes > pVotes) {
							winner = "Cathartidae";
						} else if (pVotes >= (k / 2) + 1 && pVotes > cVotes && pVotes > aVotes) {
							winner = "Passeridae";
						}
					}
					
					System.out.println(winner);
				}

			}
		}
	}

	private static final class Distance implements Comparable<Distance> {
		public final Bird bird;
		public final int distance;

		public Distance(Bird bird, int distance) {
			this.bird = bird;
			this.distance = distance;
		}

		@Override
		public int compareTo(Distance other) {
			if (this.distance > other.distance) {
				return 1;
			} else if (this.distance < other.distance) {
				return -1;
			}
			return 0;
		}
	}

	private static final class Bird {
		public final String family;
		public final double length;
		public final double width;
		public final double wingspan;
		public final double angle;

		public Bird(String family, double length, double width, double wingspan, double angle) {
			this.family = family;
			this.length = length;
			this.width = width;
			this.wingspan = wingspan;
			this.angle = angle;
		}

		public Distance getDistance(Bird unknown) {
			double a = this.length - unknown.length;
			double b = this.width - unknown.width;
			double c = this.wingspan - unknown.wingspan;
			double d = this.angle - unknown.angle;

			double square = (a * a) + (b * b) + (c * c) + (d * d);

			return new Distance(this, (int) (Math.sqrt(square) * 100000));
		}
	}
}
