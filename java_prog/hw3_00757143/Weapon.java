package ntou.cs.java2020.hw3;//00757143 楊明哲

public abstract class Weapon implements ATK {

	public static double MAX_VALUE = 255;
	private double offense;
	private double defense;

	public Weapon(double offense, double defense) {//建構元
		if ((0 < offense) && (offense < MAX_VALUE))
			this.offense = offense;
		else
			this.offense = 0;
		
		if ((0 < defense) && (defense < MAX_VALUE))
			this.defense = defense;
		else
			this.defense = 0;
	}

	public double getOffense() {//回傳offense
		return offense;
	}

	public void setOffense(double offense) {//設定offense
		if ((0 < offense) && (offense < MAX_VALUE))
			this.offense = offense;
		else
			this.offense = 0;
	}

	public double getDefense() {
		return defense;
	}

	public void setDefense(double defense) {
		if ((0 < defense) && (defense < MAX_VALUE))
			this.defense = defense;
		else
			this.defense = 0;
	}
	@Override
	public double attack() {//將ATK的攻擊變成getoffense
        return this.getOffense();
    }
	@Override
	public double defend() {
		return getDefense();
	}

	@Override
	public String toString() {
		return "Weapon [offense=" + offense + ", defense=" + defense + "]";
	}
}
