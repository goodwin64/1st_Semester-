import org.openqa.selenium.By;

public class Grid extends TestDrive {
	Cell[] cellArray = new Cell[16];

	public void createArray() {
		for (int i = 0; i < 16; i++) {
			Cell cell = new Cell();
			cell.CreateCell(i);
			cell.position = i;
			cellArray[i] = cell;
		}
	}

	public void refreshArray() {
		for (int i = 0; i < 16; i++) {
			// driver.findElements(By.cssSelector(".grid-cell")).get(i).getLocation();
			System.out.println(driver
					.findElements(By.cssSelector(".grid-cell")).get(i)
					.getText());

		}
	}
	// public int summArray(Cell[] cell) {

	// }
}
