package ntou.cs.java2020.hw2;//00757143 楊明哲
import java.security.SecureRandom;
public class Player {

	public static final long MAX_HP = 10000000000L;
	public static final long MIN_HP = 9000000000L;
	private int weaponCount=0;//Saves the amount of weapon been equipped.
	private final String name;
	private long hp;
	private CloneableWeapon[] myWeapon = new CloneableWeapon[3];
	public Player(String name) {
		SecureRandom random = new SecureRandom();
		this.hp=(long)(Math.pow(10,9)*random.nextFloat())+9000000000L;//Generate random long HP.
		this.name=name;
	}

	public String getName() {
		return this.name;//return name
	}

	public long getHp() {
		return this.hp;//return hp
	}

	public void setHp(long newHp) {
		this.hp=newHp<0?0:newHp;//set hp,if newHP is negative, set to 0.
	}

	public void makeWeapon() {
		if(weaponCount==3){//already have 3,can't make new ones.
			System.out.printf("%s cannot make weapons now!%n",this.getName());
		}
		else{//make one weapon and add to weaponCount.
			this.myWeapon[this.weaponCount]=new CloneableWeapon();
			System.out.printf("%s makes a weapon with offense %,d%n",this.getName(),this.myWeapon[weaponCount].getOffense());
			this.weaponCount++;
		}
	}

	public void cloneWeapon() {
		if(this.weaponCount==0||this.weaponCount==3){//no space or no weapon can be cloned.
			System.out.printf("%s cannot clone weapons now!%n",this.getName());
			return;
		}
		else{//Clone the last weapon and add to the weaponCount.
			this.myWeapon[this.weaponCount]=new CloneableWeapon(this.myWeapon[this.weaponCount-1]);
			this.myWeapon[this.weaponCount].setOffense((int)Math.round(myWeapon[this.weaponCount].getOffense()*0.9));
			System.out.printf("%s clones a weapon with offense %,d%n",this.getName(),this.myWeapon[this.weaponCount].getOffense());
			this.weaponCount++;
		}
	}

	public int getAttack() {//adds up all the weapon offense and return. 
		int sumAttack=0;
		for(int i=0;i<weaponCount;i++)sumAttack+=myWeapon[i].getOffense();
		return sumAttack;
	}
}
