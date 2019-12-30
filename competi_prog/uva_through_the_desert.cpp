#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    float zero1,zero2;
    string junk1,junk2;
    while(cin>>zero1>>junk1>>junk2>>zero2,zero2!=0){
        int start=zero1,end=0,leak=0,flag=0;
        float speed=(zero2/100.0),max_dis=0.0,temp_dis=0.0,ans;
        string cmd;
        while(cin>>end>>cmd){
            switch(cmd[0]){
                case 'G':
                    if(cmd[1]=='o'){
                        temp_dis+=(end-start)*(speed+leak);
                        ans=max(temp_dis,max_dis);
                        printf("%.3f\n",ans);
                        flag=1;
                        break;
                    }
                    else{
                        string junk;
                        cin>>junk;
                        temp_dis+=(end-start)*(speed+leak);
                        max_dis=max(temp_dis,max_dis);
                        temp_dis=0.0;
                        start=end;
                        break;
                    }
                case 'L':
                    temp_dis+=(end-start)*(speed+leak);   
                    leak+=1;
                    start=end;
                    break;
                case 'M':
                    temp_dis+=(end-start)*(speed+leak);
                    leak=0;
                    start=end;
                    break;
                case 'F':
                    {
                        float num;
                        string junk;
                        cin>>junk>>num;
                        temp_dis+=(end-start)*(speed+leak);
                        speed=num/100.0;
                        start=end;
                    }
            }
            if(flag==1)break;
        }
    }
}