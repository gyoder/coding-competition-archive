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

			int[] binary = new int[Integer.parseInt(line)];

			while (true) {
				String out = "";

				for (int number : binary) out += number;

				System.out.println(out);

				if (!out.contains("0")) break;

				for (int j = binary.length - 1; j >= 0; j--) {
					if (binary[j] == 0) {
						binary[j] = 1;
						break;
					}

					binary[j] = 0;
				}
			}
		}
	}

}