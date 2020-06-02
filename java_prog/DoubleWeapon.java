package ntou.cs.java2020.hw3;//00757143 楊明哲
import java.util.Random;
public class DoubleWeapon extends Weapon{
    DoubleWeapon(double attack,double defense){
        super(attack,defense);
    }//呼叫上層的建構元
    @Override
    public double getOffense(){
        Random random = new Random();
        int rndNum=random.nextInt()%5;//隨機產生0-4
        if(rndNum==0){//如果是0的話就回傳2倍的攻擊力
            return super.getOffense()*2;
        }
        else return super.getOffense();
    }
}