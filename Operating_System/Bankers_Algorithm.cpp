#include<iostream>
#include<fstream>
using namespace std;

bool arrayCompare(int i,int needed[][4],int resource[]){
    for(int j=0;j<4;j++){
        if(needed[i][j]>resource[j])return false;
    }
    return true;
}

int main(){
    ifstream allocationFile("Allocation_Avoidance.txt");
    ifstream maxFile("Max_Avoidance.txt");
    ifstream resourceFile("Resource_Avoidance.txt");
    if((allocationFile.is_open() && maxFile.is_open() && resourceFile.is_open())){
        /*--------read all files into variables--------*/
        int allocationMatrix[3][4],maxMatrix[3][4],resourceArray[4],neededMatrix[3][4]={};
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                allocationFile>>allocationMatrix[i][j];
                maxFile>>maxMatrix[i][j];
            }
        }
        for(int i=0;i<4;i++)resourceFile>>resourceArray[i];

        /*------create needed resources-------*/
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                neededMatrix[i][j]=maxMatrix[i][j]-allocationMatrix[i][j];
            }
        }
        
        /*------determine the resources left-------*/
        for(int j=0;j<4;j++){
            int total=0;
            for(int i=0;i<3;i++){
                total+=allocationMatrix[i][j];
            }
            resourceArray[j]-=total;
        }

        /*-------if satisfied grant resource and return allocated resources-------*/
        bool flag=false,processFinished[3]={false,false,false};
        int i=0,j=0;
        do{
            flag=false;
            if(!processFinished[i]&&arrayCompare(i,neededMatrix,resourceArray)){
               for(int j=0;j<4;j++){
                   resourceArray[j]+=allocationMatrix[i][j];
                   processFinished[i]=true;
               }
               cout<<"P"<<i<<" -> ";
               flag=true;
            }
            i++;
            i%=3;
        }while(flag);
        cout<<"end"<<endl;
        if(processFinished[0]&&processFinished[1]&&processFinished[2]){
            cout<<"Safe"<<endl;
        }
        else{
            cout<<"unSafe"<<endl;
        }
        
    }
    else{
        cout<<"File open failed."<<endl;
    }
}