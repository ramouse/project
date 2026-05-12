#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5;

void solve()
{
    vector<vector<ll>> vec(4,vector<ll>(7,0)),vis(4,vector<ll>(7,0));
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=6;j++){
            cin>>vec[i][j];
            vis[i][vec[i][j]]++;
        }
    }

    double ans = 0.0;
    for(int i = 1;i<=6;i++){
        for(int j = 1;j<=6;j++){
            for(int k = 1;k<=6;k++){
                set<ll> se;
                se.insert(vec[1][i]);
                se.insert(vec[2][j]);
                se.insert(vec[3][k]);
                if(se.count(4) && se.count(5) && se.count(6)) ans++;
            }
        }
    }

    printf("%.10lf",ans/216.0);
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}