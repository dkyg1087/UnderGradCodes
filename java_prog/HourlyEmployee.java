package ntou.cs.java2020.hw3;//00757143 楊明哲
public class HourlyEmployee extends Employee{
    HourlyEmployee(int salaryPaid,double amountWorked,Bonus bonusGet){
        super(salaryPaid,amountWorked,bonusGet);
    }
    @Override
    public int getEarnings(){
        if(this.amountWorked>=40){//如果>40就先算40的再算超過40的
            return 40*this.salaryPaid+(int)((amountWorked-40)*this.salaryPaid*1.5);
        }
        else return (int)this.amountWorked*this.salaryPaid;
    }
    @Override
    public String toString(){//轉成字串
        return String.format("Hourly Employee => hourly salary: %,d, hours: %,d, calculated earnings: %,d, bonus: %,d",this.salaryPaid,(int)this.amountWorked,this.getEarnings(),this.bonusGet.getBonus(this.getEarnings()));
    } 
}