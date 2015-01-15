import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;


public class Cell extends TestDrive {
	String cellValue;
	int position;
	
	public WebElement CreateCell(int index) {
		WebElement cell = driver.findElements(By.cssSelector(".grid-cell")).get(index);
		return cell;
	}
	
	private int getPosition() {
		return position;
	}

	private void setPosition(int position) {
		this.position = position;
	}

	private String getCellValue() {
		return cellValue;
	}

	private void setCellValue(int cellValue) {
		this.cellValue = driver.findElements(By.cssSelector(".tile-inner")).get(position).getText();
	}
}
