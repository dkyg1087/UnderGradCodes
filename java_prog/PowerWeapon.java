package ntou.cs.java2020.hw3;//00757143 楊明哲

public class PowerWeapon extends Weapon{
    PowerWeapon(double attack,double defense){
        super(attack,defense);//呼叫上一層的建構元
    }
    @Override
    public double getOffense(){//回傳1.2倍的攻擊力
        return super.getOffense()*1.2;
    }
}