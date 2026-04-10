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
        while((!dq.empty()) && a[dq.back()] <= a[i]) 		           			dq.pop_back();
        dq.push_back(i);
        if(dq.front() == i - k){
            dq.pop_front();//移除过期数据
        }
        if(i>=k)
            cout << a[dq.front()] <<" ";//输出窗口每次移动的最大值
    }//输出长度为k窗口下的最大值
```



## 子数组最大 / 最小

```c++
ll cur = -1e18;
ll ans = -1e18;
for(int i = 1;i<=n;i++){
	cur = max(a[i],cur+a[i]);
    ans = max(ans,cur);
}
cout<<ans<<endl; //最大

ll cur = 0;
ll ans = 0;
for(int i = 1;i<=n;i++){
    cur = min(a[i],cur+a[i]);
    ans = min(ans,cur);
}
cout<<ans<<endl; //最小
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
        while ((!st.empty()) && a[st.top()] < a[i]) //单调递减的单调栈
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



### 3.5.4 LCS && LIS

#### 最长公共子序列(LCS)

```c++
int dp[5010][3010];
string s, t;
cin >> s >> t;
    
for (int i = 1; i <= s.length(); i++)
{
    for (int j = 1; j <= t.length(); j++)
    {
        if (s[i-1] == t[j-1])
        {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
cout<<dp[s.length()][t.length()]; //输出最长公共子序列长度

//反向追踪出最长的公共子序列
string res = "";
int i = s.length(),j = t.length();
while(i>0 && j>0){
    if(s[i - 1] == t[j-1] ){
        res+=s[i-1];
        i--,j--;
    }else{
        if(dp[i-1][j] >= dp[i][j-1]) i--;
        else j--;
    }
}
cout<<res;

```





#### 最长上升子序列(LIS)

设计$dp_i$为以$a_i$为结尾的最长上升子序列，计算时，尝试将$a_i$接到之前的最长不下降子序列后面

```c++
dp[1] = 1;
ll ans = 1;
for(int i = 2;i<=n;i++){
    dp[i] = 1;
    for(int j = 1;j<i;j++){
        if(a[j]<a[i]){
            dp[i] = max(dp[i],dp[j]+1);
            ans = max(ans,1LL*dp[i]);
        }
    }
}
cout<<ans;
```

$n^2$的算法如果对$1e5$及以上的数据来说有点慢，我们可以进行优化，可优化为$O(n\,logn)$,如下

```c++
vector<int> low(n + 1, 0);
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > low[len])
        {
            len++;
            low[len] = b[i];
        }
        else
        {
            int idx = lower_bound(low.begin()+1, low.begin()+len+1, b[i]) - low.begin();
            low[idx] = b[i];
        }
    }

    cout << len;
```

**解释**: $low_i$表示长度为 i 的最长上升子序列；我们从1开始遍历到n，如果遇到当前数组的数值大于low中最后的元素，我们就可以把当前的数值接到后面；如果遇到严格小于low中最后的元素，我们就可以将其替换到第一个大于他的位置上，可以证明，这是更优的，因为如果后面的值越小，就更容易接上更多的值



求 **LCS ** 的问题部分也可转化为求 **LIS** 的问题，例如，如果对应两个数组中的元素范围相同且每个数只出现一次，我们就可以把其中一个数组当作基准来调整另一个数组中的元素；

更具体的说，如果现在给你两个数组a，b，他们都是n的排列，让你求出a和b的最长公共子序列，我们就可以以a为基准，对b进行映射，那么问题就**等价**于对映射后的b求最长上升子序列

如下

```c++
 int n;
    cin >> n;
    vector<int> pos(n+1,0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        pos[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = pos[b[i]];
    }

    vector<int> low(n + 1, 0);
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > low[len])
        {
            len++;
            low[len] = b[i];
        }
        else
        {
            int idx = lower_bound(low.begin()+1, low.begin()+len+1, b[i]) - low.begin();
            low[idx] = b[i];
        }
    }

    cout << len;

```

### 进制转换

#### 十进制转2-16进制

```c++
int n;
string s;
int x;
char c;
for(int i = 2;i<=16;i++){
     int nu = n;
	 while(nu){
         x = nu%i;
         if(x<10){
             c = x+'0';
         }else{
             c = x+'A'-10;
         }
         nu/=i;
         s = s +c;
     }
    cout<<s<<endl;
}
```



## 3.6 搜索 && 数据结构

