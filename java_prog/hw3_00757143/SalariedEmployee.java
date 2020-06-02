package ntou.cs.java2020.hw3;//00757143 楊明哲
public class SalariedEmployee extends Employee{
    SalariedEmployee(int salaryPaid,double amountWorked,Bonus bonusGet){
        super(salaryPaid,amountWorked,bonusGet);//呼叫上一層的建構元
    }
    @Override//轉字串
    public String toString() {
        return String.format("Salaried Employee => weekly salary: %,d, working weeks: %,d, calculated earnings: %,d, bonus: %,d",this.salaryPaid,(int)this.amountWorked,this.getEarnings(),this.bonusGet.getBonus(this.getEarnings()));
    }
}