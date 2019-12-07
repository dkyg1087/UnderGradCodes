#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
#define N 1100
typedef long long ll;
 
struct Ma
{
    int a,b;
}m[26];
stack<Ma>s;
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
 
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            int k=s[0]-'A';
            scanf("%d%d",&m[k].a,&m[k].b);
        }
        string s1;
        while(cin>>s1)
        {
 
            int flag=0;
            int len=s1.length();
            int ans=0;
            for(int i=0;i<len;i++)
            {
                
                if(isalpha(s1[i]))
                    s.push(m[s1[i]-'A']);
                else if(s1[i]==')')
                {
                    Ma m1=s.top();s.pop();
                    Ma m2=s.top();s.pop();
                    if(m2.b!=m1.a)
                    {
                        flag=1;
                        break;
                    }
                    ans+=m2.a*m2.b*m1.b;
                  
                    Ma m3;
                    m3.a=m2.a;
                    m3.b=m1.b;
                    s.push(m3);
                }
            }
             if(flag) printf("error\n");
             else printf("%d\n",ans);
        }
    }
    return 0;
}