```c++
//lambda表达式：
auto dfs = [&](auto &&self,int u,int fa) -> void{
  	....
   	//调用时
    self(self,v,u);
    return;
};
//第一次调用
dfs(dfs,1)


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

 

### 最短路

#### dijkstra(处理非负权边的最短路)

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



#### 全源最短路(处理含负权边) (SPFA)

- 核心思想：首先创建一个虚拟超级 $0$ 节点，向所有节点连一条权值为 $0$ 的边,跑一次 $SPFA$ 求出势能函数后，利用他把所有边转换成非负权边，接着按照题意把需要求的最短路用 $dijkstra$ 求出即可

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18; // 设置一个足够大的无穷大值，防止累加时溢出

// 边的结构体
struct node {
    ll to; // 目标节点
    ll w;  // 边权
};

int main() {
    // ---------------------------------------------------------
    // 0. 基础设置与建图
    // ---------------------------------------------------------
    ios::sync_with_stdio(0); // 优化 C++ 输入输出流，防止大数据读写超时
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    
    // 使用 vector 的 vector，兼容所有 C++ 标准，避免 VLA (变长数组) 报错
    vector<vector<node>> adj(n + 1);

    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // 构建有向图
    }

    // ---------------------------------------------------------
    // 1. SPFA 求势能数组 h (隐式建立虚拟节点 0)
    // ---------------------------------------------------------
    vector<ll> cnt(n + 1, 0);     // cnt[i] 记录节点 i 入队的次数，用于判负环
    vector<bool> vis(n + 1, false); // vis[i] 表示节点 i 当前是否在队列中 (SPFA核心)
    
    //h 初始必须为 0！等价于虚拟节点 0 到各点的距离为 0
    vector<ll> h(n + 1, 0);       
    queue<ll> q;

    // 隐式从虚拟源点出发：将所有真实节点压入队列，初始距离(势能)全为 0
    for (int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true; // 标记已在队列中
        cnt[i] = 1;    // 相当于所有点已经入队 1 次
    }

    // SPFA 主循环
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vis[u] = false; // 节点出队，取消标记

        for (auto &edge : adj[u]) {
            ll v = edge.to;
            ll w = edge.w;

            // 松弛操作
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                
                // 只有当 v 不在队列中时，才需要将其入队
                if (!vis[v]) {
                    vis[v] = true;
                    cnt[v]++; // 记录入队次数
                    
                    // 如果某个点入队次数超过图的总节点数 n，说明在无限绕负权环
                    if (cnt[v] > n) {
                        cout << -1 << endl;
                        return 0; // 发现负环，直接结束程序
                    }
                    
                    //q.push 必须放在 if(!vis[v]) 内部！防止重复无意义入队
                    q.push(v);
                }
            }
        }
    }
    
    //将所有边转换为非负
    for(int i = 1;i<=n;i++){
        for(auto &edge : adj[i]){
            edge.w = edge.w + h[i] - h[edge.to];
        }
    }

    //后面根据题目进行dijkstra即可，注意最后要对边权进行还原
    //真实 w = dist[j] + h[j] - h[i]
    
    return 0;
}
```



#### 分册图+回溯寻找路径

