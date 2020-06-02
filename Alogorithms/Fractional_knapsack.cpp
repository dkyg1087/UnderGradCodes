#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
class Item{
    public:
        int amount;
        int value;
}item[40010];
bool cmp(Item a,Item b){
    return (double)a.value/a.amount>(double)b.value/b.amount;
}
int main(){
    int count=0;
    double max;
    cin>>max;
    while(cin>>item[count].value>>item[count].amount)count++;
    sort(item,item+count,cmp);
    double total=0.0;
    for(int i=0;i<count&&max>0;){
        if(max>=item[i].amount){
            total+=item[i].value;
            max-=item[i].amount;
            i++;
        }
        else{
            total+=((double)item[i].value/item[i].amount)*(double)max;
            break;
        }
    }
    printf("%.6lf\n",total);
}