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

void solve()
{  
    ll n,m;
    cin>>n>>m;

    vector<Node> vec;
    vector<vector<ll>> v(n+1,vector<ll>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            ll x;
            cin>>x;
            v[i][j] = x;
            vec.push_back({i,j,x});
        }
    }

    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    sort(vec.begin(),vec.end(),[&](const auto& a,const auto& b){
        return a.val > b.val;
    });

    vector<vector<int>> vis(n+1,vector<int>(m+1,-1));
    for(int i = 0;i<vec.size();i++){
        ll x = vec[i].x;
        ll y = vec[i].y;
        ll val = vec[i].val;
        bool ok = false;
        for (int j = 0; j < 4; j++)
        {
            ll xx = x + dx[j];
            ll yy = y + dy[j];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
            {
                if (v[xx][yy] > val)
                {
                    if(vis[xx][yy] == 0){
                        ok = true;
                        break;
                    }
                }
            }
        }

        if(ok) vis[x][y] = 1;
        else vis[x][y] = 0;
    }

    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=m;j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    

    ll q;
    cin>>q;
    while(q--){
        ll r,c;
        cin>>r>>c;

        if(vis[r][c] == 1) cout<<"First"<<endl;
        else cout<<"Second"<<endl; 
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}