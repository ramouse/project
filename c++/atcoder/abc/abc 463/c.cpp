#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 676767677;

void solve(){
    ll n;
    cin>>n;
    vector<ll> h(n+1,0),l(n+1,0),suf(n+2,0);
    for(int i = 1;i<=n;i++){
        cin>>h[i]>>l[i];
    }
    for(int i = n;i;i--){
        suf[i] = max(suf[i+1],h[i]);
    }
    ll q;
    cin>>q;
    while(q--){
        ll t;
        cin>>t;
        ll idx = upper_bound(l.begin() + 1,l.end(),t) - l.begin();
        cout<<suf[idx]<<endl;
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