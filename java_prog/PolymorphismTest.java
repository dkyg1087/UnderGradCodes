package ntou.cs.java2020.ex3;
public class PolymorphismTest {

	public static void main(String args[]) {
		
		ThirdLayer objectE = new ThirdLayer("台灣");

		System.out.println();

		ThirdLayer objectA = new ThirdLayer();
		FirstLayer objectB = new FirstLayer('C');
		FirstLayer objectC = new FirstLayer('E');
		SecondLayer objectD = new SecondLayer('S');

		System.out.println();

		FirstLayer objectF = (FirstLayer) objectE;
		FirstLayer objectG = (FirstLayer) objectD;

		objectF.showDigits();
		objectF.showDigits();
		objectF.showDigits(0);
		objectB.showDigits();
		objectG.showDigits();
		objectF.showDigits(9);
	}
}

class FirstLayer {
	public FirstLayer() {
		System.out.print("S");
	}

	public FirstLayer(char c) {
		System.out.print(c);
	}

	public FirstLayer(String str) {
		System.out.print(str);
	}

	public void showDigits() {
		System.out.print("4");
	}

	public void showDigits(int d) {
		System.out.print(d);
	}
}

class SecondLayer extends FirstLayer {
	public SecondLayer() {
		System.out.print("U");
	}

	public SecondLayer(char c) {
		System.out.print(c);
	}

	public SecondLayer(String str) {
		super(str);
		System.out.print("海洋");
	}

	@Override
	public void showDigits() {
		System.out.print("2");
	}
}

class ThirdLayer extends SecondLayer {
	public ThirdLayer() {
		System.out.print("C");
	}

	public ThirdLayer(String str) {
		super(str);
		System.out.print("大學");
	}

	@Override
	public void showDigits() {
		super.showDigits();
		System.out.print("0");
	}
}