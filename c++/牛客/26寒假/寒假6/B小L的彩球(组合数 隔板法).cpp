#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 998244353;
const int N = 1e6+2;
vector<ll> fact(N+3);
vector<ll> inv(N+3);

ll qpow(ll a,ll b){
    ll res  = 1;
    while(b != 0){
        if(b%2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b/=2;
    }
    return res;
}

void init(){
    fact[0] = 1;
    for(int i = 1;i<=N;i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    inv[N] = qpow(fact[N],MOD-2);
    for(int i = N-1;i>=0;--i){
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
}

ll C(ll n,ll k){
    if(k<0 || k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void solve(){
    ll n,x,t;
    cin>>n>>x>>t;

    if(x == n){
        cout<<(t==0?1:0)<<endl;
        return;
    }
    if(t == 0){
        cout<<0<<endl;
        return;
    }

    ll ans = 0;
    if(t&1){
        ans = 2 * C(x-1,(t+1)/2-1) % MOD * C(n-x-1,(t+1)/2-1) % MOD;
    }else{
        ans = (C(x-1,t/2 - 1) * C(n-x-1,t/2) % MOD + C(x-1,t/2) * C(n-x-1,t/2 - 1) % MOD)%MOD;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    return 0;
}