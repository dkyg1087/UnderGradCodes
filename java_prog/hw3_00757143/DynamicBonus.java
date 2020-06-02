package ntou.cs.java2020.hw3;//00757143 楊明哲

public class DynamicBonus implements Bonus {

	@Override//回傳0.1的bonus
	public int getBonus(int salary) {
		return (int) (salary * 0.1);
	}

}
