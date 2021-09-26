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

			int number1 = Integer.parseInt(split[0]);
			int number2 = Integer.parseInt(split[1]);

			if (number1 == number2) {
				System.out.println((number1 + number2) * 2);
			} else {
				System.out.println(number1 + number2);
			}
		}
	}

}