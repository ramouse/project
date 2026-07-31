#include<bits/stdc++.h> 
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> vec(n+1,vector<ll>(m+1,0));
    vector<vector<ll>> cost(m+1,vector<ll>((1<<m)+1,0)); 
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>vec[i][j];
            
        }
        string s;
        cin>>s;

        ll fmask = 0;
        for(int j = 0;j<s.size();j++){
            if(s[j] == 'R'){
                fmask += (1<<j);
            }
        }

        for(int j = 1;j<=m;j++){
            cost[j][fmask] += vec[i][j];
        }
    }

    for(int k = 1;k<=m;k++){
        for(int i = 0;i<m;i++){
            for(int mask = 0;mask<(1<<m);mask++){
                if(mask & (1<<i)){
                    cost[k][mask] += cost[k][mask^(1<<i)];
                }
            }
        }
    }

    vector<ll> dp((1<<m) + 1,INF);
    dp[0] = 0;

    ll allmask = (1<<m)-1;
    for(int mask = 0;mask<=allmask;mask++){
        ll comp = allmask ^ mask;

        for(int k = 0;k<m;k++){
            if(!((1<<k) & mask)){
                ll next = mask | (1 << k);
                dp[next] = min(dp[next],dp[mask] + cost[k+1][comp]);
            }
        }
    }

    cout<<dp[allmask]<<endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}