#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 998244353;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> dp(n+1,0);
    vector<ll> pre(n+1,0);
    vector<int> bit(64,0);
    ll p = 0;
    ll l = 1;
    dp[0] = 1;
    pre[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int k = 0;k<63;k++){
            if((a[i]>>k)&1){
                bit[k]++;
            }
            if(bit[k]>=2){
                p++;
            }
        }

        while(p > 0){
            for(int k = 0;k<63;k++){
                if((a[l]>>k)&1){
                    bit[k]--;
                    if(bit[k]==1){
                        p--;
                    }
                }
                
            }
            l++;
        }

        ll cur = pre[i-1];
        if(l>1){
            cur = (cur - pre[l-2] + MOD) % MOD;
        }
        dp[i] = cur;
        pre[i] = (pre[i-1] + cur) % MOD;

    }
    cout<<dp[n]<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}