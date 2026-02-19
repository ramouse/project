#1.队列

##queue (<queue>)

队列 (queue)，是一种先进先出的数据结构

```c++
std::queue<T> q;
q.push(x); // 元素 x 入队
q.pop(); // 元素 x 出队
q.top(); // 返回栈顶元素
q.front(); // 返回队列的队首元素
q.back(); // 返回队列的队尾元素
q.empty();//检查是否为空,空返回1否则返回0
q.size();//获取大小
```



##deque (<deque>)

双端队列  (deque)，可以理解为一个双端数组

```c++
std::deque<int> dq;
dq.push_back(x); // 在末尾加入一个元素
dq.pop_back(); // 删除末尾的元素
dq.push_front(x); // 在开头加入一个元素
dq.pop_front(); // 删除开头的元素
dq.front(); // 返回数组的开头元素
dq.back() // 返回数组的末尾元素
// 中括号随机访问，i 是下标
dq[i] = x；
dq.empty();//检查是否为空,空返回1否则返回0
dq.size();//获取大小
```



##priority_queue (<priority_queue>)

优先队列 (priority_queue)，也是一种堆，可以方便获取最值。

```c++
std::priority_queue<int> pq; // C++默认大根堆  栈顶元素永远最大 d
std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // 小根堆  栈顶元素永远最小  单调递减
pq.push(x); // 将元素 x 放入堆中
pq.pop(); // 将堆顶元素删除
pq.top(); // 返回堆顶元素，大根堆返回最大值，小根堆返回最小
pq.empty();//检查是否为空,空返回1否则返回0
pq.size();//获取大小
```



# 2.容器



## 2.1vector (<vector>)

- 定义

```c++
std::vector<T> vec; // 不写任何参数，创建一个长度为 0，没有元素的数组
std::vector<T> vec(n, val)； // 创建一个长度为 n ，全部元素均为 val 的数组，val可以不写，不写时填 T 的默认构造
std::vector<T> vec(vec_)；// 拷贝构造函数，把 vec_ 的所有内容拷贝过

//二维vector的定义，n*m大小
std::vector<std::vector<T>> vec(n,std::vector<T>(m));   
//遍历用for即可
```

- 常用成员

```c++
std::vector<T> vec; // 先提前声明一个 T 类型的 vector
 vec.push_back(x); // 最后放入一个元素 x
 vec.pop_back(); // 去除最后一个元素
// 中括号随机访问，这里 i 是一个下标
vec[i] = x;
vec.back()； // 返回 vector 最后一个元素
vec.clear();//清空vector
vec.size();//获取大小
```

注意：用push_back会引发动态扩容



## 2.2set (<set>)

集合 (set)，满足所有元素在里面只会出现至多一次且默认有序

- 

```c++
std::set<T> s; // 构造一个空集合
std::set<T> s(s_); // 将集合 s_ 的内容复制到 s 中
```

- 

```c++
std::set<T> s;
s.insert(x); // 将 x 放入集合中，如果已经有了，不进行任何操作
s.count(x); // 返回 x 在集合中的出现次数，由于集合的特性，可以理解为判断 x 是否存在在集合中
s.erase(x); // 删除 x
s.find(x); // 返回一个指向元素 x 的迭代器，找不到则返回 s.end()
s.empty();//检查是否为空,空返回1否则返回0
s.size();//获取大小
```



## 2.3multiset (<set>)

多重集 (multiset)，也是一个集合，但是一种元素可以出现多次

- 

```c++
std::multiset<T> s;
s.count(x); // 返回 x 在 s 中的出现次数
s.erase(x); // 删除 x 在 s 中的 所有 出现
s.extract(x); // 删除 x 在 s 中的一个出现
s.find(x); // 返回 x 在 s 中的一个出现的迭代器
s.empty();//检查是否为空,空返回1否则返回0
s.size();//获取大小
```



## 2.4pair(<utility>)

