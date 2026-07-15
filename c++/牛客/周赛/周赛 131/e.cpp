#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];

    vector<ll> f(n+5,0);
    auto b = a;
    for(int i = 2;i<=n;i++){
        f[i] = f[i-1];
        ll cur = min(b[i],b[i-1]);
        b[i] -= cur;
        f[i] += cur;
    }

    b = a;
    vector<ll> g(n+5,0);
    for(int i = n-1;i>=1;i--){
        g[i] = g[i+1];
        ll cur = min(b[i],b[i+1]);
        b[i] -= cur;
        g[i] += cur;
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++) ans = max(ans,a[i]+f[i-1]+g[i+1]);

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