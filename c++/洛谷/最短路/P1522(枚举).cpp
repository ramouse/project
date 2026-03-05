#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pldl pair<long double,ll>

const ll INF = 1e18;

struct DSU {
    std::vector<int> parent;
    std::vector<int> siz; // 记录每个集合的大小
    int count;            // 记录连通分量的数量

    // 初始化：n 为节点数量
    DSU(int n) : parent(n + 1), siz(n + 1, 1), count(n) {
        // 初始时每个节点的父节点是自己
        std::iota(parent.begin(), parent.end(), 0); 
    }

    // 查找 (Find) - 路径压缩
    int find(int x) {
        // 如果 x 不是根节点，递归找根，并进行路径压缩
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // 合并 (Union) - 按大小合并
    // 返回值：true 表示合并成功（原本不在一组），false 表示原本就在一组
    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false; // 已经在同一个集合

        // 启发式合并：把小的集合合并到大的集合上，保持树的高度较低
        if (siz[rootX] < siz[rootY]) std::swap(rootX, rootY);
        
        parent[rootY] = rootX; // Y 挂到 X 上
        siz[rootX] += siz[rootY]; // 更新 X 的大小
        count--; // 连通分量减少一个
        return true;
    }

    // 判断是否连通
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // 获取某个节点所在集合的大小
    int getSize(int x) {
        return siz[find(x)];
    }
};

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> pos(n+1);
    for(int i = 1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        pos[i] = {x,y};
    }
    vector<string> adj(n+1);
    for(int i  = 1;i<=n;i++){
        cin>>adj[i];
        adj[i] = " "+adj[i];
    }

    DSU dsu(n);
    //将连通的牧区进行合并
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(adj[i][j] == '1'){
                dsu.merge(i,j);
            }
        }
    }
    //找出所有不连通的节点
    vector<pair<ll,ll>> dif;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(!dsu.connected(i,j)){
                dif.push_back({i,j});
            }
        }
    }

    auto Get = [](ll x1,ll y1,ll x2,ll y2){
        return sqrt((x2-x1) * (x2 - x1) + (y2-y1) * (y2-y1));
    };

    auto dij = [&](ll i){
        double res = 0.0;
        vector<double> dist(n+1,INF);
        priority_queue<pldl,vector<pldl>,greater<pldl>> pq;
        pq.push({0.0,i});
        dist[i] = 0;
        
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d>dist[u]) continue;

            res = max(res, dist[u]);

            for(int v = 1;v<=n;v++){
                if(adj[u][v] == '1'){
                    double len = Get(pos[u].first,pos[u].second,pos[v].first,pos[v].second);
                    if(dist[v]>dist[u]+len){
                        dist[v] = dist[u] + len;
                        
                        pq.push({dist[v],v});
                    }
                }
            }
        }
        return res;
    };

    //中文版
//--————————————————————————————————————————————————————————————--
    // vector<double> dist(n+1,0.0);
    // vector<double> comm(n+1,0.0);
    // double ans = INF;

    // for (int j = 1; j <= n; j++)
    // {
    //     dist[j] = dij(j);
    // }

    // for(int i = 1;i<=n;i++){
    //     ll root = dsu.find(i);
    //     comm[root] = max(comm[root],dist[i]);
    // }

    // for(int i = 0;i<dif.size();i++){
    //     ll u = dif[i].first;
    //     ll v = dif[i].second;

    //     double cur = dist[u] + dist[v] + Get(pos[u].first, pos[u].second, pos[v].first, pos[v].second);
    //     cur = max({cur,comm[dsu.find(u)],comm[dsu.find(v)]});
    //     ans = min(ans,cur);
    // }
    // cout << fixed << setprecision(6) << ans << endl;

    //英文版
//--——————————————————————————————————————————————————————————--
    vector<double> dist(n+1,0.0);
    double ans = INF;
    double maxx = 0.0;
    for (int j = 1; j <= n; j++)
    {
        dist[j] = dij(j);
        maxx = max(maxx, dist[j]);
    }

    for(int i = 0;i<dif.size();i++){
        ll u = dif[i].first;
        ll v = dif[i].second;

        double cur = dist[u] + dist[v] + Get(pos[u].first, pos[u].second, pos[v].first, pos[v].second);
        cur = max(cur,maxx);
        ans = min(ans,cur);
    }
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}