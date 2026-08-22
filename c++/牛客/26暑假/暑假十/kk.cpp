#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{   
    
    ll n;
    cin>>n;
    ll m=3*n;
    vector<vector<ll>>v(m,vector<ll>(m,0));
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    
    ll te[24][24][24]={0};
    for(ll i=0;i<m;i++)
    {
        for(ll j=i+1;j<m;j++)
        {
            for(ll k=j+1;k<m;k++)
            {
                te[i][j][k]=v[i][j]+v[j][k]+v[i][k];
            }
        }
    }

    ll total=(1<<m);
    ll full=total-1;
    vector<ll>dp(total,-LLONG_MAX);
    dp[0]=0;
    
    for(ll mask=0;mask<total;mask++)
    {
        ll cur=dp[mask];
        if (cur == -LLONG_MAX)continue;
        ll rem=full&~mask;
        ll lowi=rem&-rem;
        ll i = 63-__builtin_clzll(lowi);

        for(ll t=rem^lowi;t;t^=(t&-t))
        {
            ll lowj=t&-t;
            ll j = 63-__builtin_clzll(lowj);
            for(ll t1=t^lowj;t1;t1^=(t1&-t1))
            {
                ll lowk=t1&-t1;
                ll k = 63-__builtin_clzll(lowk);

                ll nmask=mask|lowi|lowj|lowk;
                if(dp[mask]+te[i][j][k]>dp[nmask])
                {
                    dp[nmask]=dp[mask]+te[i][j][k];
                }
            }
        }
    }

    cout<<dp[full]<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}