[P1266 [BalticOI 2002\] 速度限制 - 洛谷](https://www.luogu.com.cn/problem/P1266)

1. 分册图

   - **分层图最短路**，本质上是**图论与动态规划（DP）的结合**（所以也常被称为“状态机最短路”）。
- 因为到达某一个节点时会因为上一个节点的结果不同而可能导致当前节点的结果不同，那么这种情况下我们需要对 $dist$ 数组进行升维，二维或者三维，根据题目限制条件而定
   - 一般题目带有**"状态/油量/速度/免费次数/打折券”**等带有限制性条件时，一般都需要分层图

2. 回溯找最短路对应的节点

   - 可根据 $dist$ 创建对应数量和维度的 $pre$ 数组，用来存放谁更新了当前最优的状态，最后倒序查找即可

```c++
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

struct Node{
    int to;
    int l;
    int v;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    vector<Node> adj[n];
    for(int i = 1;i<=m;i++){
        int u,v,s,l;
        cin>>u>>v>>s>>l;
        adj[u].push_back({v,l,s});
    }

    //本题的边权，也就是时间并非固定不变，所有需要再开一维来进行表示，dist[u][se]表示到达u节点且速度为se时的最短路径
    vector<vector<double>> dist(n,vector<double>(505,INF));
    priority_queue<tuple<double,ll,ll>,vector<tuple<double,ll,ll>>,greater<tuple<double,ll,ll>>> pq;
    vector<vector<int>> pre_pos(n,vector<int>(505,-1));//表示到达对应状态的上一个路口
    vector<vector<int>> pre_sp(n,vector<int>(505,-1));//表示到达对应状态的上一个速度
    pq.push({0.0,70,0});
    dist[0][70] = 0;

    while(!pq.empty()){
        auto [t,se,u] = pq.top();
        pq.pop();

        if(t>dist[u][se]) continue;

        for(auto &edge : adj[u]){
            int v = edge.to;
            int l = edge.l;
            int se1 = edge.v;
            double t1 = 0.0;
           
            if(se1 == 0){
                t1 = (double)l / se;
                se1 = se;
            }else{
                t1 = (double)l / se1;
            }
            
            if(dist[v][se1]>dist[u][se]+t1){
                dist[v][se1] = dist[u][se] + t1;
                pq.push({dist[v][se1],se1,v});
                pre_pos[v][se1] = u;
                pre_sp[v][se1] = se;
            }
        }
    }

    double minn = INF;
    vector<int> ans;
    int sp = -1;
    for(int i = 0;i<=500;i++){
        if(minn>dist[d][i]){
            minn = dist[d][i];
            sp = i;
        }
    }

    int cur_u = d;
    int cur_sp = sp;

    while(cur_u != -1){
        ans.push_back(cur_u);

        int next_u = pre_pos[cur_u][cur_sp];
        int next_sp = pre_sp[cur_u][cur_sp];

        cur_u = next_u;
        cur_sp = next_sp;
    }
    reverse(ans.begin(),ans.end());

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
```



#### Floyd

该算法可求任意两点的之间的最短长度，但复杂度过高，一般只在n较小的情况下使用或优化

```c++
for (k = 1; k <= n; k++) {
  for (x = 1; x <= n; x++) {
    for (y = 1; y <= n; y++) {
      f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
    }
  }
}//f[x][y]表示x到y的最短路程
```



#### 处理任意k个点中任意两点间的最短路

```c++
void solve()
{
    int n, m;
    cin >> n >> m;
    
    // 使用 pair 存储图：{目标节点 v, 边权 w}
    vector<vector<pair<int, ll>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // 无向图，双向建边
    }

    int k;
    cin >> k;
    
    // dist 记录某个节点距离离它最近的特殊点的距离
    vector<ll> dist(n + 1, INF);
    // color 记录离该节点最近的特殊点是哪一个（即势力的 ID）
    vector<int> color(n + 1, 0); 
    
    // priority_queue 存储：{距离, 当前节点ID}，默认大根堆，用 greater 变成小根堆
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // 将所有特殊点作为多源 BFS/Dijkstra 的起点同时入队
    for(int i = 0; i < k; i++){
        int start_node;
        cin >> start_node;
        dist[start_node] = 0;
        color[start_node] = start_node; // 自己染自己的色
        pq.push({0, start_node});
    }

    ll ans = INF;

    // 开始多源 Dijkstra 扩张
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        // 剪枝：如果当前取出的距离不是最优的，直接跳过
        if(d > dist[u]) continue;

        for(auto &edge : adj[u]){
            ll v = edge.first;
            ll w = edge.second;

            // 状态 1：目标节点 v 还是无主之地（没被染色）
            if(color[v] == 0){
                color[v] = color[u]; // 插上和 u 一样的旗帜
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
            // 状态 2：目标节点 v 已经被别的势力占领了！两军相遇！
            else if(color[v] != color[u]){
                // 不入队，直接用相遇距离更新全局最小答案
                ans = min(ans, dist[u] + dist[v] + w);
            }
            // 状态 3：目标节点 v 已经是自己势力的地盘了，看看能不能找到更短的巡逻路线
            else if(color[v] == color[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << ans << "\n";
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
    ll count;            // 记录连通分量的数量

    // 初始化：n 为节点数量
    DSU(ll n) : parent(n + 1), siz(n + 1, 1), count(n) {
        // 初始时每个节点的父节点是自己
        std::iota(parent.begin(), parent.end(), 0); 
    }

    // 查找 (Find) - 路径压缩
    ll find(ll x) {
        // 如果 x 不是根节点，递归找根，并进行路径压缩
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // 合并 (Union) - 按大小合并
    // 返回值：true 表示合并成功（原本不在一组），false 表示原本就在一组
    bool merge(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);

        if (rootX == rootY) return false; // 已经在同一个集合

        // 启发式合并：把小的集合合并到大的集合上，保持树的高度较低
        if (siz[rootX] < siz[rootY]) std::swap(rootX, rootY);
        
        parent[rootY] = rootX; // Y 挂到 X 上
        siz[rootX] += siz[rootY]; // 更新 X 的大小
        count--; // 连通分量减少一个
        return true;
    }

    // 判断是否连通
    bool connected(ll x, ll y) {
        return find(x) == find(y);
    }

    // 获取某个节点所在集合的大小
    int getSize(ll x) {
        return siz[find(x)];
    }
};
```



### 树状数组

树状数组是一种支持 **单点修改** 和 **区间查询** 的，代码量小的数据结构．

树状数组利用数的**二进制特征**来定义“管辖范围”,即一个数的二进制的最后一位 `1` 以及其后所有的`0`所构成的二进制大小，就是该数所管辖的区间范围。例如 `8` 的二进制为 `1000`，那么`a[8]` 所管辖的范围就是`1-8`这个区间，再例如 `7`，`a[7]`所管辖的范围就只有`7`

lowbit(x) 用于提取 x 在二进制表示下最低位的 1 及其后面的 0 构成的数值。

```c++
struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    ll lowbit(int x){
        return x & (-x);
    }
    
    // 在位置 i 增加 delta
    void add(int i, ll delta) {
        for (; i <= n; i += lowbit(i)) {
            tree[i] = tree[i] + delta;
        }
    }
    
    // 查询 1 到 i 的区间和
    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= lowbit(i)) {
            sum = sum + tree[i];
        }
        return sum;
    }
    
    // 查询 l 到 r 的区间和
    ll query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

```



### 线段树

#### 区间修改+区间查询

```c++
ll arr[MAXN];      // 原数组
ll tree[MAXN * 4]; // 线段树数组
ll tag[MAXN * 4];  // 懒标记(加)
vector<ll> tag1(MAXN*4,1); // 懒标记(乘)

// 向上更新 (Push Up): 用子节点算父节点
void push_up(ll p) {
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}

// 向下下放 (Push Down)，每当要访问数据的时候都要下放
// p: 当前节点, len: 当前节点管辖的区间长度
void push_down(ll p, ll len) {
    //如果存在修改乘上某值，需要先对乘法的标记进行下放
    if(tag1[p] != 1){
        tag1[p<<1] *= tag1[p];
        tag1[p<<1 | 1] *= tag1[p];
        
        //需要对加法的标记进行倍增
        tag[p<<1] *= tag1[p];
        tag[p<<1 | 1] *= tag1[p];
        
        tree[p<<1] *= tag1[p];
        tree[p<<1 | 1] *= tag1[p];
        
        tag1[p] = 1;
    }
    if (tag[p]) {
        // 1. 传给左子 (p<<1) 和 右子 (p<<1|1)
        tag[p << 1] += tag[p];
        tag[p << 1 | 1] += tag[p];
        
        // 2. 更新子节点的值 (增量 = tag * 区间长度)
        tree[p << 1] += tag[p] * (len - len / 2);
        tree[p << 1 | 1] += tag[p] * (len / 2);
        
        // 3. 清除当前标记
        tag[p] = 0;
    }
}

// 建树
void build(ll p, ll l, ll r) {
    tag[p] = 0;
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

// 区间修改: [ql, qr] 范围全加 k
void update(ll p, ll l, ll r, ll ql, ll qr, ll k) {
    // 1. 完全覆盖，直接更新并打标，不递归
    if (ql <= l && r <= qr) {
        tree[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    
    // 2. 未完全覆盖，先下放标记，再递归
    push_down(p, r - l + 1);
    ll mid = (l + r) >> 1;
    if (ql <= mid) update(p << 1, l, mid, ql, qr, k);
    if (qr > mid) update(p << 1 | 1, mid + 1, r, ql, qr, k);
    push_up(p);
}

void update1(ll p,ll l,ll r,ll ql,ll qr,ll k){
    if(ql <= l && r<=qr){
        tree[p] *= k;
        tag1[p] *= k;
        tag[p] *= k;
        return;
    }
    
    push_down(p,r-l+1);
    ll mid = (l+r)>>1;
    if(ql <= mid) update(p<<1,l,mid,ql,qr,k);
    if(qr>mid) update(p<<1 | 1,mid+1,r,ql,qr,k);
    push_up(p);
}

// 区间查询: 求 [ql, qr] 的和
ll query(ll p, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) return tree[p];
    
    push_down(p, r - l + 1); // 查之前也要下放
    ll mid = (l + r) >> 1;
    ll res = 0;
    if (ql <= mid) res += query(p << 1, l, mid, ql, qr);
    if (qr > mid) res += query(p << 1 | 1, mid + 1, r, ql, qr);
    return res;
}
```



## 3.7 数学

### 一些定理？以及一些遇到的数学技巧

#### 唯一分解定理

是指大于1的正整数n，都可以唯一地表示为有限个素数的乘积

$n = p_1^{a_1} \times p_2^{a_2} \times ... \times p_n^{a_n}$



#### 叉积求三角形面积

1. 利用向量的叉积

<img src="D:\mouse\Pictures\screenshots\屏幕截图 2026-02-08 014012.png" alt="屏幕截图 2026-02-08 014012" style="zoom:50%;" />

2. 推广

<img src="D:\mouse\Pictures\screenshots\屏幕截图 2026-02-08 014258.png" alt="屏幕截图 2026-02-08 014258" style="zoom:50%;" />



### 枚举因数

```c++
vector<ll> a;
for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
        a.push_back(i);       // 存入较小的因数
        if(i * i != n){
            a.push_back(n / i); // 存入对应的较大的因数（注意是 n / i，绝对不能写 n /= i）
        }
    }
}
```



### 分解质因数

```c++
vector<ll> primes;
// 质因数分解，i 从 2 开始
for(ll i = 2; i * i <= n; i++){
    // 只要能整除，就一直除，直到除不尽为止
    while(n % i == 0){
        primes.push_back(i);
        n /= i; // 这里修改 n 是必须的！因为我们要把因子剔除干净
    }
}
// 如果最后 n 没被除到 1，说明剩下一个大于 sqrt(原始n) 的质数
if(n > 1){
    primes.push_back(n);
}
```



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
        if (b & 1)
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



### 1到1e6模1e9+7的逆元模板

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



## 3.7.7排列数和组合数

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
    return fact[n] * inv[n-k] % MOD;
}
```



#3.8 位运算

```c++
__builtin_ctz(x) //获取x二进制后缀0的长度
__builtin_clz(x) //获取x二进制前缀0的长度  //二者皆为接受int类型，接受ll需要后面加ll //_
```



## 1. 线性基

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct LinearBasis {
    ll d[64];       // 存储线性基的数组，d[i] 表示最高位为第 i 位的基向量
    bool has_zero;  // 记录原序列中是否能异或出 0（即是否存在线性相关的元素）

    // 构造函数，初始化
    LinearBasis() {
        memset(d, 0, sizeof(d));
        has_zero = false;
    }

    // 1. 插入一个元素 x
    void insert(ll x) {
        for (int i = 62; i >= 0; i--) { // 从最高位向下枚举（long long 最大 62 位）
            if ((x >> i) & 1) {         // 如果 x 的第 i 位是 1
                if (!d[i]) {            // 如果这一位还没有基向量
                    d[i] = x;           // x 成为这一位的基向量
                    return;             // 插入成功，立刻退出
                }
                x ^= d[i];              // 如果这一位已经被占了，就用 d[i] 把 x 的第 i 位消成 0
            }
        }
        // 如果 x 被消成了 0，说明 x 可以由之前的基向量异或得到（线性相关）
        has_zero = true; 
    }

    // 2. 查询原数组能异或出的最大值
    ll query_max() {
        ll res = 0;
        for (int i = 62; i >= 0; i--) {
            // 贪心策略：如果异或上 d[i] 能让结果变大，就异或它
            if ((res ^ d[i]) > res) {
                res ^= d[i];
            }
        }
        return res;
    }

    // 3. 判断 x 能否由原数组的元素异或得到
    bool check(ll x) {
        for (int i = 62; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!d[i]) return false; // x 在第 i 位是 1，但线性基没有这一位的基，无法消去
                x ^= d[i];               // 消去第 i 位
            }
        }
        return x == 0; // 如果 x 最终被消成 0，说明它可以由线性基表出
    }
};
```



