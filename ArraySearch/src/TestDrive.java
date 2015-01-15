public class TestDrive {

	public static void main(String[] args) {

		double[] numbers = { -9, 6, 0, -59 , Double.NEGATIVE_INFINITY, Double.NaN};
		double min = numbers[0];
		for (int i = 0; i < numbers.length; i++) {
			if (min > numbers[i])
				min = numbers[i];
		}

		System.out.println(min);
	}
}