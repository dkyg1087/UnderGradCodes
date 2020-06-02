package ntou.cs.java2020.hw2;//00757143 楊明哲

import java.util.Scanner;
public class CreateMatrix{
    private static void printMatrix(int matrixSize,int[][] ansMatrix){
        for(int i=0;i<matrixSize;i++){
            for(int j=0;j<matrixSize;j++){
                System.out.printf("%d\t",ansMatrix[i][j]);
            }
            System.out.printf("\n");
        }
    }//print the matrix out
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int spinDirection,fromWhere,sideLength=0;
        boolean flag=true;
        System.out.printf("請輸入順時鐘(1)或逆時鐘(2)?");
        spinDirection=input.nextInt();
        System.out.printf("請輸入內迴旋(1)或外迴旋(2)?");
        fromWhere=input.nextInt();
        while(flag){//if input even number then ask again.
            System.out.printf("請輸入邊長(<100)?");
            sideLength=input.nextInt();
            if(sideLength%2==1)flag=false;
            else System.out.printf("邊長應為奇數 ，請重新輸入!\n");
        }
        int[][] ansMatrix=new int[sideLength][sideLength];
        int[] steps=new int[(sideLength-1)*2+1];//steps count array
        int z,stepCount,iValue,jValue;//i,jval is the starting point
        if(fromWhere==1){
            z=-1;
            stepCount=sideLength;
            iValue=0;
            jValue=0;
        }
        else{
            z=1;
            stepCount=1;
            iValue=sideLength/2;
            jValue=sideLength/2;
        }
        boolean second=false;
        for(int i=0;i<(sideLength-1)*2+1;i++){
            steps[i]=stepCount;
            if(steps[i]==sideLength)steps[i]=sideLength-1;
            if(second==true || stepCount==sideLength){
                stepCount+=z;
                second=false;
            }
            else{
                second=true;
            }
        }//will create something like this: if side=5 -> 5,5,5,4,4,3,3,2,2,1,1
        int currentDirection=spinDirection==1?2:3;//1上 2右 3下 4左
        int counts=2;//start filling from 2
        ansMatrix[iValue][jValue]=1;//fill 1 first.
        for(int i=0;i<steps.length;i++){
            for(int j=0;j<steps[i];j++){
                switch(currentDirection){//move from current location to the next one depending on the currentDirection
                    case 1:
                        iValue--;
                        break;
                    case 2:
                        jValue++;
                        break;
                    case 3:
                        iValue++;
                        break;
                    case 4:
                        jValue--;
                        break;
                    default:
                        break;
                }
                ansMatrix[iValue][jValue]=counts;
                counts++;
            }
            currentDirection=spinDirection==1?currentDirection==1?2:currentDirection==2?3:currentDirection==3?4:1:currentDirection==1?4:currentDirection==2?1:currentDirection==3?2:3;
            //above basically means to switch from current to next direction depending on spinDirection and currentDirection.
        }
        printMatrix(sideLength, ansMatrix);//print out.
    }

}