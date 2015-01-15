import static org.junit.Assert.fail;

import java.util.concurrent.TimeUnit;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.openqa.selenium.Alert;
import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.NoAlertPresentException;
import org.openqa.selenium.NoSuchElementException;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

public class TestDrive {
	public static WebDriver driver;
	private String baseUrl;
	private boolean acceptNextAlert = true;
	private StringBuffer verificationErrors = new StringBuffer();

	@Before
	public void setUp() throws Exception {
		System.setProperty("webdriver.chrome.driver",
				"/home/leonid/Public/chromedriver");
		driver = new ChromeDriver();
		baseUrl = "http://gabrielecirulli.github.io/2048";
		driver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
		driver.manage().deleteAllCookies();

	}

	@Test
	public void test5Register() throws Exception {
		driver.get(baseUrl + "/");
		Grid grid = new Grid();
		grid.createArray();
		grid.refreshArray();
		
		/*
		for (int i = 0; i < 16; i++) {
			String text = driver.findElements(By.cssSelector(".grid-cell")).get(i).getText();
			System.out.println(text);
		driver.findElements(By.className("tile-inner")).get(0).getText();
		}
		*/
		/*
		while (true) {
			WebElement element = driver.findElement(By.tagName("body"));
			
			for (int i = 0; i < 4; i++) {
				element.sendKeys(Keys.ARROW_DOWN);
			}
			for (int i = 0; i < 1; i++) {
				element.sendKeys(Keys.ARROW_LEFT);
			}
			for (int i = 0; i < 1; i++) {
				element.sendKeys(Keys.ARROW_RIGHT);
			}
		}
		*/
	}

	@After
	public void tearDown() throws Exception {
		driver.quit();
		String verificationErrorString = verificationErrors.toString();
		if (!"".equals(verificationErrorString)) {
			fail(verificationErrorString);
		}
	}

	private boolean isElementPresent(By by) {
		try {
			driver.findElement(by);
			return true;
		} catch (NoSuchElementException e) {
			return false;
		}
	}

	private boolean isAlertPresent() {
		try {
			driver.switchTo().alert();
			return true;
		} catch (NoAlertPresentException e) {
			return false;
		}
	}

	private String closeAlertAndGetItsText() {
		try {
			Alert alert = driver.switchTo().alert();
			String alertText = alert.getText();
			if (acceptNextAlert) {
				alert.accept();
			} else {
				alert.dismiss();
			}
			return alertText;
		} finally {
			acceptNextAlert = true;
		}
	}
}