# 3.9 dp

## 1 树上dp

### 一、 树形 DP 的本质是什么？

树形 DP 的本质是：**利用树的“天然递归结构”，将大问题拆解为子树的小问题。**

在一棵无根树中，只要我们人为规定一个节点为根（通常是 1 号点），它就变成了一棵有向的、层级分明的树。

- **无后效性**：一旦子树 v 的状态算好了，它内部怎么组合的就不再重要了，只会作为一个整体的数值提供给父亲 。
- **最优子结构**：父亲 u 的最优解，一定可以由儿子 v 的最优解组合推导出来

**标准遍历方向：自底向上（后序遍历）**
即：先递归把所有儿子的 DP 值算出来 →然后合并给父亲。

### 1.1 染色问题

大致题意：给你一颗树，树上可染红蓝绿三种颜色，且相邻节点不能同色，若一个节点有两个子节点，这两个子节点也不能同色，问你其中一个颜色可染节点的最大数量是多少

一般的解法是树上dp

```c++
//dp[u][0] 表示u节点不染要求颜色，1则为染
auto dfs = [&](auto &&self,ll u,ll fa) -> void{
        ll sum = 0;//记录当前节点的子节点有多少已染对应颜色的点
        ll maxx = 0;
        for(auto v : adj[u]){
            if(v != fa){
                
                self(self,v,u);
                sum += dp[v][0]; 
                //求出若有一个子节点要染可产生的最大贡献
                maxx = max(maxx,dp[v][1] - dp[v][0]); 
            }   

        }
    	//处理完所有子节点后，进行向上转移
        dp[u][1] = 1 + sum; //如果u要染，则加上所有子节点不染所产生的最大贡献再加一
        dp[u][0] = sum + maxx;//如果u不染，则加上所有子节点不染产生的最大贡献后再加上若其中一个子节点

    };
    dfs(dfs,1,0);
    cout<<max(dp[1][1],dp[1][0])<<endl;
```



