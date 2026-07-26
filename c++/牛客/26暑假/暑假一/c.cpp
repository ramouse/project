#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

struct DSU{
    vector<ll> parent;
    vector<ll> sz;
    vector<ll> maxx;
    vector<ll> val;

    DSU(ll n) : parent(n+1,0),sz(n+1,1),maxx(n+1,-INF),val(n+1,0){
        iota(parent.begin(),parent.end(),0);
    }

    ll find(ll x){
        if(parent[x] == x) return x;

        ll root = find(parent[x]);
        maxx[x] = max(maxx[x],maxx[parent[x]]);
        return parent[x] = root;
    }

    void mereg(ll u,ll v,ll va){
        // u 是新加入的节点
        ll rootv = find(v);
        if(rootv != u){
            maxx[rootv] = va - sz[rootv] + 1;
            parent[rootv] = u;
            sz[u] += sz[rootv];
        }
    }
};

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void solve()
{   
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> grid(n+1,vector<ll>(m+1,0));
    DSU dsu(q+1);

    ll last = 0;
    ll cnt = 0;
    while(q--){
        ll op;
        cin>>op;
        if(op == 1){
            ll x,y,v;
            cin>>x>>y>>v;
            x = x ^ last;
            y = y ^ last;

            cnt++;
            grid[x][y] = cnt;
            dsu.val[cnt] = v;

            vector<ll> vec;
            for(int i = 0;i<4;i++){
                ll xx = x + dx[i],yy = y + dy[i];
                if(xx >=1 && xx<=n && yy >= 1 && yy <= m && grid[xx][yy] > 0){
                    vec.push_back(grid[xx][yy]);
                }
            }

            vec.erase(unique(vec.begin(),vec.end()),vec.end());
            for(auto vv : vec){
                dsu.mereg(cnt,vv,v);
            }

            last = dsu.sz[cnt] - 1;
            cout<<last<<endl;
        }else{
            ll x,y;
            cin>>x>>y;
            x = x ^ last;
            y = y ^ last;

            ll id = grid[x][y];
            dsu.find(id);
            last = max(0LL,dsu.maxx[id] - dsu.val[id]);
            cout<<last<<endl;
        }
    }

}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}