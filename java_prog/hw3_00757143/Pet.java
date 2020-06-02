package ntou.cs.java2020.hw3;//00757143 楊明哲

import java.util.Random;

public class Pet implements ATK {
	private int maxAttack;
	public Pet(int maxAttack) {
		if (maxAttack > 0) {
			this.maxAttack = maxAttack;
		}
	}
	@Override
	public double attack() {
		Random rnd=new Random();//每次問攻擊力都給1到最大之間的攻擊力
		return rnd.nextInt(this.maxAttack-1)+1;
	}
	@Override
	public double defend() {
		return 0;//不知道要幹嘛
	}
}