### 1.2 树形背包

**特征**：给了一定的总额度（体积），让你在树上分配，通常要求选儿子必须先选父亲。

**经典题目**：**P2014 [CTSC1997] 选课**、二叉苹果树。

**状态设计**：`dp[u][i]`表示以 u 为根的子树，分配了 i 个体积的最优解。

**转移方程**：嵌套循环，像极了分组背包。

```c++
// 在合并 v 到 u 时：
for(int j = M; j >= 0; j--) { // u 的总容量
    for(int k = 0; k < j; k++) { // 分给 v 的容量
        dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k]);
    }
}
```



### 1.3 换根dp

**特征**：题目不问你以 1 为根的答案，而是问你：**以** i**为根时答案是多少（要求输出所有 `i=1…Ni=1…N` 的答案）**。如果做 N次 DFS 会超时。

**经典题目**：STA-Station、Tree Distances。

**解法**：两遍 DFS。

- **第一遍 DFS（自底向上）**：随便选一个根（比如 1），求出每个节点的 dp[u]（仅考虑其子树内部的贡献）。

- **第二遍 DFS（自顶向下）**：开一个新数组 ans[u]。父亲 u把自己身上**除去 `v` 之外的其他部分**，当作一个巨大的“上面挂着的子树”，下放给 v。

  [P3478 [POI 2008\] STA-Station - 洛谷](https://www.luogu.com.cn/problem/P3478)

  题意：让你求出每个节点为根时的所有节点的深度之和

  ```c++
  void solve()
  {
      ll n;
      cin>>n;
      vector<vector<ll>> adj(n+1);
      for(int i= 1;i<=n-1;i++){
          ll u,v;
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
  
      vector<ll> dept(n+1,0);
      vector<ll> sz(n+1,0);
      vector<ll> p(n+1,0);
      auto dfs1 = [&](auto &&self,ll u,ll fa,ll d) ->void{
          dept[u] = d;
          sz[u] = 1;
          for(ll v : adj[u]){
              if(v != fa){
                  self(self,v,u,d+1);
                  sz[u]+=sz[v];
              }
          }
      };
      //第一次dfs求出所有节点的相对于1节点深度和子树大小
      dfs1(dfs1,1,0,1); 
  
      for(int i = 1;i<=n;i++){
          p[1]+=dept[i];
      }
      auto dfs2 = [&](auto &&self,ll u,ll fa) ->void{
          for(ll v : adj[u]){
              if(v != fa){
                  p[v] = p[u] - sz[v] + n - sz[v];
                  self(self,v,u);
              }
          }
      };
      //第二次求答案，思考容易得出从u转移到v的方程
      dfs2(dfs2,1,0);
  
      ll ans = -1;
      ll id = -1;
      for(int i = 1;i<=n;i++){
          if(p[i]>ans){
              ans = p[i];
              id = i;
          }
      }
      cout<<id<<endl;
  }   
  ```




## 2.基础dp



### 最长公共子序列(LCS)

```c++
int dp[5010][3010];
string s, t;
cin >> s >> t;
    
for (int i = 1; i <= s.length(); i++)
{
    for (int j = 1; j <= t.length(); j++)
    {
        if (s[i-1] == t[j-1])
        {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
cout<<dp[s.length()][t.length()]; //输出最长公共子序列长度

//反向追踪出最长的公共子序列
string res = "";
int i = s.length(),j = t.length();
while(i>0 && j>0){
    if(s[i - 1] == t[j-1] ){
        res+=s[i-1];
        i--,j--;
    }else{
        if(dp[i-1][j] >= dp[i][j-1]) i--;
        else j--;
    }
}
cout<<res;

```





### 最长上升子序列(LIS)

设计$dp_i$为以$a_i$为结尾的最长上升子序列，计算时，尝试将$a_i$接到之前的最长不下降子序列后面

```c++
dp[1] = 1;
ll ans = 1;
for(int i = 2;i<=n;i++){
    dp[i] = 1;
    for(int j = 1;j<i;j++){
        if(a[j]<a[i]){
            dp[i] = max(dp[i],dp[j]+1);
            ans = max(ans,1LL*dp[i]);
        }
    }
}
cout<<ans;
```

$n^2$的算法如果对$1e5$及以上的数据来说有点慢，我们可以进行优化，可优化为$O(n\,logn)$,如下

```c++
vector<int> low(n + 1, 0);
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > low[len])
        {
            len++;
            low[len] = b[i];
        }
        else
        {
            int idx = lower_bound(low.begin()+1, low.begin()+len+1, b[i]) - low.begin();
            low[idx] = b[i];
        }
    }

    cout << len;
```

**解释**: $low_i$表示长度为 i 的最长上升子序列；我们从1开始遍历到n，如果遇到当前数组的数值大于low中最后的元素，我们就可以把当前的数值接到后面；如果遇到严格小于low中最后的元素，我们就可以将其替换到第一个大于他的位置上，可以证明，这是更优的，因为如果后面的值越小，就更容易接上更多的值



求 **LCS ** 的问题部分也可转化为求 **LIS** 的问题，例如，如果对应两个数组中的元素范围相同且每个数只出现一次，我们就可以把其中一个数组当作基准来调整另一个数组中的元素；

更具体的说，如果现在给你两个数组a，b，他们都是n的排列，让你求出a和b的最长公共子序列，我们就可以以a为基准，对b进行映射，那么问题就**等价**于对映射后的b求最长上升子序列

如下

```c++
 int n;
    cin >> n;
    vector<int> pos(n+1,0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        pos[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = pos[b[i]];
    }

    vector<int> low(n + 1, 0);
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > low[len])
        {
            len++;
            low[len] = b[i];
        }
        else
        {
            int idx = lower_bound(low.begin()+1, low.begin()+len+1, b[i]) - low.begin();
            low[idx] = b[i];
        }
    }

    cout << len;

```



为什么正确？ 因为我们强行把a映射成了一个递增序列，将映射关系应用到b后；我们不难想到公共子序列的本质就是要求元素在两个数组中出现的相对顺序一致，那么由于这层映射关系，a单调递增了，那我们只用找出映射后的b中最长的单调递增序列即可；还可以知道，b中只要是单调递增的序列，那么这一段序列一定是a的一个合法子序列

# 4. 一些类型题的处理思路

### 4.1 存在大量插入，删除以及查询全局最小(大)值的

1. 方法一：使用**mulitset **
   - 适用场景：总操作次数(插入+删除)在 $10^5$ 级别，且时间为 2 秒可用
   - 插入：`ms.insert(x)`  , 删除一个元素：`ms.erase(ms.find(x))`  均为$O(log\;n)$
2. 方法二：双优先队列
   - 适用场景：极高频的插入和删除，且只关心最大值或最小值
   - 使用：定义两个最小堆的pq，一个存放所有插入的元素，一个存放所有删除的元素，查询时，如果两个堆顶的元素都相同，说明该值已被删除，对两个堆执行 $pop$ 操作,直到不相同为止，该次查询的值就是负责存放的堆的堆顶元素
3. 方法三：动态开点线段树



# 5. 优化技巧

## 线段树优化建图

如果遇到 **点到区间** 连边或 **区间到点** 连边，且总边数和总操作数都很大的时候，且需要跑**最短路**等算法的时候一般都会使用这种技巧

例：[Problem - B - Codeforces](https://codeforces.com/contest/786/problem/B)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>

const ll INF = 1e18;

struct Node{
    ll to;
    ll w;
};

void solve()
{
    ll n,q,s;
    cin>>n>>q>>s;
    vector<vector<Node>> adj(4*n);
    vector<ll> in(4*n,0); //入树，点到区间
    vector<ll> out(4*n,0); //出树，区间到点
    ll cnt = n; //虚拟节点编号需大于所有真实点

    //建树过程
    auto build = [&](auto &&self,ll p,ll l,ll r) -> void{
        if(l == r){
            in[p] = l;
            out[p] = l;
            return;
        }

        ll ls = p<<1;
        ll rs = p<<1 | 1;
        ll mid = (l+r)>>1;

        in[p] = ++cnt;
        out[p] = ++cnt;

        self(self,ls,l,mid);
        self(self,rs,mid+1,r);

        adj[in[p]].push_back({in[ls],0});
        adj[in[p]].push_back({in[rs],0});

        adj[out[ls]].push_back({out[p],0});
        adj[out[rs]].push_back({out[p],0});
    };

    //点到区间连边
    auto v_to_range = [&](auto &&self,ll p,ll v,ll w,ll l,ll r,ll ql,ll qr) ->void{
        if(ql<=l && r<=qr){
            adj[v].push_back({in[p],w});
            return;
        }

        ll ls = p << 1;
        ll rs = p << 1 | 1;
        ll mid = (l + r) >> 1;

        if(ql<=mid) self(self,ls,v,w,l,mid,ql,qr);
        if(qr>mid) self(self,rs,v,w,mid+1,r,ql,qr);
    };

    auto range_to_v = [&](auto &&self,ll p,ll v,ll w,ll l,ll r,ll ql,ll qr) -> void{
        if(ql<=l && r<=qr){
            adj[out[p]].push_back({v,w});
            return;
        }

        ll ls = p << 1;
        ll rs = p << 1 | 1;
        ll mid = (l + r) >> 1;

        if(ql<=mid) self(self,ls,v,w,l,mid,ql,qr);
        if(qr>mid) self(self,rs,v,w,mid+1,r,ql,qr);
    };

    build(build,1,1,n);
    
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll v,u,w;
            cin>>v>>u>>w;
            adj[v].push_back({u,w});
        }else{
            ll v,l,r,w;
            cin>>v>>l>>r>>w;
            if(t==2){
                v_to_range(v_to_range,1,v,w,1,n,l,r);
            }else if(t == 3){
                range_to_v(range_to_v,1,v,w,1,n,l,r);
            }
        }
    }

    vector<ll> dist(cnt+1,INF);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    dist[s] = 0;

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(auto &edge : adj[u]){
            ll v = edge.to;
            ll w = edge.w;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    for(ll i = 1;i<=n;i++){
        if(dist[i] == INF){
            cout<<-1<<" ";
        }else{
            cout<<dist[i]<<" ";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
```



## 调和级数

与其对数组b中每个数寻找数组a中是否存在能整除他的数，不如枚举数组a中的数的倍数后，看看b数组中是否有对应的值

因为前者的复杂度为$\;O(n^2)$ 后者则是$\;O(n\,ln\,n)$ 

后者代码可大致表示如下

```c++
int n = 1000000;
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {  // 注意这里是 j += i，而不是 j++
        // 执行某些 O(1) 的操作
    }
}
```

总操作次数T为
$$
T = \frac{n}{1} +\frac{n}{2}+...+\frac{n}{n}\\
T=n\times\,(\frac{1}{1}+\frac{1}{2}+...+\frac{1}{n})\\
$$


其中
$$
\sum_{i=1}^{n}\,\frac{1}{i}\;\approx\;\ln(n)
$$
所以时间复杂度是$O(n\ln(n))$



#小点

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
cout << setprecision(8) << value << endl; // 改成8精度

//整数向上取整可以 (a+b-1)/b

对于矩阵中的任意2*2子块，想要其合为合数，只需顺序填入值
    
cout << setprecision(8) << value << endl; // 改成8精度

//对于一个矩阵有一点(r,c),顺时针旋转后为(c,len-1-r),逆时针旋转后为(len-1-c,r),len为矩阵边长
//当然这里的坐标是相对坐标并不是全局坐标，即左上角为(0,0)
```



## 图论

对于任何森林（没有环的图），连通块数量  C 满足

$c = deg[u] - deg[v] - 1 - is\_adj(u,v)$ 其中 $$is\_adj(u,v)$$ 表示u和v是否为连边，是则为1，反之为0；





i $\equiv$j(modx) 意味着i和j关于x同余，那么集合可表示为{${1+x,1+2x,....,1+kx}$}



0-base 下$[L,R]$的和用前缀和表示为 `pre[R+1] - pre[L]`

1-base下$[L,R]$的和用前缀和表示为`pre[R] - pre[L-1]`

只由0或1组成的二维矩阵，只要该点为1(或0)且1(或0)的总数大于等于2时，总能找到一个终点，使得路径上排成的字符为回文串

对于一组升序排序的数组，如果任意两个数之差小于等于某一个值，那么整个数组中的数据可以被两两配对，且之差不大于那个值



如果再进行二分查找的时候成员函数有，直接用成员函数，不要用std::的，例如multiset有upper_bound和lower_bound函数

## 好用函数

`std::is_sorted(a.begin(),a.end());` //判断数组是否是非降序的 既检查是否满足 $a_i<=a_{i+1}$,是返回true，否则返回false

如果想检查是否为降序可添加 `std::greater<ll>()`

`std::is_sorted_until` 该函数返回一个迭代器，返回到哪个元素开始不再是非降序



`std::binary_search(起始迭代器，结束迭代器，要查找的值)` 该函数返回一个bool值，可查找数组中是否存在特点的值，存在返回 $true$ 否则 返回 $false$ ，当然数组得是单调的  该函数复杂度为 $O(log\,n)$


#自己的小壁画
在递归的过程中，例如dfs，在进行`for(auto v : adj[u])`的过程中，在for内部是对u的孩子节点进行操作的，而在for循环结束后则是对所有孩子节点给出的信息进行操作，这点在树上dp的时候要注意