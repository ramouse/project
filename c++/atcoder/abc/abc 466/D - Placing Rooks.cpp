#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;



void solve()
{
    ll n,m;
    cin>>n>>m;
    // vector<int> R(n+1,0),C(n+1,0);
    // vector<vector<int>> vis(n+1,vector<int>(n+1,0));
    // vector<pair<int,int>> ti(m+1);

    // for(int i = 1;i<=m;i++){
    //     ll r,c;
    //     cin>>r>>c;
    //     R[r]++,C[c]++;
    //     // if(R[r] & 1 || C[c] & 1){

    //     // }else{
           
    //     // }
    //     vis[r][c] = i;
    //     ti[i] = {R[r],C[c]};
    // }

    // int ans = 0;
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         if(vis[i][j] == 0) continue;

    //         int time = vis[i][j];
    //         int rr = ti[time].first,cc = ti[time].second;
    //         int r = R[i] - rr,c = C[j] - cc;

    //         if(!(r & 1) && !(c & 1)){
    //             ans++;
    //             // cout<<i<<" "<<j<<endl;
    //         }
    //     }
    // }

    // // cout<<R[1]<<" "<<C[3]<<endl;
    // cout<<ans<<endl;

    vector<bool> R(n+1,0),C(n+1,0);
    vector<pair<ll,ll>> vec(m+1);
    for(int i = 1;i<=m;i++){
        cin>>vec[i].first>>vec[i].second;
    }

    ll ans = 0;
    for(int i = m;i;--i){
        ll r = vec[i].first;
        ll c = vec[i].second;

        if(!R[r] && !C[c]){
            ans++;
        }

        R[r] = 1,C[c] = 1;
    }

    cout<<ans<<endl;
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