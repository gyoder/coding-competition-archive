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

			String[] split = line.split(" ");

			if (split[0].equals(split[1])) {
				System.out.println("true");
			} else {
				System.out.println("false");
			}
		}
	}

}