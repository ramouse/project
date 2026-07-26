#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll LOG = 31;
const ll MOD = 998244353;

struct Node{
    ll x,y,val;
};

struct N{
    ll r,mn,ma;
};

void solve()
{  
    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>> pos(n*m + 1);
    vector<vector<ll>> diff(n+5,vector<ll>(m+5,0));

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            ll x;
            cin>>x;
            pos[x].push_back({i,j});
        }
    }
    for(int i = 1;i<=n*m;i++){
        if(!pos[i].empty()){
            sort(pos[i].begin(),pos[i].end(),[&](const auto&x,const auto&y){
                if(x.first != y.first) return x.first < y.first;
                else return x.second < y.second;
            });

            vector<N> vec;
            for(int j = 0;j<pos[i].size();){
                int k = j;
                ll minn = INF;
                ll maxx = 0;
                while(k < pos[i].size() && pos[i][k].first == pos[i][j].first){
                    minn = min(minn, pos[i][k].second);
                    maxx = max(maxx, pos[i][k].second);
                    k++;
                }
                vec.push_back({pos[i][j].first,minn,maxx});
                j = k;
            }

            if(vec.size() < 2) continue;

            vector<ll> minn(vec.size() + 1,INF),maxx(vec.size() + 2,0);
            minn[0] = vec[0].mn;
            // maxx[vec.size()-1] = vec.back().ma;
            for(int j = 1;j<vec.size();j++){
                minn[j] = min(minn[j-1],vec[j].mn);
            }
            for(int j = vec.size() - 1;j>=0;j--){
                maxx[j] = max(maxx[j+1],vec[j].ma);
            }
            for(int j = 0;j<vec.size()-1;j++){
                if(minn[j] < maxx[j+1]){
                    ll r1 = vec[j].r,c1 = minn[j];
                    ll r2 = vec[j+1].r,c2 = maxx[j+1];
                    diff[r1][c1]++;
                    diff[r1][c2 + 1]--;
                    diff[r2 + 1][c1]--;
                    diff[r2 + 1][c2 + 1]++;
                }
            }
        }
    }

    // for(int i = 0;i<=n+1;i++){
    //     for(int j = 0;j<=m+1;j++){
    //         cout<<diff[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            
            cout<<(diff[i][j] == 0 ? 0 : 1);
        }
        cout<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}