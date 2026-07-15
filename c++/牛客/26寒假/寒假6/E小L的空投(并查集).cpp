#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 5e5+5;
vector<ll> adj[N];

struct DSU
{
    std::vector<int> parent;
    std::vector<int> siz; // 记录每个集合的大小
    int count;            // 记录连通分量的数量

    // 初始化：n 为节点数量
    DSU(int n) : parent(n + 1), siz(n + 1, 1), count(n)
    {
        // 初始时每个节点的父节点是自己
        std::iota(parent.begin(), parent.end(), 0);
    }

    // 查找 (Find) - 路径压缩
    int find(int x)
    {
        // 如果 x 不是根节点，递归找根，并进行路径压缩
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // 合并 (Union) - 按大小合并
    // 返回值：true 表示合并成功（原本不在一组），false 表示原本就在一组
    bool merge(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false; // 已经在同一个集合

        // 启发式合并：把小的集合合并到大的集合上，保持树的高度较低
        if (siz[rootX] < siz[rootY])
            std::swap(rootX, rootY);

        parent[rootY] = rootX;    // Y 挂到 X 上
        siz[rootX] += siz[rootY]; // 更新 X 的大小
        count--;                  // 连通分量减少一个
        return true;
    }

    // 判断是否连通
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    // 获取某个节点所在集合的大小
    int getSize(int x)
    {
        return siz[find(x)];
    }
};

int main(){
    ll n,m,x,d;
    
    cin>>n>>m>>x>>d;
    vector<pair<ll, ll>> h(n + 1);
    for(int i = 1;i<=n;i++){
        ll t;
        cin>>t;
        h[i] = make_pair(i,t);
    }
    sort(h.begin()+1,h.end(),[](auto &x,auto &y){
        return x.second > y.second;
    });

    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> H(x+1,0);
    for(int i = 1;i<=x;i++){
        cin>>H[i];
    }

    DSU dsu(n);
    ll ptr = 1;
    vector<bool> activ(n+1,0);
    vector<ll> ans(x+1,0);
    ll cur = 0;
    for(int i = x;i;--i){
        while(ptr<=n && h[ptr].second > H[i]){
            int u = h[ptr].first;
            activ[u] = 1;

            if(dsu.siz[u]>=d) cur++;

            for(int v : adj[u]){
                if(activ[v]){
                    int rootu = dsu.find(u);
                    int rootv = dsu.find(v);

                    if(rootu != rootv){
                        if(dsu.siz[rootu]>=d) cur--;
                        if(dsu.siz[rootv]>=d) cur--;

                        dsu.merge(rootu,rootv);
                        if(dsu.getSize(u) >= d) cur++;
                    }
                }
            }
            ptr++;
        }
        ans[i] = cur;
    }
    for (int i = 1; i <= x; ++i)
    {
        cout << ans[i] << endl;
    }

    return 0;
}