#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll INF = 1e18;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0);
    vector<ll> suf(n+2,INF);
    ll minn = INF;
    bool ok = true;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]-i<0) ok = false;
    }
    if(!ok){
        cout<<-1<<endl;
        return;
    }
    for(int i = n;i;i--){
        suf[i] = min(suf[i+1]-1,a[i]);
    }
    // for(int i = 1;i<=n;i++){
    //     cout<<suf[i]<<" ";
    // }
    // cout<<endl;
    ll ans = n;
    ll sum = 0;
    ll cur = 0;
    for(ll i = 1;i<=n;i++){
        cur = min(suf[i],i+sum);
        b[i] = cur;
        sum += a[i]-b[i];
    }
    // for(int i = 1;i<=n;i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    for(int i = 1;i<=n;i++){
        if(b[i]!=a[i]) ans+=a[i]-b[i];
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}