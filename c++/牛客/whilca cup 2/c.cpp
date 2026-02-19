#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 2e5+5;

ll n, m;
vector<ll> adj[N];
ll depth[N];
ll fat[N];
vector<ll> F[N];
ll H;
vector<ll> val(N, 0);
vector<ll> dval(N, 0);
vector<ll> uval(N, 0);

void dfs(int u,int fa,int d){
    depth[u] = d;
    fat[u] = fa;
    F[d].push_back(u);
    H = max(H,depth[u]);

    for(int v : adj[u]){
        if(v == fa) continue;
        dfs(v,u,d+1);
    }
}

void solve(){

    cin>>n>>m;

    for(int i = 1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);

    for(int i = 1;i<=m;i++){
        ll a,t;
        cin>>a>>t;
        if(H-depth[a]<=t) val[a]++;
    }


    for(int i = H;i>=0;i--){
        for(int u : F[i]){
            ll maxx = 0;
            for(int v : adj[u]){
                if(v == fat[u]) continue;
                maxx = max(maxx,dval[v]);
            }
            dval[u] = maxx + val[u]; 
        }
    }


    for(int i = 0;i<=H;i++){
        for(int u : F[i]){
            uval[u] = val[u] + uval[fat[u]];
        }
    }

    ll ans = 0;
    for(int i = 1;i<=H;i++){
        ll md = 0;
        ll mu = 0;
        for(int u : F[i]){
            md = max(md,dval[u]);
        }
        for(int u : F[i-1]){
            mu = max(mu,uval[u]);
        }
        ans = max(ans,mu + md);
    }
   
    cout<<ans<<endl;

    H = 0;
    for(int i = 0;i<=n;i++){
        val[i] = 0;
        dval[i] = 0;
        uval[i] = 0;
        adj[i].clear();
        F[i].clear();
        depth[i] = 0;
        fat[i] = 0;
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}