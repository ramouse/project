#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll m,n,z;
    cin>>m>>n>>z;
    if(z%(m+n) == 0){
        cout<<1;
        return;
    }
    if( z%(m+n) - m <= 0 && z%(m+n) != 0){
        cout<<0;
        return;
    }else{
        cout<<1;
        return;
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