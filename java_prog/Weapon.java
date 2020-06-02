package ntou.cs.java2020.hw2;//00757143 楊明哲

public class Weapon {
	
	public static int MAX_VALUE = 200000000;
	private int offense;

	public Weapon() {//if not specified then 0.
		this(0);
	}

	public Weapon(int offense) {//if negative then 0
		if ((0 < offense) && (offense <= MAX_VALUE)) {
			this.offense = offense;
		}
	}

	public int getOffense() {
		return offense;//return offense.
	}

	public void setOffense(int offense) {
		if ((0 < offense) && (offense <= MAX_VALUE)) {
			this.offense = offense;
		}//if negative then 0.
	}

	@Override
	public String toString() {
		return String.format("a weapon with offense %,d", offense);
	}
}
