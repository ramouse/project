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
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> dp1(n+1,1),dp2(n+1,1);
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(a[j]<a[i]){
                dp1[i] = max(dp1[i],dp1[j]+1);
            }
        }
    }

    for(int i = n-1;i;--i){
        for(int j = n;j>=i;--j){
            if(a[j]<a[i]){
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans = max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<n-ans<<endl;
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