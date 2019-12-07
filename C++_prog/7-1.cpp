#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int value;
    while(cin>>value){
        vector<int> Vec;
        int a;
        char b;
        for(;;){
            cin>>a;
            Vec.push_back(a);
            b=getchar();
            if(b=='\n')break;
        }
        vector<int> New;
        int i;
        for(i=Vec.size()-1;i>=0;i--){
            New.push_back(Vec[i]);
        }
        int ans=0;
        for(i=0;i<New.size();i++){
            New[i]=New[i]*i;
            int z=i-1;
            if(z<0)z=0;
            ans=ans+(New[i]*pow(value,z));
        }
        cout<<ans<<endl;
    }
    return 0;
}