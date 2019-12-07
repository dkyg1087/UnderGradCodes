#include<iostream>
using namespace std;
int main(){
	int N;
	while(cin>>N){
		int i,j,x=N/2+1,y=N/2+1,D,count=1,step=1,current_step=0,sum=0;
		cin>>D;
		/*動態記憶體配置*/
		int **array;
		array=new int*[N+2];
		for(i=0;i<N+2;i++)
			array[i]=new int[N+2];
		/*cin array*/
		for(i=1;i<N+1;i++)
			for(j=1;j<N+1;j++)
				cin>>array[i][j];
		/*開始走*/
		cout<<array[x][y];
		while(count<N*N){
			while(step!=current_step && count<N*N){
				current_step++;
				/*左*/
				if(D==0)
					cout<<array[x][--y];
				/*上*/
				else if(D==1)
					cout<<array[--x][y];
				/*右*/ 
				else if(D==2)
					cout<<array[x][++y];
				/*下*/
				else if(D==3)
					cout<<array[++x][y];
				count+=1;
			}
			sum+=1;//sum是紀錄step走幾次
			if(sum==2){
				sum=0;
				step+=1;
			}
			D=(D+1)%4;
			current_step=0;
		}
		cout<<endl;
		/*釋出記憶體空間*/
		for(i=0;i<N;i++)
			delete [] array[i];
		delete [] array;
	}
	return 0;
}