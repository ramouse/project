#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 676767677;

void solve(){
    ll x,y;
    cin>>x>>y;
    if(x/gcd(x,y) == 16 && y/gcd(x,y) == 9){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}