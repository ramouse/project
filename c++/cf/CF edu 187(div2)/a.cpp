#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    int k = d/m;
    if(k+1>=n){
        cout<<1<<endl;
        return;
    }
    int kk = n/(k+1);
    int kkk = n%(k+1);
    if(kkk>0){
        cout<<kk+1<<endl;
    }else{
        cout<<kk<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}