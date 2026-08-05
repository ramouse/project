#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 1e9 + 7;

void solve(){
    ll n,q;
    cin>>n>>q;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ull B = rng()%MOD;
    vector<ll> a(n+1,0),s(n+1,0),p(200005,0),t(n+1,0);
    p[0] = 1;
    for(int i = 1;i<=200000;i++){
        p[i] = p[i-1] * B % MOD;
    }
    ll cur = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        s[i] = (s[i-1] + p[a[i]] + MOD) % MOD;
        cur = (cur + p[i]) % MOD;
        t[i] = 2 * cur % MOD;
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        ll len = r - l + 1;
        if(len&1){
            cout<<"No"<<endl;
            continue;
        }
        if((s[r] - s[l-1] + MOD) % MOD == t[len/2]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
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