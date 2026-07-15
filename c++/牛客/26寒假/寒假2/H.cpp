#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n;
    cin>>n;
    ll ans = 0;
    map<ll,ll> pos;
    for(int i = 1;i<=n;i++){
        ll x;
        cin>>x;
        ans+=(i-pos[x]) * ((n-i+1) * (n-i+2)) / 2;
        pos[x] = i;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}