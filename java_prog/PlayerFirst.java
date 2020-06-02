package ntou.cs.java2020.ex2;
import java.util.Random;
public class PlayerFirst{
    private long hp;
    private int attackPoints;
    Random randomNum = new Random();
    public Player(){
        this.hp=(long)(Math.pow(10,9)*randomNum.nextFloat())+9000000000L;
        this.attackPoints=(int)(Math.pow(10,8)*randomNum.nextFloat())+100000000;
    }
    public long getHp(){
        return this.hp;
    }
    public int getAttackPoints(){
        return this.attackPoints;
    }
    public void setHp(long newHp){
        if(newHp<0)newHp=0;
        this.hp=newHp;
    }
    public void attack(Player enemy){
        enemy.setHp(enemy.getHp()-this.getAttackPoints());
    }
}