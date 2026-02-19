#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,q;
    cin>>n>>q;
    // ll h = 1;
    // int i = 0;
    // n--;

    while(q--){
        ll x;
        cin>>x;
        ll start = 1LL << __lg(x);
        ll total = min(2*start-1,n);
        cout<<total-start+1<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}