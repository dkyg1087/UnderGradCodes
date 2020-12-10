#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef unsigned long long ull;
int main() {
    int n,amount,primeNum;
    vector<int> primes;
    cin>>n>>amount;
    while(amount--){
        cin>>primeNum;
        primes.push_back(primeNum);
    }
    priority_queue<ull> q;
    vector<ull> res;
    q.push(-1);
    set<ull> s;
    while(res.size() <= n) {
        ull t = q.top(); q.pop();
        if(s.find(t) != s.end()) continue;
        res.push_back((-1)*t);
        for(int i:primes) {
            q.push(t*i);
        }
        s.insert(t);
    }
    cout<<res[n-1]<<endl;
}