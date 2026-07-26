#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 1048576;
const ll INF = 1e18;

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
            res = res * a ;
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> h(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>h[i];
    }
    vector<ll> dp(n+1,INF);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    for(int i = 3;i<=n;i++){
        // dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]),dp[i-2] + abs(h[i] - h[i-2]));
        ll cur = INF;
        ll idx = 0;
        for(int j = i-1;j>=max(1LL,i-k);j--){
            if(abs(h[i] - h[j]) + dp[j]< cur){
                idx = j;
                cur = abs(h[i] - h[j]) + dp[j];
            }
            // cur = min(cur,abs(h[i]-h[j]));
        }
        dp[i] = min(dp[i],cur);
    }
    // for(int i = 1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    cout<<dp[n]<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cout<<'j'-'0'-'0'<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}