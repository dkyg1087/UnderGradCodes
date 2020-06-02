package ntou.cs.java2020.hw3;//00757143 楊明哲
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;
public class EmployeeTest {
    public static void main(String[] args){//Employee的主程式
        Scanner input=new Scanner(System.in);
        ArrayList<Employee>myEmployee=new ArrayList<>();
        int workerCmd;
        int salaryPaid;
        double amountWorked;
        int bonusCmd;
        Bonus myBonus;
        while(true){
            System.out.printf("---Earnings Calculation System:%n1. Salaried Employee%n2. Hourly Employee%n3. Commission Employee%n4. Piece Worker%nPlease input (1~4, -1 to end): ");
            workerCmd=input.nextInt();
            if(workerCmd==-1){//-1就停下來
                System.out.printf("Input finished!%n%n");
                break;
            }
            switch (workerCmd) {
                case 1://1就建構Salaried
                    System.out.printf("Please input weekly salary: ");
                    salaryPaid=input.nextInt();
                    System.out.printf("Please input working weeks: ");
                    amountWorked=input.nextDouble();
                    System.out.printf("Please input type of Bonus (1: static, 2: dynamic): ");
                    bonusCmd=input.nextInt();
                    if(bonusCmd==1)myBonus=(Bonus)new StaticBonus();
                    else myBonus=(Bonus)new DynamicBonus();
                    myEmployee.add((Employee)new SalariedEmployee(salaryPaid,amountWorked,myBonus)); 
                    break;
                case 2://2就建構Hour
                    System.out.printf("Please input wage: ");
                    salaryPaid=input.nextInt();
                    System.out.printf("Please input hours: ");
                    amountWorked=input.nextDouble();
                    System.out.printf("Please input type of Bonus (1: static, 2: dynamic): ");
                    bonusCmd=input.nextInt();
                    if(bonusCmd==1)myBonus=(Bonus)new StaticBonus();
                    else myBonus=(Bonus)new DynamicBonus();
                    myEmployee.add((Employee)new HourlyEmployee(salaryPaid,amountWorked,myBonus)); 
                    break;
                case 3://3就建構Commission
                    System.out.printf("Please input commission rate: ");
                    amountWorked=input.nextDouble();
                    System.out.printf("Please input gross sales: ");
                    salaryPaid=input.nextInt();
                    System.out.printf("Please input type of Bonus (1: static, 2: dynamic): ");
                    bonusCmd=input.nextInt();
                    if(bonusCmd==1)myBonus=(Bonus)new StaticBonus();
                    else myBonus=(Bonus)new DynamicBonus();
                    myEmployee.add((Employee)new CommissionEmployee(salaryPaid,amountWorked,myBonus)); 
                    break;
                case 4://4就建構PeiceWorker
                    System.out.printf("Please input wage: ");
                    salaryPaid=input.nextInt();
                    System.out.printf("Please input piece: ");
                    amountWorked=input.nextDouble();
                    System.out.printf("Please input type of Bonus (1: static, 2: dynamic): ");
                    bonusCmd=input.nextInt();
                    if(bonusCmd==1)myBonus=(Bonus)new StaticBonus();
                    else myBonus=(Bonus)new DynamicBonus();
                    myEmployee.add((Employee)new PieceWorker(salaryPaid,amountWorked,myBonus)); 
                    break;
                default:
                    break;
            }
            System.out.println();
        }
        int totalEarnings=0;
        int totalBonus=0;
        if(myEmployee.size()>0){//如果沒有直接輸入結束就輸出建置的結果
            System.out.printf("---Result:%n");
            for(int i=0;i<myEmployee.size();i++){
                System.out.printf("No. %d%n",i+1);
                System.out.println(myEmployee.get(i));
                totalEarnings+=myEmployee.get(i).getEarnings();
                totalBonus+=myEmployee.get(i).bonusGet.getBonus(myEmployee.get(i).getEarnings());
            }
            System.out.println();
            System.out.printf("Total earnings: %,d%n",totalEarnings);
            System.out.printf("Total bonus: %,d",totalBonus);
        }
    }
}