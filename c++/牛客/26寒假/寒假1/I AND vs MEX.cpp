#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll l,r;
    cin>>l>>r;

    ll k = 1LL << (63 - __builtin_clzll(r));
    if(l >= k){
        cout<<0<<endl;
    }else{
        ll r0 = r - k;
        if(r0>=l-1){
            cout<<r + 1<<endl;
        }else{
            cout<<r0+1<<endl;
        }
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