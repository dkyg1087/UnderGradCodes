package ntou.cs.java2020.hw3;//00757143 楊明哲
public class PieceWorker extends Employee{
    PieceWorker(int salaryPaid,double amountWorked,Bonus bonusGet){
        super(salaryPaid,amountWorked,bonusGet);//呼叫上一層建構元
    }
    @Override
    public String toString(){//轉成字串
        return String.format("Piece Worker => wage: %,d, piece: %,d, calculated earnings: %,d, bonus: %,d",this.salaryPaid,(int)this.amountWorked,this.getEarnings(),this.bonusGet.getBonus(this.getEarnings()));
    }
}