#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n+1,vector<ll>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            ll up = (j > 1 ? a[i][j-1] : 0);
            ll left = (i > 1 ? a[i-1][j] : 0);
            ll di = (i > 1 && j > 1 ? a[i-1][j-1] : 0);
            ll d = a[i][j] - up - left + di;
            if(d > 0){
                cout<<-1<<endl;
                return;
            }
            ans+=(-d);
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();

    return 0;
}