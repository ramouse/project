#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;
const ll N = 1e6 + 6;

// 优先队列节点，用于维护缓存淘汰的优先级
struct Node{
    ll nxt, dep, u;

    // 核心贪心策略（Belady 算法）：优先淘汰“下一次访问时间”最晚的节点
    bool operator< (const Node& o) const{
        // 如果下一次访问时间相同（或都是 INF 不再访问），则优先淘汰深度更大的节点（即更靠外的叶子节点）
        if(nxt == o.nxt) return dep < o.dep; 
        // 否则，下一次访问时间越晚 (nxt 越大)，越优先被弹出淘汰
        else return nxt < o.nxt; 
    }
};

// 全局静态数组开字典树，避免局部变量导致栈溢出 (最大节点数 10^6，字符集 26)
ll trie[N + 1][26];

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll tot = 1; // 字典树节点计数器，根节点为 1
    vector<ll> dep(N + 1, 0); // 记录每个节点的深度
    vector<string> s(n + 1);  // 记录所有的请求字符串
    
    // pos[u] 记录字典树上节点 u 在哪些请求（时间点）被访问过
    // 这是离线算法的核心：预知未来，为后续的缓存淘汰提供“下一次访问时间”
    vector<vector<ll>> pos(N + 1); 

    // 第一阶段：离线建树与收集访问时间线
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        
        ll u = 1; // 从根节点出发
        for(char c : s[i]){
            // 如果节点不存在，则创建新节点
            if(!trie[u][c - 'a']){
                trie[u][c - 'a'] = ++tot;
                dep[tot] = dep[u] + 1; // 新节点的深度是父节点深度 + 1
            }
            u = trie[u][c - 'a'];
            pos[u].push_back(i); // 记录节点 u 在第 i 次请求中被访问
        }
    }

    priority_queue<Node> pq; // 最大堆，用于延迟删除维护缓存

    ll sz = 0;  // 当前缓存中的节点数量（边数）
    ll ans = 0; // 记录总的计算代价值
    vector<bool> incache(N + 1, 0); // 标记节点当前是否在缓存中
    vector<ll> ptr(N + 1, 0);       // 指针，用于在 pos[u] 数组中快速找到“下一次访问时间”

    // 第二阶段：模拟请求与缓存状态维护
    for(int i = 1; i <= n; i++){
        ll len = s[i].size();
        ll u = 1;
        
        // 找出当前字符串在字典树上对应的完整路径
        vector<ll> path;
        for(char c : s[i]){
            u = trie[u][c - 'a'];
            path.push_back(u);
        }

        // 计算命中的前缀长度 L（从上到下必须连续存在于缓存中）
        ll L = 0;
        while(L < len && incache[path[L]]){
            L++;
        }
        
        // 增加计算代价：字符串总长度减去已命中缓存的长度
        ans += len - L;

        // 将缺失的节点加入缓存，并更新路径上所有节点的“下一次访问时间”
        for(ll v : path){
            ptr[v]++; // 指针后移，指向该节点的下一次访问请求
            
            // 如果未来还有访问，记录时间；如果没有了，设为 INF（正无穷，确保最先被淘汰）
            ll nxt = (ptr[v] < pos[v].size() ? pos[v][ptr[v]] : INF);

            // 如果节点不在缓存中，将其加入缓存
            if(!incache[v]){
                incache[v] = 1;
                sz++;
            }

            // 将更新后的节点状态压入优先队列
            pq.push({nxt, dep[v], v});
        }

        // 第三阶段：缓存超载时的淘汰逻辑 (延迟删除 Lazy Deletion)
        while(sz > m){
            auto [nxt, de, u] = pq.top();
            pq.pop();

            // 无论是因为不在缓存还是彻底过期 (INF)，都执行淘汰清理。
            // 注意：这里由于上下逻辑完全一致，实际上起到了强行清理堆顶元素释放空间的作用。
            if(!incache[u] || nxt == INF){
                incache[u] = 0; // 标记移出缓存
                sz--;           // 缓存占用量 -1
                continue;
            }

            // 常规的淘汰移出缓存
            incache[u] = 0;
            sz--;
        }
    }

    cout << ans << endl;
}

int main()
{
    // 提升 cin/cout 读写速度
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t; // 多组测试用例时取消注释
    while (t--)
        solve();
}