对组 (pair)，存放两个信息：first, second，相当于一个存放两个变量的类

当一个函数需要返回2个数据的时候，可以选择pair

- 

```c++
std::pair<T1, T2> p；//T1和T2b
p1.first;// 返回对象p1中名为first的公有数据成员
p1.second;// 返回对象p1中名为second的公有数据成员
```



## 2.5map (<map>)

`map` 容器中的元素是按照键的顺序自动排序的，这使得它非常适合需要快速查找和有序数据的场景。

- 

```c++
std::map<key_type，value_type> myMap  
//可声明多维map，例
std::map<int,map<int,int>> myMap;
//遍历
for (auto [key, value] : f) {
 std::cout << key << " " << value << "\n";
}
```

- 

```c++
mp[x];//返回键x对应的值
myMap.erase(key);//清楚key对应的元素
myMap.clear();//清空容器
myMap.size();//h
myMap.count("Bob"); // key 是否存在存在返回1，否则返回0
```



## 2.6 stack (<stack>)

栈 (stack)，一种后进先出的数据结构，能高效匹配括号，也能处理递归问题等

- 

```c++
std::stack<T> st;
st.push(x) //将元素x压入栈中
st.top(); //返回栈顶元素，但不对其进行操作
st.pop(); //移除栈顶元素
s.empty();//检查是否为空,空返回1否则返回0
s.size();//获取大小
```



# 3 模板

## 3.1 单调队列 滑动窗口

```c++
	for(int i=1;i<=n;i++){
        while((!dq.empty()) && a[dq.back()] <= a[i]) 		           		dq.pop_back();
        dq.push_back(i);
        if(dq.front() == i - k){
            dq.pop_front();//移除过期数据
        }
        if(i>=k)
            cout << a[dq.front()] <<" ";//输出窗口每次移动的最大值
    }//输出长度为k窗口下的最大值
```

## 3.1.1 找出一定范围内不定长度的最大值

