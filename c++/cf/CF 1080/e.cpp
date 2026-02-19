#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N  = 3e5+5;
const int MOD = 1e9+7;

vector<ll> tree[N];
ll t[N];
ll ans[N];

void dfs1(int u){
    if(tree[u][0] == 0 && tree[u][1] == 0){
        t[u] = 1;
        return;
    }

    dfs1(tree[u][0]);
    dfs1(tree[u][1]);
    t[u] = (t[tree[u][0]] + t[tree[u][1]] + 3) % MOD;
}

void dfs2(int u,ll p){
    ans[u] = (p + t[u]) % MOD;

    if(tree[u][0] != 0 && tree[u][1] != 0){
        dfs2(tree[u][0],ans[u]);
        dfs2(tree[u][1],ans[u]);
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        ll l,r;
        cin>>l>>r;
        tree[i].push_back(l);
        tree[i].push_back(r);
    }
    dfs1(1);
    dfs2(1,0);

    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<=n;i++) tree[i].clear();
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}