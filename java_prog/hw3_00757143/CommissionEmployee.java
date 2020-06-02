package ntou.cs.java2020.hw3;//00757143 楊明哲
public class CommissionEmployee extends Employee{
    CommissionEmployee(int salaryPaid,double amountWorked,Bonus bonusGet){
        super(salaryPaid,amountWorked,bonusGet);//呼叫上一層的建構元
    }
    @Override
    public String toString(){//將他轉成字串
        return String.format("Commission Employee => commission rate: %.2f, gross sales: %,d, calculated earnings: %,d, bonus: %,d",this.amountWorked,this.salaryPaid,this.getEarnings(),this.bonusGet.getBonus(this.getEarnings()));
    }
}