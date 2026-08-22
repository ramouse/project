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
    vector<vector<ll>> vec(3*n+1,vector<ll>(3*n+1,0));
    for(int i = 1;i<=3*n;i++){
        for(int j = 1;j<=3*n;j++){
            cin>>vec[i][j];
        }
    }

    ll ans = 0;
    vector<int> vis(3*n+1,0);
    vector<ll> group;
    // auto dfs = [&](auto &&self,ll u) -> ll{
    //     if(group.size() == 3){
    //         return vec[group[0]][group[1]] + vec[group[0]][group[2]] + vec[group[1]][grou1[2]];
    //     }

    //     ll cur = 0;
    //     T t;
    //     for(int i = 1;i<=3*n;i++){
    //         for(int j = 1;j<=3*n;j++){
    //             if(i != j && !vis[i] && !vis[j]){
    //                 vis[i] = 1,vis[j] = 1;
    //                 if(self(self,u) > cur){
    //                     t = {u,i,j}
    //                 }
    //             }
    //         }
    //     }
    // };

    for(int i = 1;i<=3*n;i++){
        if(!vis[i]){
            ll cur = -INF;
            T t = {0,0,0};
            for(int j = 1;j<=3*n;j++){
                for(int k = 1;k<=3*n;k++){
                    if(j != i && j != k && k != i){
                        if(!vis[j] && !vis[k]){
                            if(vec[i][j] + vec[i][k] + vec[j][k] > cur){
                                auto [f,s,c] = t;
                                // vis[f] = vis[s] = vis[c] = 0;
                                cur = vec[i][j] + vec[i][k] + vec[j][k];
                                // vis[i] = vis[j] = vis[k] = 1;
                                t = {i,j,k};
                            }
                            // cout << i << " " << j << " " << k << endl;
                        }
                    }
                }
            }
            auto [f,s,c] = t;
            vis[f] = vis[s] = vis[c] = 1;
            ans += cur;
            // cout<<f<<" "<<s<<" "<<c<<endl;
        }
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
        solve();
}