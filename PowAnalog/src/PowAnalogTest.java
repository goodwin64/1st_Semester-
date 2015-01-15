import java.util.Scanner;

public class PowAnalogTest {

	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter number");
		double numberToInvolve = scanner.nextDouble();
		System.out.println("Enter involution, involution must be int");
		int involution = scanner.nextInt();
		scanner.close();

		double involved = numberToInvolve;
	
		if (involution == 0) {
			involved = 1;
			System.out.println(involved);
		} else if (Math.abs(involution) == 1) {
			involved = numberToInvolve;
		} else {
			for (int i = 1; i < Math.abs(involution); i++) {
				involved = involved * numberToInvolve;
				System.out.println(involved);
				if (involved == Double.POSITIVE_INFINITY
						|| involved == Double.NEGATIVE_INFINITY) {
					System.out.println("out of data type");
					break;
				}
			}
		}
		if (involution < 0) {
			System.out.println("involution < 0 activate reverse involved");
		involved = (1.0 / involved);
		}
		System.out.println("Total:" + involved);
		/*
		 * if (involution > 0) { for (int i = 0; i <= involution; i++) { invif
		 * (involution == 0) { involved = 1; System.out.println(involved);
		 * }olved = involved * numberToInvolve; System.out.println(involved); if
		 * (involved == Double.POSITIVE_INFINITY || involved ==
		 * Double.NEGATIVE_INFINITY) { System.out.println("out of data type");
		 * break; } } } else if (involution < 0) { for (int i = 0; i <=
		 * -involution; i++) { involved = involved / numberToInvolve;
		 * System.out.println(involved); if (involved ==
		 * Double.POSITIVE_INFINITY || involved == Double.NEGATIVE_INFINITY) {
		 * System.out.println("out of data type"); break; } }
		 */
	}
}