[P1714 切蛋糕 - 洛谷](https://www.luogu.com.cn/problem/P1714?contestId=290509)

找出位于m滑块下的不定长最大

简单思考可以得到，若使维护前缀和单调递增，那么得到的答案一定最优

```c++
deque<int> dq;
dq.push_back(0);//初始放入索引0
int ans = -1e8;//如果出现全负的数据，需要（此题不需要）
for (int i = 1; i <= n; i++) {
        // 维护窗口大小不超过 m，每次最多只有一个过期元素，所以可以用if，但用while更安全
        // 这里使用if是因为我们知道每次窗口移动一步，最多只有一个过期元素
        while (!dq.empty() && dq.front() < i - m) {
            dq.pop_front();
        }
        // 更新答案
        if (!dq.empty()) {
            ans = max(ans, prefix[i] - prefix[dq.front()]);
        }
        // 维护队列单调递增，这里必须用while，因为可能弹出多个
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) 		 {
            dq.pop_back();
        }//保证前缀和总是单调递增
        dq.push_back(i);
    }
```



## 3.2 单调栈

```c++
for (int i = 1; i <= n; i++)
    {
        while ((!st.empty()) && a[st.top()] < a[i])
        {
            int index = st.top();
            st.pop();
            ans[index] = i;
        }
        st.push(i);
    }
```

## 3.3 二分

```c++
	ll r = max;
    ll l = 1;
    ll ans = 0;

    while(l<=r){
        ll temp = 0;
        ll mid = (l + r) / 2;   

        for(int i = 0;i<n;i++){
            temp += a[i] / mid;
        }
        
        if(temp <k){
            r = mid - 1;
        }else{
            l = mid + 1;
            ans = mid;
        }

    }
```

## 3.4三分

**适用场景**：
用于在单峰函数（先增后减）或单谷函数（先减后增）上寻找极值。

- 如果函数是**凸的 (Convex)**（像 U 形）：求最小值。
- 如果函数是**凹的 (Concave)**（像 ∩ 形）：求最大值。

> **注意**：函数必须严格单调，若存在平坦区域（平台），三分可能会失效。

------



### 3.4.1 实数域三分 (浮点数)

这是最常用的场景（如几何题、物理题）。建议使用**固定迭代次数法**，比 while(r-l > eps) 更快且不易死循环。

```c++
    // 这里的 check 函数即题目中需要求极值的函数
double check(double x) {
    double res = 0;
    // ... 计算逻辑 ...
    return res;
}

void solve() {
    double l = 0, r = 1e9; // 根据题目范围设定
    
    // 【求最小值】 (U形函数)
    // 循环 100 次可以将精度控制在极高范围，通常优于设置 eps
    for (int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        
        // 如果 m1 处的函数值更小，说明极小值在 m2 左侧 (舍弃右边)
        // 注意：求最大值时，符号改为 >
        if (check(m1) < check(m2)) {
            r = m2; 
        } else {
            l = m1;
        }
    }
    
    // 最终结果 l 和 r 几乎相等，输出 l 或 r 均可
    printf("%.10f\n", l);
}
  
```



### 3.4.2 整数域三分

当坐标必须是整数时，由于整除截断问题，m1 和 m2 可能会重合。
**通用策略**：三分将范围缩小到很小（例如区间长度小于 3），然后暴力枚举剩余的几个点。

 code C++downloadcontent_copyexpand_less

```c++
long long solve() {
    long long l = 0, r = 1e9; // 假设求最大值

    // 1. 三分缩小范围，直到区间长度很小 (比如 <= 2)
    while (r - l > 2) { 
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        
        // 求最大值 (凹函数 ∩)
        // 谁小删谁 (m1 比较小，说明峰值在 m1 右侧)
        if (check(m1) < check(m2)) {
            l = m1; 
        } else {
            r = m2;
        }
    }

    // 2. 此时区间 [l, r] 只剩下 l, l+1, r 等 2~3 个点
    // 直接暴力求这几个点的最大值，绝对不会漏，也不会死循环
    long long ans = -1e18; // 初始极小值
    for (long long i = l; i <= r; i++) {
        ans = max(ans, check(i));
    }
    
    return ans;
}
```



## 3.5 字符串

### 3.5.1 统计字串个数

字串:对于字符串 s 与 t，如果存在 l 与 r 满足 $1 ≤l ≤r ≤n$ 且 $t = s_ls_{l+1} ···s_{r-1}s_r$，那么定义 t为 s 的子串。例如，`“garo”` 是 `“kangaroo”` 的子串，而 `“ko” `不是 `“kangaroo” `的子串。

```c++
int cout_find( string s, string p){
    int cnt = 0;
    size_t pos = 0;
    while((pos = s.find(p,pos)) != string::npos){
        cnt++;
        pos += 1;
    }
    return cnt;
}
```



### 3.5.2统计子序列个数

子序列:对于字符串s与t，字符串t在字符串s中于子序列的形式出现，意味着，字符串t可由s删除若干个字符得到（也可能是0个）

```c++
int Count(string s,string t){
    vector<ll> dp(t.length()+1,);
    dp[0] = 1;
    for(int i = 0;i<s.length();i++){
        for(int j = t.length();j;j--){
            if(s[i] == t[j-1]){
                dp[j] += dp[j-1];
            }
        }
    }  //dp[j] 的含义是：目标字符串 T 的“前 j 个字符”在当前扫描过的 S 中作为子序列出现了多少次。
    return dp[t.length()];
}//从后往前遍历t后，dp里分别表示的就是对应位置的前字符串能在s种组成几个
//例如 s="babg",t="bag"
//遍历完后，dp为[1,2,1,1]  dp[1]=2，表示"b"在s中有两个，dp[2]=1，表示"ba"在s中有1g
```



### 3.5.3 字典树

**利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较。**

```c++
const int N = 100010; // 根据题目总字符长度设定
int trie[N][26];       // 假设只存小写字母，每个节点最多26个子节点
int cnt[N];           // 计数器
int idx;              // 节点分配器，从0或1开始

// 插入字符串
void insert(string s) {
    int p = 0; // p代表当前所在的节点编号，0是根节点
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a'; // 将字符转化为 0-25 的数字
        if (!trie[p][u]) trie[p][u] = ++idx; // 如果没有路，这就新建一条路
        p = trie[p][u]; // 走到下一个节点
        cnt[p]++;      // 【重点】这里记录有多少个单词经过了这个节点
    }
}

// 查询前缀出现次数（例如查 "ca" 是多少个单词的前缀）
int query(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!trie[p][u]) return 0; // 路断了，说明不存在这个前缀
        p = t[p][u];
    }
    return cnt[p]; // 返回经过这个节点的数量
}
```



## 3.6 搜索

```c++
void dfs(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

//二者等价

void dfs(int u,int fa){
    for(int v = 0;v<adj[u].size();u++){
        if(adj[u][v] == fa)
            continue;
        dfs(adj[u][v],u);
    }
}


//统计子树+公共祖先倍增

vector<ll> in(N),out(N);  //统计进出x
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

bool isAncestor(int u,int v){ //判断v是否是u的祖先
    return in[u] <= in[v] && out[v] <= out[u];
}

// 找到 v 的祖先中，是 u 的直接子节点的那个点
// 前提：u 是 v 的严格祖先
int getChildTowards(int u, int v) {  //获取u-1
    
    for (int i = LOG - 1; i >= 0; i--) {
        // 如果跳一步之后，深度仍然比 u 大（说明还在 u 下面），就往上跳
        if (up[v][i] != 0 && depth[up[v][i]] > depth[u]) {
            v = up[v][i];
        }
    }
    return v;
}
```



```c++
void bfs(int st) {
    vector<int> vis(N, 0);
    queue<int> q;
    q.push(st);
    vis[st] = 1; //标记已经访问过的
    while (!q.empty()) {
        int u = q.front();
        q.pop(); //访问后移除
        for (int v : adj[u]) {
            if (vis[v])
                continue;
            q.push(v); //将以u为节点的子节点存入队列，继续遍历
            vis[v] = 1; //标记
        }
    }
}
```



### dijkstra

标准模板

```c++
#include <bits/stdc++.h>
using namespace std;

// 使用 long long 防止路径总和爆 int
using ll = long long;

// 定义无穷大，注意不要用 INT_MAX，防止相加溢出
const ll INF = 0x3f3f3f3f3f3f3f3f; 
// 或者直接 const ll INF = 1e18;

const int N = 100005; // 根据题目最大节点数修改
const int M = 200005; // 根据题目最大边数修改

// 邻接表存图：vector<pair<目标点, 权值>>
struct Edge {
    int to;
    ll w;
};
vector<Edge> adj[N];

// dist[i] 存储起点到 i 的最短距离
ll dist[N];

// 标记数组（可选，但在堆优化中用于剪枝）
// bool vis[N]; 

// n: 节点数, s: 起点
void dijkstra(int n, int s) {
    // 1. 初始化距离为无穷大
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        // vis[i] = false;
    }
    
    // 2. 起点距离设为 0
    dist[s] = 0;

    // 3. 优先队列（小根堆）：存储 {当前距离, 节点编号}
    // greater 让 pair 按照 first 从小到大排序
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    // 把起点放入队列
    pq.push({0, s});

    while (!pq.empty()) {
        // 取出当前距离最小的点
        auto [d, u] = pq.top();
        pq.pop();

        // 【关键剪枝】：懒惰删除
        // 如果当前取出的距离 d 大于已经更新过的最短距离 dist[u]，
        // 说明这个节点是旧的、无效的信息，直接跳过。
        if (d > dist[u]) continue;
        
        // 如果需要 vis 数组：
        // if (vis[u]) continue;
        // vis[u] = true;

        // 遍历 u 的所有邻居
        for (auto& edge : adj[u]) {
            int v = edge.to;
            ll w = edge.w;

            // 【松弛操作】：如果经由 u 到 v 更近
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v}); // 将更新后的 v 放入队列
            }
        }
    }
}

int main() {
    // 加速 I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;
    // 输入：节点数，边数，起点
    cin >> n >> m >> s;

    // 建图
    for (int i = 0; i < m; i++) {
        int u, v; 
        ll w;
        cin >> u >> v >> w;
        // 有向图
        adj[u].push_back({v, w});
        
        // 如果是无向图，加上下面这句：
        // adj[v].push_back({u, w});
    }

    // 运行算法
    dijkstra(n, s);

    // 输出结果
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << " "; // 无法到达
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```



### 并查集

专门用来处理一些**不相交集合的合并与查询**问题

```c++
/**
 * 并查集 (DSU) 模板
 * 包含：路径压缩 + 按大小合并
 * 复杂度：O(alpha(n)) ≈ O(1)
 */
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
```



## 3.7 数学

### 3.7.1 快速幂

快速幂是求解 的问题，其中a,b限定为整。如求3的 1e18 次方，直接递推肯定超时。

原理：如求3的8次方，我们可以先算3的2次，再2次乘2次，到3的4次，4次乘4次，到3的8次

```c++
#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << qpow(a, b) << endl;
    return 0;
}
```



### 3.7.2 矩阵快速幂

问题：快速求解n*n的矩阵A，求$A^b$

```c++
#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
vector<vector<ll>> mul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) // 矩阵相乘
{
    ll n = a.size() - 1;
    vector<vector<ll>> res(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod + mod) % mod;
            }
        }
    }
    return res;
}
vector<vector<ll>> qpow(vector<vector<ll>> a, ll b) // 矩阵快速幂
{
    ll n = a.size() - 1;
    vector<vector<ll>> res(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        res[i][i] = 1;
    while (b)
    {
        if (b % 2)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int main()
{
    ll n, b;
    cin >> n >> b; // 矩阵阶数n,次数b.
    vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> res = qpow(a, b);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```



### 3.7.3 高精度

1. 加法高精度

```c++
//计算 123456789 + 987654321
/*
高精度的加法思想
1.把大数存到字符串; 
    2.字符串的每个字符数字都通过ASCII转换存到数组,
    注意的是要低位存在数组开头:a[i] = s[len-i-1]-'0';
    
    3.获取最大的数长度:max(len1,len2) ;
    4.把a,b值加入到c数组： c[i] = a[i]+b[i]; 
    
    5.c数组加法进位的算式:
    ①  c[i+1] += c[i]/10; 
    ②  c[i] %= 10;
    
    6.数字溢出，长度+1;
    7.反向输出结果;
*/
#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int a[10000],b[10000],c[100001];
int main(){
//  1.输入值，长度 
    cin>>s1>>s2;  
    int len1 = s1.size();
    int len2 = s2.size(); 
//  2.把字符转为整数存到数组
//  注意要个位存到数组开头 
    for(int i=0;i<len1;i++){
        a[i] = s1[len1-i-1]-'0';
    } 
    for(int i=0;i<len2;i++){
        b[i] = s2[len2-i-1]-'0';
    }
//  3.获取最大的数。 
    int len = max(len1,len2);
    // 对各个位数进行相加 
    for(int i=0;i<len;i++){
        c[i]=a[i]+b[i];
    }
    //4.进位
    for(int i=0;i<len;i++){
        c[i+1] += c[i]/10;
        c[i] %= 10; 
    }
    //5.溢出
    while(c[len]==0 && len>0){
        len--;
    } 
    if(c[len]>0){
        len++;
    } 
    //6.反向输出 
    for(int i=len-1;i>=0;i--){
        cout<<c[i];
    }
    return 0;
} 
```



2. 高精度减法

```c++
// 辅助函数：判断 s1 是否小于 s2
bool isSmaller(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    return s1 < s2; // 长度相同时直接用字典序比较
}

ll solve(string s1, string s2) {
    // 1. 修复比较逻辑，不用 stoi
    if (isSmaller(s1, s2)) {
        swap(s1, s2);
    }
    
    // 2. 修复数组初始化，使用 vector 自动初始化为 0，防止垃圾值
    // 开大一点防止溢出
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int> a(len1, 0); 
    vector<int> b(len1, 0); // 让 b 的大小和 a 一样，方便减法，不足补0
    vector<int> c(len1, 0);

    for (int i = 0; i < len1; i++) a[i] = s1[len1 - i - 1] - '0';
    for (int i = 0; i < len2; i++) b[i] = s2[len2 - i - 1] - '0';

    // 减法逻辑
    for (int i = 0; i < len1; i++) {
        if (a[i] < b[i]) {
            a[i + 1]--;
            a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }

    // 去除前导零
    int real_len = len1;
    while (real_len > 1 && c[real_len - 1] == 0) {
        real_len--;
    }

    // 3. 修复返回值：直接在计算过程中取模，而不是转成 stoi
    // 结果现在存在 c[0]...c[real_len-1] 中，c[0] 是个位
    ll num = 0;
    // 从高位到低位还原数值并取模（秦九韶算法）
    for (int i = real_len - 1; i >= 0; i--) {
        num = (num * 10 + c[i]) % MOD;
    }
    
    return num;
}
```



3. 高精度乘法

```c++
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 40500; // 最大长度
int a[MAXN], b[MAXN], c[MAXN];
int main() {
   string s1, s2;
   cin >> s1 >> s2;
   int n = s1.length(), m = s2.length(), len = n + m;
   // 逆序存储
   for (int i = 0; i < n; i++) a[n - i] = s1[i] - '0';
   for (int i = 0; i < m; i++) b[m - i] = s2[i] - '0';
   // 累加乘积
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= m; j++) {
           c[i + j - 1] += a[i] * b[j];
       }
   }
   // 处理进位
   for (int i = 1; i < len; i++) {
       if (c[i] >= 10) {
           c[i + 1] += c[i] / 10;
           c[i] %= 10;
       }
   }
   // 删除前导零并输出
   while (len > 1 && c[len] == 0) len--;
   for (int i = len; i > 0; i--) cout << c[i];
   return 0;
}
```



### 3.7.4离散化

1. **离散化差分**（Discretized Difference Array）是解决**“大范围坐标、少操作次数”**区间问题的核心算法。

简单来说，就是当题目中告诉你坐标范围是 $1≤x≤10^9$，但操作次数只有**N** 只有$10^5$时，因为内存和时间限制，你不能开一个 $10^9$大小的数组。此时，我们需要把**用不到的中间空白坐标压缩掉**，或者**只存储有变化的坐标点**。

------



**核心思想**：
数轴是连续的，但数值的变化是**离散**的。
只有在区间的**起点**和**终点**，覆盖层数才会发生突变。在两个相邻的“关键点”之间，覆盖层数是恒定的。

因此，我们只需要记录这些**关键点（变化点）**，然后计算两个关键点之间的距离乘以当前的层数，就是这段区间的贡献。

------

```c++
map<ll, int> diff;
// 1. 读入并差分
for(int i=0; i<n; i++) {
    cin >> l >> r;
    diff[l]++;
    diff[r+1]--; // 注意这里通常是 r+1，代表左闭右闭区间 [l, r]
}

// 2. 扫描线统计
ll ans = 0, sum = 0, pre = -1;
for(auto& [pos, val] : diff) {
    // 第一次循环只记录起点，不计算
    if(pre != -1) {
        // 计算上一段 [pre, pos) 的长度
        ll len = pos - pre;
        // 根据 sum (层数) 判断是否计入答案
        if(sum > 0) ans += len; 
    }
    sum += val; // 更新层数
    pre = pos;  // 更新上一个点
}
```



### 3.7.5 欧拉筛

```C++
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll maxn = 1e6;
vector<ll> prime;  //存储已经找到的所有素数（相当于 “素数字典”）；
vector<ll> phi(maxn + 1, 1); //存储每个数的欧拉函数值(顺带计算)
vector<bool> vis(maxn + 1, 0);  //标记某个数是否为合数（false= 素数，true = 合数）
void init()
{
    phi[1] = 1;
    vis[1] = 1;// 1既不是质数也不是合数，但在筛法中标记为1避免重复处理
    for (ll i = 2; i <= maxn; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size(); ++j)
        {
            ll p = prime[j];
            if (p * i > maxn)
                break;
            vis[p * i] = true;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            else
            {
                phi[i * p] = phi[i] * phi[p];
            }
        }
    }
}
int main()
{
    init();
    for (int i = 1; i <= 10; i++)
    {
        cout << phi[i] << endl;
    }
    return 0;
}
```



### 3.7.6 逆元 取模 最大公约数(gcd) 最小公倍数(lcm) 

取模最主要的是要注意步步取模，避免爆值，例如

- **加法**: `(a+b) % MOD`
- **乘法**:`(a * b) % MOD`
- **减法**:`(a - b + MOD) % MOD`(注意减法要先加上模数后再取模，避免出现负值取模)
- **除法**:除法不能直接取模，需要求模逆元；除以一个数 b 等于乘以 b 的模逆元

​          $\frac{a}{b}(mod\;P) \equiv a * b^{P-2}(mod\;P)$  可以用快速幂计算`qpow(b,MOD-2)`(模数得是质数才成立，但一般题目给出的都是质数)



#### 1到1e6模1e9+7的逆元模板

```c++
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll maxn = 1e6;
vector<ll> inv(maxn + 1, 1);
void init()
{
    for (int i = 2; i <= maxn; ++i)
    {
        inv[i] = (mod - mod / i * inv[mod % i] % mod) % mod;
    }
}
int main()
{
    init();
    for (int i = 1; i <= 10; ++i)
    {
        cout << inv[i] << endl;
    }
    return 0;
}
```



```c++
ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b; // 先除后乘，尽量不溢
}
```



### 3.7.7排列数和组合数

```c++
vector<ll> fact(n+1),inv(n+1);//阶乘和逆元

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void init(){
    fact[0] = 1;
    for(int i = 1;i<=n;i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv[n] = qpow(fact[n],MOD-2);
    for(int i = n - 1;i>=0;i--){
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
}

ll C(ll n,ll k){//n中选k
    if(k<0 || k>n) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

ll A(ll n,llk){
    if(k<0 || k>n) return 0;
    return fact[n] * inv[n-k] %
}
```



###小点

```c++
ceil(x)//取第一个不小于x的整数 <cmath>
```

```c++
//加速
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

// 2. 去重 unique 会将重复的元素移到末尾，返回去重后最后一个有效元素的下一个位置的迭代器
auto last = unique(a.begin(),a.end());
a.erase(last,a.end()); //配合vector::erase s
a.erase(unique(a.begin(), a.end()), a.end()); /


//用endl再极端情况下可能会TLE,建议直接使用'\n'   
//或者直接 #define endl '\'
    
//row+i 表示同一副对角线
//row-i 表示同一主对角线  因为会出现负值，所以我们通常会加一个常数，
   //row-i+n


//整数向上取整可以 (a+b-1)/b

对于矩阵中的任意2*2子块，想要其合为合数，只需顺序填入值
```

i $\equiv$j(modx) 意味着i和j关于x同余，那么集合可表示为{${1+x,1+2x,....,1+kx}$}



0-base 下$[L,R]$的和用前缀和表示为 `pre[R+1] - pre[L]`

1-base下$[L,R]$的和用前缀和表示为`pre[R] - pre[L-1]`
