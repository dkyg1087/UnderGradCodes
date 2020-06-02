package ntou.cs.java2020.hw3;//00757143 楊明哲

public class StaticBonus implements Bonus {

	@Override//固定紅利10000
	public int getBonus(int salary) {
		return 10000;
	}

}
