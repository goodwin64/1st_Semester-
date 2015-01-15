import java.util.ArrayList;
import java.util.Scanner;

public class AnotherTestDrive {

	public static void main(String[] args) throws Exception {

		int[] numbers = new int[20];
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = (int) (Math.random() * 10);
			System.out.print(numbers[i] + "  ");
		}
		System.out.println();
		System.out.println("Введите int по которому искать...");
		Scanner scanner = new Scanner(System.in);
		int userNumber = scanner.nextInt();
		scanner.close();
		
		boolean flag = true;
		
		for (int i = 0; i < numbers.length; i++) {		
			if (userNumber == numbers[i]) {
				System.out.println("Сопадение " + userNumber + " на " + i + " позиции");
				flag = false;
			}
		}
		if (flag) {
			System.out.println("Совпадений нет");
		}
		System.out.println();
	}
}