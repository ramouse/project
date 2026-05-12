#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll,ll,ll>
#define pll pair<ll,ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;
const ll N = 1e5+5;

void solve()
{
    vector<ll> a;
    ll t;
    a.push_back(0);
    while(cin>>t){
        a.push_back(t);
    }
    // for(auto v : a) cout<<v<<" ";

    ll n = a.size();
    // cout<<n<<endl;
    vector<ll> dp(n+1,INF),low(n+1,0);
    ll len = 0;
    for(int i = 1;i<=n-1;i++){
        if(a[i] <= dp[len]){
            len++;
            dp[len] = a[i];
        }else{
            ll idx = upper_bound(dp.begin()+1,dp.begin()+1+len,a[i],greater<ll>())-dp.begin();
            dp[idx] = a[i];
        }
    }

    ll len1 = 0;
    for(int i = 1;i<=n-1;i++){
        if(a[i]>low[len1]){
            len1++;
            low[len1] = a[i];
        }else{
            ll idx = lower_bound(low.begin()+1,low.begin()+len1+1,a[i])-low.begin();
            low[idx] = a[i];
        }
    }
    cout<<len<<endl<<len1;

}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}