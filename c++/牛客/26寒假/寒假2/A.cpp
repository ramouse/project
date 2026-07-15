#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){   
    ll a,b,c;
    cin>>a>>b>>c;

    ll t = min({a,b,c});
    ll ma = max({a,b,c});
    if(ma - t <= 1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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