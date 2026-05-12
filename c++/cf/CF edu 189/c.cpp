#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    vector<string> s(3);
    for(int i = 1;i<=2;i++){
        cin>>s[i];
    }
    vector<ll> dp(n+1,INF);
    dp[0] = (s[1][0] == s[2][0])?0:1;
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1] + ((s[1][i] == s[2][i]) ? 0 : 1);
        if(i == 1){
            dp[i] = min(dp[i], ((s[1][i - 1] == s[1][i]) ? 0LL : 1LL) + ((s[2][i - 1] == s[2][i]) ? 0LL : 1LL));
        }
        if(i>1){
            dp[i] = min(dp[i],dp[i-2] + ((s[1][i-1] == s[1][i]) ? 0LL : 1LL) + ((s[2][i-1] == s[2][i]) ? 0LL : 1LL));
        }
    }
    cout<<dp[n-1]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}