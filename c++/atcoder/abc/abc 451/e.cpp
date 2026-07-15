#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> edge(n+1,vector<ll>(n+1,0));
    for(int i = 1;i<=n-1;i++){
        for(int j = i+1;j<=n;j++){
            cin>>edge[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}