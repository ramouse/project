#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int MOD = 998244353;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    ll mn = 1e9;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        if(b[i]<mn) mn=b[i];
    }

    ll ans = 1;
    ll x = 0,y = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] > mn) x++;
        else y++;
    }
    for(int i = 1;i<=x;i++){
        ans = (ans * i) % MOD;
    }
    for (int i = 1; i <= y; i++)
    {
        ans = (ans * i) % MOD;
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