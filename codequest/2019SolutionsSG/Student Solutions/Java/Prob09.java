import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int lines;

		try {
			lines = Integer.parseInt(scanner.nextLine());
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}

		for (int i = 0; i < lines; i++) {
			String line = scanner.nextLine();

			line = line.replace("and", " ");
			line = line.replace(",", " ");

			while (line.contains("  ")) line = line.replace("  ", " ");

			String[] split = line.split(" ");

			int seconds = 0;
			int minutes = 0;
			int hours = 0;

			for (String dan : split) {
				if (dan.contains("s")) {
					dan = dan.replace("s", "");
					seconds = Integer.parseInt(dan);
				} else if (dan.contains("m")) {
					dan = dan.replace("m", "");
					minutes = Integer.parseInt(dan);
				} else {
					dan = dan.replace("h", "");
					hours = Integer.parseInt(dan);
				}
			}

			System.out.println((hours < 10 ? "0" + hours : hours) + ":" + (minutes < 10 ? "0" + minutes : minutes) + ":" + (seconds < 10 ? "0" + seconds : seconds));
		}
	}

}