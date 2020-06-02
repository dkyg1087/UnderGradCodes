package ntou.cs.java2020.hw3;//00757143 楊明哲
public abstract class Employee {
    public int salaryPaid;
    public double amountWorked;
    public Bonus bonusGet;
    Employee(int salaryPaid, double amountWorked, Bonus bonusGet){
        this.amountWorked=amountWorked;
        this.salaryPaid=salaryPaid;
        this.bonusGet=bonusGet;//Employee的建構元
    }
    int getEarnings(){//回傳實際賺多少
        return (int)(salaryPaid*amountWorked);
    }
}