#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 3e5+3;
const int LOG = 20;

vector<ll> adj[N];

vector<ll> in(N),out(N);
ll tim =0;
vector<ll> sz(N,0);  //统计子树大小
vector<vector<ll>> up(N,vector<ll>(LOG,0));  //倍增祖先 up[u][i]表示u向上跳2^i步到达的节点
vector<ll> depth(N,0);  //统计深度


void dfs(int u,int fa,int d){
    in[u] = ++tim;
    depth[u] = d;
    sz[u] = 1;

    up[u][0] = fa;
    for(int i = 1;i<LOG;i++){
        if(up[u][i-1] != 0){
            up[u][i] = up[up[u][i-1]][i-1];
        }else{
            up[u][i] = 0;
        }
    }

    for(int v:adj[u]){
        if(v == fa) continue;
        dfs(v,u,d+1);
        sz[u] += sz[v]; //累加子树大小
    }
    out[u] = ++tim;
}

bool isAncestor(int u,int v){
    return in[u] <= in[v] && out[v] <= out[u];
}

int main(){
    ll n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);

    ll q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;

        if(u == v){
            cout<< 0 <<endl;
            continue;
        }

        if(isAncestor(u,v)){ //如果 u 是 v 的祖先，那么删除u后v所在连通块的大小就是u和v所在连通块中，u的下一个单元
            for(int i = LOG -1 ;i>=0;i--){
                if(up[v][i] != 0 && depth[up[v][i]] > depth[u]){
                    v = up[v][i];
                }
            }
            cout<<sz[v]<<endl;
        }else{
            cout<< n - sz[u]<<endl;
        }
    }


    return 0;
}