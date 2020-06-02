package ntou.cs.java2020.hw1;

public class CrapsTest{
    public static void main(String[] args){
        int[] Win_count;
        int[] Lose_count;
        Win_count = new int[22];//win count
        Lose_count= new int[22];//lost count
        for(int i=1;i<=21;i++)Win_count[i]=Lose_count[i]=0; //incase it didn't initialize with 0
        double expected=0.0;//expected value
        int num;
        for(int i=0;i<1000;i++){
           num=CrapsAnalysis.playGame();
           if(num>0){//if true then its a win
              expected+=num;//adds up the expected value
              Win_count[num>21?21:num]+=1;//if it's larger or equal than 21 it adds up in the same cell.Otherwise it's in its coresponding cell. 
           }
           else{// its a lost
               num*=-1;
               expected+=num;//adds up the expected value
               Lose_count[num>21?21:num]+=1;//if it's larger or equal than 21 it adds up in the same cell.Otherwise it's in its coresponding cell. 
           }
        }
        for(int i=1;i<21;i++)System.out.printf("%d games won and %d games lost on roll#%d\n",Win_count[i],Lose_count[i],i);
        System.out.printf("%d games won and %d games lost on rolls after the 20th roll\n",Win_count[21],Lose_count[21]);
        int total=0;
        for(int i=1;i<22;i++)total+=Win_count[i];//add up all the wins.
        System.out.printf("The chances of winning are %d / 1000 = %.2f %%\n",total,(double)(total*100)/1000);
        System.out.printf("The average game length is %.2f rolls\n",expected/1000);
     }
}