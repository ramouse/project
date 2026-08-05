# 1.队列

## queue (<queue>)

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



## deque (<deque>)

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



## priority_queue (<priority_queue>)

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

- 定义

```c++
std::set<T> s; // 构造一个空集合
std::set<T> s(s_); // 将集合 s_ 的内容复制到 s 中
```

- 常用成员

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

- 常用成员

```c++
std::multiset<T> s;
s.count(x); // 返回 x 在 s 中的出现次数
s.erase(x); // 删除 x 在 s 中的 所有 出现
s.extract(x); // 删除 x 在 s 中的一个出现
s.find(x); // 返回 x 在 s 中的一个出现的迭代器
s.empty();//检查是否为空,空返回1否则返回0
s.size();//获取大小
```

- set类可以很方便的取出最大值和最小值，在遇到存在多次插入取出，求当前最大最小值时可以考虑

## 2.4pair(<utility>)

对组 (pair)，存放两个信息：first, second，相当于一个存放两个变量的类

当一个函数需要返回2个数据的时候，可以选择pair

- 定义

```c++
std::pair<T1, T2> p；//T1和T2b
p1.first;// 返回对象p1中名为first的公有数据成员
p1.second;// 返回对象p1中名为second的公有数据成员
```



## 2.5map (<map>)

`map` 容器中的元素是按照键的顺序自动排序的，这使得它非常适合需要快速查找和有序数据的场景。

- 定义

```c++
std::map<key_type，value_type> myMap  
//可声明多维map，例
std::map<int,map<int,int>> myMap;
//遍历
for (auto [key, value] : f) {
 std::cout << key << " " << value << "\n";
}
```

- 常用成员

```c++
mp[x];//返回键x对应的值
myMap.erase(key);//清楚key对应的元素
myMap.clear();//清空容器
myMap.size();//h
myMap.count("Bob"); // key 是否存在存在返回1，否则返回0
```



## 2.6 stack (<stack>)

栈 (stack)，一种后进先出的数据结构，能高效匹配括号，也能处理递归问题等

- 常用成员

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
reverse(res.begin(),res.end());
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

### 3.5.5 KMP

KMP 的核心任务是解决单模式串在主串中的匹配问题。当你用模式串 $P$ 去匹配主串 $T$ 时，如果中途在 $P[j]$ 处失配了，暴力算法会把主串指针回溯。而 KMP 告诉你：主串指针永远不回头，只移动模式串指针

核心数组：next（或 pi 数组）定义：next[i] 表示前缀 $P[0 \dots i]$ 的最长相等**前后**缀的长度（不能是它本身）。用途：当模式串在 $P[j]$ 失配时，说明前面的 $P[0 \dots j-1]$ 已经匹配成功。由于有 next 数组的存在，我们可以直接把模式串向右滑，让 $P[\text{next}[j-1]]$ 对齐刚才失配的位置继续比对。

**模板**：

```c++
// 计算最长相等前后缀 pi 数组 (即通常说的 next 数组)
vector<int> compute_pi(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// KMP 匹配：返回所有匹配成功的起始下标（0-indexed）
vector<int> kmp_match(const string& text, const string& pattern) {
    if (pattern.empty()) return {};
    vector<int> pi = compute_pi(pattern);
    vector<int> matches;
    int j = 0;
    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == pattern.size()) {
            matches.push_back(i - j + 1);
            j = pi[j - 1]; // 继续找下一个匹配
        }
    }
    return matches;
}
```
**KMP扩展**
1. **寻找最小循环节**（极其经典）对于一个长度为 $n$ 的字符串 $S$，计算出它的 pi 数组。定理：若 $n \pmod{n - \text{pi}[n-1]} == 0$ 且 $\text{pi}[n-1] > 0$，则 $S$ 具有常数周期的循环节，其最小循环元长度为 $L = n - \text{pi}[n-1]$，循环次数为 $\frac{n}{L}$。如果不能整除，说明它尾部缺了一点。但 $n - \text{pi}[n-1]$ 依然代表补齐后可能形成的最小周期。

```c++
int L = n - pi[n - 1];
        
// 3. 判定是否能完美整除
if (n % L == 0 && pi[n - 1] > 0) {
    cout << n / L << "\n";
} else {
    cout << 1 << "\n";
}
```

2. **前缀出现次数统计怎么在 $O(n)$ 时间内求出字符串 $S$ 的所有前缀在 $S$ 自身中出现了多少次?** 每一个 `pi[i]` 都代表一个前缀的结束。我们可以建立一张图，从 $i$ 向 $\text{pi}[i-1]$ 连边。这本质上是一棵 KMP 树（失配树）。通过在树上从叶子到根进行拓扑求和（或者简单的倒序递推 `ans[pi[i-1]] += ans[i]`），就可以一次性统计出所有前缀的全局出现次数。
```c++
// 统计 S 的所有前缀在 S 自身中的出现次数
    vector<int> count_prefix_occurrences(const string& s) {
    int n = s.size();
    vector<int> pi = compute_pi(s); // 使用之前的 KMP 模板
    
    // ans[len] 表示长度为 len 的前缀出现的总次数
    vector<int> ans(n + 1, 0);
    
    // 步骤 1：每个位置先自主贡献 1 次
    for (int i = 0; i < n; i++) {
        ans[i + 1] = 1;
    }
    
    // 步骤 2：从大到小倒序递推，相当于在失配树上从叶子向根节点求后缀和
    for (int i = n; i > 0; i--) {
        if (pi[i - 1] > 0) {
            ans[pi[i - 1]] += ans[i];
        }
    }
    
    // 此时 ans[len] 里存的就是长度为 len 的前缀在全局出现的绝对次数
    return ans; 
}
```



### 3.5.6 exKMP(Z函数)
exKMP 是 KMP 的全方位升级版。它的核心任务是：求文本串 $T$ 的每一个后缀与模式串 $P$ 的最长公共前缀 (LCP)。

**核心数组**：z 数组与 ext 数组竞赛中为了代码复用，通常分为两步：
1. z 数组（对 $P$ 自身求）：z[i] 表示以 $P[i]$ 开头的后缀 $P[i \dots m-1]$ 与整个 $P$ 的 LCP 长度。
2. ext 数组（$T$ 与 $P$ 匹配）：ext[i] 表示以 $T[i]$ 开头的后缀 $T[i \dots n-1]$ 与整个 $P$ 的 LCP 长度。

**工作机制**：Z-box（匹配盒子）exKMP 在维护过程中，会记录一个当前拓展到最右端的匹配区间 $[l, r]$（即 $T[l \dots r]$ 完全匹配了 $P[0 \dots r-l]$）。
- 当我们计算 $i$ 位置时，如果 $i \le r$，根据对称性，$T[i \dots r]$ 的信息完全等于 $P[i-l \dots r-l]$。
- 我们可以直接利用之前算好的 z[i-l] 来一刀切掉大段的重复匹配，直接从不需要比对的地方继续向外暴力外扩。

**模板**：
```c++
// 计算 P 自身的 Z 数组（即 exKMP 中的 nxt 数组）
vector<int> compute_z(const string& p) {
    int m = p.size();
    vector<int> z(m, 0);
    z[0] = m; // 自全匹配
    for (int i = 1, l = 0, r = 0; i < m; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < m && p[z[i]] == p[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// 计算 T 的每个后缀与 P 的 LCP (ext 数组)
vector<int> exkmp(const string& t, const string& p) {
    int n = t.size(), m = p.size();
    vector<int> z = compute_z(p);
    vector<int> ext(n, 0);
    for (int i = 0, l = 0, r = 0; i < n; ++i) {
        if (i <= r) ext[i] = min(r - i + 1, z[i - l]);
        while (i + ext[i] < n && ext[i] < m && p[ext[i]] == t[i + ext[i]]) ++ext[i];
        if (i + ext[i] - 1 > r) {
            l = i;
            r = i + ext[i] - 1;
        }
    }
    return ext;
}
```

**exKMP扩展**：
1. **任意位置的周期判定**
KMP 只能很方便地判定整个串的周期。而 exKMP 拥有无死角的视角：
- 如果你想判断以 $i$ 开头的后缀是否是原串的一个周期，只需看 z[i] 是否等于 $n - i$。如果是，说明 $S[i \dots n-1]$ 与原串前缀完全一致，意味着整个串在 $i$ 处发生了完美的错位重合。
2. **字符串拼接与前后缀重合问题**
比如题目要求：找出所有既是 $S$ 的前缀、又是 $S$ 的后缀、并且在 $S$ 中间还出现过至少一次的子串。z 数组天然包含了“既是前缀又是后缀”的信息（只要 $i + z[i] == n$ 即可）。我们只需要遍历中间部分的 $z$ 值，看看有没有大于等于当前后缀长度的值即可。配合线段树或简单的树状数组，能秒杀各种复杂的子串计数问题。
`-------------------------------------------------------
    解答：
    **如何判断“是后缀”？**
    如果从位置 $i$ 开始的匹配一直顶到了字符串的最后一个字符，说明它就是原串的一个后缀。
    **Z 数组翻译**： i + z[i] == n。此时这个后缀的长度就是 z[i]。
    **如何判断“在中间出现过”？**如果这个长度为 z[i] 的后缀/前缀，在 $i$ 之前还出现过，说明它在中间也有过匹配。这意味着在 $1 \dots i-1$ 之间，必然存在某个位置 $j$，使得从 $j$ 开始的匹配长度至少能覆盖 z[i]。 
    **Z 数组翻译**： 存在 $j < i$，使得 z[j] >= z[i]。
**code:**
```c++
// 引入计算 Z 数组的模板 (与上文一致)
vector<int> compute_z(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

string find_password(const string& s) {
    int n = s.size();
    vector<int> z = compute_z(s);
    
    int max_z = 0;     // 记录在当前 i 之前，出现过的最大 z 值
    int ans_len = 0;   // 记录满足条件的最长子串长度
    
    for (int i = 1; i < n; i++) {
        // 条件 1: 是后缀 (i + z[i] == n)
        // 条件 2: 在中间出现过 (max_z >= z[i])
        if (i + z[i] == n && max_z >= z[i]) {
            ans_len = max(ans_len, z[i]);
        }
        
        // 更新之前出现过的最大匹配长度
        max_z = max(max_z, z[i]);
    }
    
    if (ans_len > 0) {
        return s.substr(0, ans_len);
    } else {
        return "Just a legend"; // 题目要求的无解输出
    }
}    
```

任务：给定长度为 $n$ 的字符串 $S$，我们在第 $i$ 个位置切一刀，把前缀 $S[0 \dots i-1]$ 拼接到后缀 $S[i \dots n-1]$ 的后面。怎么快速判断拼接后的新串是否和原串 $S$ 依然一模一样？

**核心逻辑**：假设我们在下标 $i$ 处切一刀，原串 $S$ 被分成了两部分：
- 前部 A：$S[0 \dots i-1]$，长度为 $i$。
- 后部 B：$S[i \dots n-1]$，长度为 $n-i$。拼接后的新串是 B + A。我们要求 B + A == S。
既然 $S$ 本身就是 A + B 构成的，要想 B + A == A + B，必须同时满足两个极其严苛的条件：
1. B 必须和 $S$ 的前部完全一样：也就是说，后缀 $S[i \dots n-1]$ 必须和原串前缀匹配。
    - Z 数组翻译：z[i] == n - i
2. A 必须和 $S$ 的后部完全一样：也就是说，原串前缀 $S[0 \dots i-1]$ 必须和后缀 $S[n-i \dots n-1]$ 匹配。
    - Z 数组翻译：z[n - i] >= i （因为 $S[n-i]$ 开头的后缀的最长公共前缀至少得覆盖长度 $i$）。

```c++
// 纯 Z 数组原地判定法
    vector<int> find_valid_cuts_inplace(const string& s) {
    int n = s.size();
    vector<int> z = compute_z(s); // 只需要对原串求一次 Z 数组
    vector<int> valid_cuts;
    
    // 0 处切分（不切）默认算一种，如果要排除可以从 1 开始
    if (n > 0) valid_cuts.push_back(0); 
    
    for (int i = 1; i < n; i++) {
        // 条件1: 后部 B (长度 n-i) 必须和 S 的前缀匹配
        bool cond1 = (z[i] == n - i);
        // 条件2: 前部 A (长度 i) 必须和 S 的后缀(起点为 n-i)匹配
        bool cond2 = (z[n - i] >= i);
        
        if (cond1 && cond2) {
            valid_cuts.push_back(i);
        }
    }
    return valid_cuts;
}
```



### 3.5.7 马拉车算法（处理最长回文串）

马拉车算法（Manacher's Algorithm）是专门为解决“最长回文子串”问题而生的。它通过巧妙地利用回文串的**对称性**，跳过了大量重复的字符比较，将时间复杂度从原本的 O(n²) 压缩到了极其极致的 O(n)。



```c++
void solve()
{
    string s;
    cin >> s;
    
    // 1. 预处理字符串
    // 在每个字符之间插入 '#'，并在首尾加入不同的特殊字符（如 '^' 和 '$'）
    // 这样既统一了奇偶长度问题，又避免了中心扩展时的数组越界检查
    string t = "^#";
    for(char c : s) {
        t += c;
        t += '#';
    }
    t += '$';

    int n = t.length();
    vector<int> p(n, 0); // p[i] 记录以 t[i] 为中心的最长回文半径
    int C = 0; // 当前能够向右扩展最远的回文串的中心
    int R = 0; // 当前能够向右扩展最远的回文串的右边界
    int max_len = 0;

    for(int i = 1; i < n - 1; i++) {
        // 2. 利用已知回文串的对称性，初始化 p[i]
        // 如果 i 在 R 的左侧，可以利用对称点 (2 * C - i) 的信息加速
        if (i < R) {
            p[i] = min(R - i, p[2 * C - i]);
        }
        
        // 3. 尝试继续向两边扩展 (由于首尾有 ^ 和 $ 挡着，无需判断越界)
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        
        // 4. 如果新找到的回文串右边界超过了当前的 R，则更新 C 和 R
        if (i + p[i] > R) {
            C = i;
            R = i + p[i];
        }
        
        // p[i] 恰好等于原字符串中对应回文串的总长度
        max_len = max(max_len, p[i]);
    }

    cout << max_len << "\n";
}
```



### 3.5.8 哈希







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

//寻找u,v的lca
// 假设 MAX_LOG 一般取 20 (因为 2^20 > 10^5)
int get_lca(int u, int v) {
    // 步骤 1：始终保持 u 是更深的那个节点 (方便后面把 u 往上提)
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    
    // 步骤 2：让 u 往上跳，直到 u 和 v 处于同一深度
    // 从大步到小步尝试
    for (int i = MAX_LOG; i >= 0; i--) {
        // 如果 u 跳 2^i 步之后，高度仍然 >= v 的高度，那就跳
        // (注：如果跳过头了，到了 0 号节点，depth[0] 一般是 0，条件自然不成立)
        if (depth[up[u][i]] >= depth[v]) {
            u = up[u][i];
        }
    }
    
    // 步骤 3：特判。如果齐平后 u 和 v 重合了，说明原来的 v 就是 u 的祖先
    if (u == v) {
        return u;
    }
    
    // 步骤 4：u 和 v 同时往上跳，寻找 LCA 的“正下方”那个节点
    for (int i = MAX_LOG; i >= 0; i--) {
        // 如果 u 和 v 跳 2^i 步后，到达的节点【不一样】
        // 说明还没有到达 LCA（或者还没越过 LCA），那就可以跳！
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    // 步骤 5：循环结束后，u 和 v 必定处于 LCA 的直接子节点位置
    // 所以它们的父节点 up[u][0] 就是 LCA
    return up[u][0];
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

 

### 判环

​	1.无向图：如果遇到一个已经访问过的点，那么说明有环

- dfs:递归访问，记录vis。如果邻居节点v访问过且不是父节点，则有环
- 并查集：遍历每一条边，如果`find(u)==find(v)`，说明有环
- bfs：同理dfs

2. 有向图：不能简单看是否访问过

- dfs+三色标记：

  - 0表示未访问，1表示正在递归中，没有判断完，2表示已完全递归完毕，该节点不在环内

  ```c++
  bool dfs(ll u){
      vis[u] = 1;
      for(ll &v : adj[u]){
          if(vis[v]==1){
              return true;
          }
          if(vis[v]==0 && dfs(v)) return true;
      }
      
      vis[u] = 2;
      return false;
  }
  ```

- 拓扑

  - **逻辑**：
    1. 统计所有点入度。
    2. 将入度为 0 的点入队。
    3. 不断弹出队首，将其邻居入度减 1。若邻居入度减为 0，则入队。
  - **判定**：如果最后**处理过的节点总数 < 图中节点总数**，说明剩下的点入度永远减不到 0（互相死锁），**有环**。
  - **优点**：逻辑清晰，还能顺便求出拓扑序。

  ```c++
  vector<ll> deg(n+1,0)//存节点入度
  for(int i = 1;i<=n;i++){
      for(ll v : adj[i]){
          deg[v]++;
      }
  }
  
  queue<ll> q;
  for(int i = 1;i<=n;i++){
      if(deg[i]==0) q.push(i);
  }
  
  ll count = 0;
  
  while(!q.empty()){
      ll u = q.front();
      q.pop();
      count++;
      
      for(ll v : adj[u]){
          deg[v]--;
          if(deg[v]==0) q.push(v);
      }
  }
  
  if(count == n){
      //无环
  }else{
      //有环
  }
  ```

​	3.负权环

- 详情见最短路中的SPFA

​         

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
#### 带删除并查集
基础并查集基于树形结构，一旦某个节点被合并，它可能成为很多其他节点的父节点。如果直接删除它或把它移到别的集合，整棵树就断开了。

**核心思想：虚拟节点（映射法）**
既然真实的节点不能乱动，我们就给每一个真实节点分配一个“虚拟信箱”（虚拟节点）。
- 合并操作：我们实际上是在合并“虚拟节点”。
- 删除操作：当我们要删除节点 $x$ 时，我们不改动原本树中的结构，而是直接给节点 $x$ 分配一个新的、独立的虚拟节点。
- 原来的节点就变成了一个没人用的“空壳”（僵尸节点），这不会影响其他依赖它的子节点。

**适用场景**：
 - 需要将某个节点从当前连通块中分离出来（删除）。

 - 需要将某个节点从集合 A 移动到集合 B。

 - 动态图连通性问题中，涉及节点失效的场景。
``` c++
/**
 * 带删除的并查集
 * 核心原理：使用 id 数组将真实节点映射到虚拟节点，删除即重新映射。
 */
struct DeletableDSU {
    std::vector<int> parent;
    std::vector<int> siz;
    std::vector<int> id; // id[x] 表示真实节点 x 当前对应的虚拟节点编号
    int virtual_cnt;     // 虚拟节点分配计数器

    // 初始化：n 为初始节点数，max_ops 为预估的最大删除/移动操作次数
    DeletableDSU(int n, int max_ops) : 
        parent(n + max_ops + 1), 
        siz(n + max_ops + 1, 1), 
        id(n + 1) 
    {
        virtual_cnt = n;
        // 初始时，真实节点 1~n 映射到虚拟节点 1~n
        for (int i = 1; i <= n; i++) {
            id[i] = i;
        }
        // 初始化所有的虚拟节点
        std::iota(parent.begin(), parent.end(), 0);
    }

    // 查找：注意这里查找的是 id[x] 映射到的虚拟节点
    int find(int x) {
        int v = id[x]; // 先找到它当前的虚拟节点
        return parent[v] == v ? v : parent[v] = find(parent[v]);
    }

    // 内部查找：直接针对虚拟节点查找
    int find_virtual(int v) {
        return parent[v] == v ? v : parent[v] = find_virtual(parent[v]);
    }

    // 合并 x 和 y
    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (siz[rootX] < siz[rootY]) std::swap(rootX, rootY);
        
        parent[rootY] = rootX;
        siz[rootX] += siz[rootY];
        return true;
    }

    // 删除/孤立 节点 x
    void remove(int x) {
        int rootX = find(x);
        siz[rootX]--; // 原集合大小减一
        
        // 给 x 分配一个新的独立虚拟节点
        id[x] = ++virtual_cnt; 
        parent[id[x]] = id[x];
        siz[id[x]] = 1;
    }

    // 将节点 x 移动到节点 y 所在的集合
    void move(int x, int y) {
        if (find(x) == find(y)) return;
        remove(x); // 先把 x 独立出来
        merge(x, y); // 再把 x 融进 y
    }
};
```

#### 带权并查集
基础并查集只能回答“$x$ 和 $y$ 是不是一伙的”，但无法回答“在同一伙里，$x$ 和 $y$ 之间有什么具体关系”。

**核心思想：边权维护（向量运算）**
我们在节点指向父节点的边上增加一个权值 (weight)。
- 权值表示：weight[x] 记录的是节点 $x$ 到其父节点的某种相对关系（比如距离差、分数差、胜负关系）。
- 路径压缩：在 find 时，不仅要把 $x$ 挂到根节点上，还要把 weight[x] 更新为 $x$ 到根节点的关系。
- 合并计算：在 merge 时，如果已知 $x$ 到 $y$ 的关系为 $w$，通过向量加减法推导出根节点 $rootX$ 到 $rootY$ 的关系，从而连接两个树。

**适用场景**：
- 维护区间和（如：已知区间 $[l, r]$ 的和，问能否推断出另一区间的和）。
- 种类并查集/相对关系推断（如经典题：POJ 食物链、给出 $x-y=c$ 的多个方程判断是否冲突）。
- 在同一个连通块内，计算任意两点之间的差值/距离
```c++
/**
 * 带权并查集
 * 权值定义：weight[x] 表示节点 x 相对于其父节点的差值/距离
 */
struct WeightedDSU {
    std::vector<int> parent;
    std::vector<ll> weight; // 记录到父节点的权值

    WeightedDSU(int n) : parent(n + 1), weight(n + 1, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    // 查找：路径压缩，同时更新权值
    int find(int x) {
        if (parent[x] == x) return x;
        
        int old_parent = parent[x];
        parent[x] = find(parent[x]); // 递归找根
        
        // 核心：x 到新根的权值 = x 到旧父节点的权值 + 旧父节点到根的权值
        weight[x] += weight[old_parent]; 
        
        return parent[x];
    }

    // 合并：已知 x 相对于 y 的权值为 w (例如：x - y = w)
    // 规定方向：y 指向 x 的值为 w
    bool merge(int x, int y, ll w) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false; // 已经在同一集合

        // 将 rootX 挂在 rootY 下
        parent[rootX] = rootY;

        // 核心数学推导：向量加法
        // x -> rootX (权值为 weight[x])
        // y -> rootY (权值为 weight[y])
        // 已知关系: x 相对于 y 是 w 
        // 所以 rootX 相对于 rootY 的权值应该如何推导？
        // rootX_to_rootY = weight[y] - weight[x] + w; 
        weight[rootX] = weight[y] - weight[x] + w; 
        
        return true;
    }

    // 判断两个点是否在同一集合，并返回它们之间的权值差
    // 假设查询 x 相对于 y 的差值
    bool query(int x, int y, ll &result) {
        if (find(x) != find(y)) {
            return false; // 不连通，无法推断关系
        }
        // result = x_to_root - y_to_root
        result = weight[x] - weight[y]; 
        return true;
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

#### 区间最大值

只需在`push_up` 中改为取 `max` 即可





### 珂朵莉树(odt)

它**并不是一种传统的树形数据结构**（如线段树、平衡树），而是一种基于 C++ STL 中的 std::set 来维护**连续区间相同值**的暴力数据结构/思想

1. 核心思想与适用场景

**适用条件（极其苛刻但极其重要）：**

1. 题目必须有**区间平推（区间推平/区间赋值）**操作，即 将区间 [L, R] 内的所有数字修改为同一个值 V。
2. 题目的数据最好是**随机生成的**。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct Node {
    ll l, r;
    mutable ll v;
    bool operator<(const Node& o) const { return l < o.l; }
};

set<Node> odt;
ll n;

// 核心1：分裂区间
auto split(ll x) {
    if (x > n) return odt.end();
    auto it = --odt.upper_bound({x, 0, 0});
    if (it->l == x) return it;
    ll l = it->l, r = it->r;
    ll v = it->v;
    odt.erase(it);
    odt.insert({l, x - 1, v});
    return odt.insert({x, r, v}).first;
}

// 核心2：区间推平 (灵魂所在，降维打击)
void assign(ll l, ll r, ll v) {
    auto itr = split(r + 1);
    auto itl = split(l);
    odt.erase(itl, itr);
    odt.insert({l, r, v});
}

// 应用1：区间加法
void range_add(ll l, ll r, ll val) {
    auto itr = split(r + 1);
    auto itl = split(l);
    for (auto it = itl; it != itr; ++it) {
        it->v += val; // 因为有 mutable，直接改
    }
}

// 应用2：区间求和
ll range_sum(ll l, ll r,ll x,ll mod) {
    auto itr = split(r + 1);
    auto itl = split(l);
    ll res = 0;
    for (auto it = itl; it != itr; ++it) {
        res += (it->r - it->l + 1) * it->v; 
    }
    return res;
}

// 扩展：区间求第 K 小 (非常典型的 ODT 应用)
ll kth_smallest(ll l, ll r, ll k) {
    auto itr = split(r + 1);
    auto itl = split(l);
    // 把区间抽出来排序
    vector<pair<ll, ll>> vec;
    for (auto it = itl; it != itr; ++it) {
        vec.push_back({it->v, it->r - it->l + 1});
    }
    sort(vec.begin(), vec.end());
    for (auto& p : vec) {
        k -= p.second;
        if (k <= 0) return p.first;
    }
}

void solve()
{
     // 初始化时，把整个数组插入 ODT
    // 假设初始数组全是 0
    n = 100000;
    odt.insert({1, n, 0});
    
    // 如果初始数组有初值，例如 a[1...n]
    for(int i=1; i<=n; ++i) {
        odt.insert({i, i, a[i]}); 
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```



### 二分图

#### 1.二分冲突模型

当题目中包含以下三个特征时

- **分成两组**：题目要求将一堆物品、人或节点，划分到**恰好两个**集合中（比如：分到 A 学院和 B 学院、分到两座监狱、染成黑白两色）。

- **两两关系**：任意两个元素之间存在某种“代价、反应值、冲突值”。

- **最值的最值**：

- 题目的最终提问一定是以下两种句式之一：

  - 求同一组内的最大值，使其**尽可能小**。（最大值最小化）
    - **场景**：同一组内的人会打架，你要让同一组内打架最厉害的那对，伤害值尽可能小。
    - **二分目标X**：我们要让同组的最大冲突$\leq$ $X$;
    - **连边条件**：所有冲突值 $> X$ 的两人不能放在一起，所以连边后判断是否为二分图  
  - 求同一组内的最小值，使其**尽可能大**。（最小值最大化）
    - **场景**：同一组内的人要合作，你要让同一组内最拉胯的那对，默契值尽可能大。
    - **二分目标X**：我们要让同组的最小默契$\geq$ $X$;
    - **连边条件**：所有默契值 $< X$ 的两人不能放在一起，所以连边后判断是否为二分图  

- 模板：

  ```c++
  	vector<ll> vis(n+1,-1);
  	//判断是否为二分图
      auto isg = [&](auto &&self,ll u,ll c,vector<vector<ll>> &vec) -> bool{
          vis[u] = c;
          for(ll v : vec[u]){
              if(vis[v]==c) return false;
              if(vis[v] == -1 && !self(self,v,c^1,vec)) return false;
          }
          return true;
      };
  	// 二分检查
      auto check = [&](ll lim) -> bool{
          vector<vector<ll>> vec(n+1);
          for(auto [u,v,w] : adj){
              if(w>lim){
                  vec[u].push_back(v);
                  vec[v].push_back(u);
              }
          }
  
          vis.assign(n+1,-1);
          for(int i = 1;i<=n;i++){
              if(vis[i] == -1){
                  if (!isg(isg,i, 1, vec))
                      return false;
              }
              
          }
          return true;
      };
  
      ll ans = 0;
      ll l = 0,r = a.size()-1;//所有值的个数，要记得去重
      while(l<=r){
          ll mid = (l+r)>>1;
          if(check(a[mid])){
              // 依据情况逼近：
              // 变体 A (求最小): R = mid - 1; 
              // 变体 B (求最大): L = mid + 1;
              ans = a[mid];
              // cout<<a[mid]<<" ";
          }else{
              //反向进行
          }
      }
  ```






### ST表

**ST 表（Sparse Table，稀疏表）** 是一种非常经典且优雅的静态数据结构，专门用于解决**可重复贡献问题**（最常见的就是 **RMQ：区间最值查询**）。

它的核心优势在于极其变态的查询速度：只需一次 $O(N \log N)$ 的预处理，就能在 $O(1)$ 的时间复杂度内回答任意区间的查询。



#### 一、 核心思想：倍增（Doubling）与 DP

ST 表的本质是**动态规划（DP）\**结合\**倍增**思想。

普通的暴力查询是逐个遍历区间内的元素，而 ST 表通过预先计算好长度为 $2^0, 2^1, 2^2, \dots$ 的区间的答案，在查询时用两个长度为 $2^k$ 的区间“拼凑”出目标区间。

##### 1. 状态定义

我们设二维数组 $st[i][j]$ 表示：**从下标 $i$ 开始，长度为 $2^j$ 的区间内的最值**。

- 也就是区间 $[i, i + 2^j - 1]$ 的最值。
- 当 $j=0$ 时，长度为 $2^0 = 1$，即 $st[i][0]$ 就是元素本身 $A[i]$。

##### 2. 状态转移（预处理）

如何求长度为 $2^j$ 的区间的最值呢？

我们可以把它等分成两半，每半的长度正好是 $2^{j-1}$。

- 前一半的区间是 $[i, i + 2^{j-1} - 1]$，对应的状态是 $st[i][j-1]$。
- 后一半的区间是从 $i + 2^{j-1}$ 开始，长度也是 $2^{j-1}$，对应的状态是 $st[i + 2^{j-1}][j-1]$。

因此，转移方程（以求最小值为例）非常自然：

$$st[i][j] = \min(st[i][j-1], st[i + 2^{j-1}][j-1])$$

> **注意：** 在写代码时，外层循环必须是枚举区间长度（即 $j$），内层循环枚举起点 $i$，因为长区间的状态依赖于短区间的状态。

##### 3. $O(1)$ 查询（拼凑区间）

假设我们要查询区间 $[L, R]$ 的最小值，区间长度为 $len = R - L + 1$。

我们找到一个最大的整数 $k$，使得 $2^k \le len$（即 $k = \lfloor \log_2(len) \rfloor$）。

我们用两个长度为 $2^k$ 的区间来覆盖目标区间 $[L, R]$：

- 从 $L$ 往右、长度为 $2^k$ 的区间：对应的状态是 $st[L][k]$。
- 从 $R$ 往左、长度为 $2^k$ 的区间：对应的状态是 $st[R - 2^k + 1][k]$。

这两个区间可能会**重叠**，但绝对不会超出 $[L, R]$ 的范围，并且完全覆盖了 $[L, R]$。

因为我们在求最值（$\min$ 或 $\max$），**一个元素被比较一次还是多次，不影响最终结果**（这就是“可重复贡献问题”的性质）。

所以区间 $[L, R]$ 的最小值就是：

$$\min(st[L][k], st[R - 2^k + 1][k])$$

#### 二、 完整代码模板

以求解 **区间最小值** 为例（下标从 0 开始）：

```c++
#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    int n;
    // st[j][i] 表示从 i 开始，长度为 2^j 的区间最小值
    // 注意：把 j 放在第一维能提高缓存命中率 (Cache Friendly)，常数更小
    vector<vector<int>> st;
    vector<int> lg; // 预处理 log2 数组，实现真正的 O(1) 查询

    void init(const vector<int>& a) {
        n = a.size();
        int max_log = __lg(n) + 1; // __lg(n) 是 GCC 内置函数，求向下取整的 log2(n)
        
        st.assign(max_log, vector<int>(n));
        lg.assign(n + 1, 0);

        // 预处理 log 数组 (如果不用 __lg 可以用这个)
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        // 初始化长度为 2^0 = 1 的区间
        for (int i = 0; i < n; i++) {
            st[0][i] = a[i];
        }

        // DP 预处理
        for (int j = 1; j < max_log; j++) {
            // i + (1 << j) <= n 保证右边界不越界
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r) {
        if (l > r) swap(l, r);
        int k = __lg(r - l + 1); // 也可以用预处理的 lg[r - l + 1]
        // 两个区间求 min
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
```

#### 优势：

1. **查询极快**：纯正的 $O(1)$，在查询次数极其庞大（例如 $10^6$ 或 $10^7$ 级别）时，吊打线段树（$O(\log N)$）。
2. **代码简短**：没有复杂的递归或树形结构维护，常数非常小。

#### 劣势：

1. **必须是静态数组**：一旦初始化完成，**不支持任何修改操作**（单点修改、区间修改都不行）。如果需要修改，只能用线段树或树状数组。
2. **空间消耗较大**：$O(N \log N)$ 的空间在 $N = 10^7$ 时可能会导致内存超限（MLE）。
3. **只适用“可重复贡献问题”**：比如最值（$\max, \min$）、最大公约数（$\gcd$）、按位与/或（$\&, \mid$）。对于区间求和（$\sum$），因为重叠部分会被加两次，所以不能用常规的 $O(1)$ 查询 ST 表（求和应使用前缀和或线段树）。

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



#### 裴蜀定理

设 𝑎,𝑏![a,b](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 是不全为零的整数．那么，对于任意整数 𝑥,𝑦![x,y](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，都有$ gcd(𝑎,𝑏) ∣𝑎𝑥 +𝑏𝑦$![\gcd(a,b)\mid ax+by](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 成立；而且，存在整数 𝑥,𝑦![x,y](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，使得 $𝑎𝑥 +𝑏𝑦 =gcd(𝑎,𝑏)$ 成立．

**推广** ：

设 $𝑎_1,𝑎_2,⋯,𝑎_𝑛$![a_1,a_2,\cdots,a_n](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 是不全为零的整数．那么，对于任意整数$ 𝑥_1,𝑥_2,⋯,𝑥_𝑛$![x_1,x_2,\cdots,x_n](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，都有 $gcd(𝑎1,𝑎2,⋯,𝑎𝑛) ∣𝑎_1𝑥_1 +𝑎_2𝑥_2 +⋯ +𝑎_𝑛𝑥_𝑛$![\gcd(a_1,a_2,\cdots,a_n)\mid a_1x_1+a_2x_2+\cdots+a_nx_n](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 成立；而且，存在整数 $𝑥_1,𝑥_2,⋯,𝑥_𝑛$![x_1,x_2,\cdots,x_n](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，使得 $gcd(𝑎_1,𝑎_2,⋯,𝑎_𝑛) =𝑎_1𝑥_1 +𝑎_2𝑥_2 +⋯ +𝑎_𝑛𝑥_𝑛$ 成立．

**应用**：

题意：给出n张卡片并有一条无限长的纸带，分别有$l_i$和$c_i$,你可以花$c_i$的钱来购买卡片然后选择在纸带上向前或向后跳 $l_i$ 个单位任意次，问你至少花多少钱才能走遍才能跳到纸带上的所有点

解：分析该问题，发现想要跳到每一个格子上，必须使得所选数$ 𝑙_{𝑖_1},⋯,𝑙_{𝑖_𝑘}$![l_{i_1}, \cdots, l_{i_k}](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 通过数次相加或相减得出的绝对值为 1![1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)．也就是说，存在整数 $𝑥_1,⋯,𝑥_𝑘$![x_1, \cdots, x_k](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 使得 $𝑙_{𝑖_1}𝑥_1 +⋯ +𝑙_{𝑖_𝑘}𝑥_𝑘 =1$．由多个整数的裴蜀定理，这相当于从数组 $𝑙_1,⋯,𝑙_𝑛$![l_1, \cdots, l_n](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 中选择若干个数，满足它们的最大公约数为 1![1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，同时要求代价和最小



如果每次只能向左或向右移动a步或b步，能到达的所有位置一定是起点加上$gcd(a,b)$的倍数；应用到n种可能的位移上也是一样的



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



### 给定区间内求与n互质的数的个数

#### 1. 核心思想：正难则反

要直接找“互质”的数很难，但找“不互质”的数很容易。

如果一个数 $m$ 与 $n$ 不互质，说明它们有**共同的质因数**。因此，我们只需要算出 $[1, X]$ 内有多少个数是 $n$ 的质因数的倍数，然后用总数 $X$ 减去这些数，剩下的就是互质的数。

#### 2. 数学推导过程

假设 $n$ 的所有**不同质因数**为 $p_1, p_2, \dots, p_k$。

- **步骤一：总数**

  在 $[1, X]$ 范围内，整数的总个数是 $X$。

- **步骤二：减去单个质因数的倍数**

  $[1, X]$ 中，包含因子 $p_i$ 的数有 $\lfloor X / p_i \rfloor$ 个。

  我们要减去这些数。

- **步骤三：加回被重复减去的（两个质因数乘积的倍数）**

  当我们减去 $p_1$ 的倍数和 $p_2$ 的倍数时，那些既是 $p_1$ 又是 $p_2$ 的倍数（也就是 $p_1 \times p_2$ 的倍数）被减了两次。为了平衡，我们需要**加回** $\lfloor X / (p_1 \times p_2) \rfloor$。

- **步骤四：减去加多了的（三个质因数乘积的倍数）**

  同理，三个质因数乘积的倍数在前面“减、加”的过程中算错了，需要再次**减去** $\lfloor X / (p_1 \times p_2 \times p_3) \rfloor$。

以此类推，**奇数个质因数的乘积做减法，偶数个质因数的乘积做加法**。



```c++
//求[1,x]内与n互质的数的个数
ll count_coprime(ll X, const vector<ll>& p_factors) {//p_factors为n中的所有不同质因数
    if (X == 0) return 0;
    ll res = 0;
    int k = p_factors.size();
    
    // 用二进制枚举所有的组合
    for (int mask = 0; mask < (1 << k); mask++) {
        ll prod = 1;
        int bits = 0; // 记录当前组合选了几个质因数
        
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                prod *= p_factors[i];
                bits++;
            }
        }
        
        // 奇数个质因数做减法，偶数个做加法
        if (bits % 2 == 1) res -= X / prod;
        else res += X / prod;
    }
    return res;
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

ll A(ll n,ll k){
    if(k<0 || k>n) return 0;
    return fact[n] * inv[n-k] % MOD;
}
```



#3.8 位运算

```c++
__builtin_ctz(x) //获取x二进制后缀0的长度
__builtin_clz(x) //获取x二进制前缀0的长度  //二者皆为接受int类型，接受ll需要后面加ll //_

A + B = A^B + 2 * (A&B);
A | B = (A ^ B) ^ (A & B);
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



对于线性基中的**第 $K$ 小**与**第 $K$ 大**问题，核心在于利用消元重构后的独立性，把“组合问题”转化为“二进制按位选择问题”。

### 一、 先决条件：消元重构（Simplify/Rebuild）

在查询之前，必须先将线性基化为**简化阶梯型**（即前文提到的 `rebuild()`）。

重构的目的是让基元素之间**相互独立**：

- 设重构并提取出的非零基元素从小到大排列为 $d[0], d[1], d[2], \dots, d[m-1]$（共 $m$ 个）。
- 此时 $d[i]$ 的最高有效位（第 $i$ 个主位）上为 1，且其他更高的 $d[j]\ (j > i)$ 在这个主位上**全为 0**。
- **核心结论**：这 $m$ 个元素能组合出 $2^m$ 个互不相同的非负整数，并且**这些整数的大小顺序，完全由选取时用到的 $d$ 的下标对应的二进制位决定**。

### 二、 求第 $K$ 小（K-th Smallest）

求第 $K$ 小时，我们需要注意**是否能组合出 $0$**：

- 如果原数组元素个数 $N > m$，说明原数组存在线性相关，可以组合出 0，此时 **0 是第 1 小的数**。
- 如果 $N = m$，则非空子集无法组合出 0。

#### 算法步骤：

1. **边界判定**：可生成的不同数值总数为 $total = 2^m$（若包含 0）或 $2^m - 1$（若不含 0）。若 $K > total$，无解（返回 -1）。
2. **偏移修正**：如果可以组合出 0：
   - $K = 1$ 时直接返回 $0$；
   - $K > 1$ 时，由于 0 占用了第 1 小的位置，在非零组合中我们要找的是**第 $K-1$ 小**，因此令 $K = K - 1$。
3. **二进制拆分**：将 $K$ 转化为二进制。若 $K$ 的第 $i$ 位为 1，则结果异或上 $d[i]$。

### 三、 求第 $K$ 大（K-th Largest）

“第 $K$ 大”可以非常自然地**转化为求“第几小”**。

#### 转化逻辑：

假设线性基可以生成 $Total$ 个不同的数（从 1 到 $Total$ 排名）：

- 最大的数（第 1 大）等于 **第 $Total$ 小**。
- 第 2 大的数等于 **第 $Total - 1$ 小**。
- **第 $K$ 大的数等于 第 $Total - K + 1$ 小**。

#### 算法步骤：

1. 计算总共能生成的不同数字个数 $Total$：
   - 可组合出 0 时，$Total = 2^m$；
   - 不可组合出 0 时，$Total = 2^m - 1$。
2. 若 $K > Total$，无解（返回 -1）。
3. 转化为求第 $K' = Total - K + 1$ 小，直接调用第 $K$ 小的逻辑即可。

```c++
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct LinearBasis {
    static const int MAX_BIT = 60; // 根据题目数据范围调整 (例如 10^18 对应 60)
    long long p[MAX_BIT + 1];      // 存储原始线性基
    vector<long long> d;           // 存储重构后的线性基
    int cnt;                       // 线性基中有效元素的个数 (非零基底数)
    int n;                         // 尝试插入的总元素个数

    // 初始化
    LinearBasis() {
        memset(p, 0, sizeof(p));
        cnt = 0;
        n = 0;
    }

    // 1. 插入一个数
    // 返回值：true 表示成功插入(线性无关)，false 表示无法插入(线性相关)
    bool insert(long long x) {
        n++; // 记录插入的总数
        for (int i = MAX_BIT; i >= 0; --i) {
            if ((x >> i) & 1) {
                if (!p[i]) {
                    p[i] = x;
                    cnt++;
                    return true;
                }
                x ^= p[i];
            }
        }
        return false;
    }

    // 2. 查询能异或出的最大值
    long long query_max() {
        long long res = 0;
        for (int i = MAX_BIT; i >= 0; --i) {
            if ((res ^ p[i]) > res) {
                res ^= p[i];
            }
        }
        return res;
    }

    // 3. 查询能异或出的最小非零值
    long long query_min() {
        for (int i = 0; i <= MAX_BIT; ++i) {
            if (p[i]) return p[i];
        }
        return 0; // 只有线性基为空时才会返回 0
    }

    // 4. 重构线性基 (化为简化阶梯型，用于第 K 大/小查询)
    // 注意：调用第 K 大/小查询前，必须先调用一次此函数！
    void rebuild() {
        d.clear();
        for (int i = MAX_BIT; i >= 0; --i) {
            if (p[i]) {
                for (int j = i - 1; j >= 0; --j) {
                    if ((p[i] >> j) & 1) {
                        p[i] ^= p[j];
                    }
                }
            }
        }
        // 将重构后的非零元素按从小到大提取出来
        for (int i = 0; i <= MAX_BIT; ++i) {
            if (p[i]) {
                d.push_back(p[i]);
            }
        }
    }

    // 5. 查询能异或出的第 K 小的值
    // 返回 -1 表示 K 超出了能组合出的总数范围
    long long query_kth_smallest(long long k) {
        bool can_be_zero = (n > cnt); // 插入总数 > 基底数，说明存在线性相关，能组合出 0
        long long total_combinations = (1LL << d.size()) - (can_be_zero ? 0 : 1);
        
        if (k > total_combinations) return -1;

        // 如果能组合出 0，那么 0 就是第 1 小
        if (can_be_zero) {
            if (k == 1) return 0;
            k--; // 扣除 0 占用的第 1 小位置
        }

        long long ans = 0;
        for (int i = 0; i < d.size(); ++i) {
            if ((k >> i) & 1) {
                ans ^= d[i];
            }
        }
        return ans;
    }

    // 6. 查询能异或出的第 K 大的值
    // 返回 -1 表示 K 超出了能组合出的总数范围
    long long query_kth_largest(long long k) {
        bool can_be_zero = (n > cnt);
        long long total_combinations = (1LL << d.size()) - (can_be_zero ? 0 : 1);
        
        if (k > total_combinations) return -1;

        // 第 K 大 等价于 第 (Total - K + 1) 小
        long long k_small = total_combinations - k + 1;
        return query_kth_smallest(k_small);
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
        if (b[i] > low[len]) //如果是最长不降就是>=,也就是允许相等的情况
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

1. 求【最长上升子序列 (严格递增 <)】

- **数组状态：** 升序。
- **延长条件：**` if (x > dp[len])`
- **替换位置：** 找第一个 `≥x`的数替换掉它。
- **使用函数：** **`lower_bound(..., x)`** （默认就是升序）

2. 求【最长不下降子序列 (允许相等 `≤`)】

- **数组状态：** 升序。
- **延长条件：**` if (x >= dp[len])`
- **替换位置：** 找第一个 `>x` 的数替换掉它。
- **使用函数：** **`upper_bound(..., x)`**

3. 求【最长下降子序列 (严格递减 >)】

- **数组状态：** 降序。
- **延长条件：** `if (x < dp[len])`
- **替换位置：** 找第一个 `≤x` 的数替换掉它。
- **使用函数：** **`lower_bound(..., x, greater<ll>())`**

4. 求【最长不上升子序列 (允许相等 `≥`)】

- **数组状态：** 降序。
- **延长条件：** `if (x <= dp[len])`
- **替换位置：** 找第一个 `<x `的数替换掉它。
- **使用函数：** **`upper_bound(..., x, greater<ll>())`**



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



## 3.11 杂项

### 莫队

#### 莫队基础

**莫队算法**本质上是一种**极其优雅的暴力**，其本质是**分块**。它用于解决**离线区间查询**问题（“离线”意味着我们可以一次性读入所有查询，打乱顺序计算后再按原顺序输出）

如果已知区间$[L,R]$ 的答案，能够快速的得到其相邻区间的答案，即可使用莫队算法来求解

莫队算法的精髓就在于：**通过对查询区间进行巧妙的排序，严格限制双指针移动的步数总和，将其优化到**$O(N\sqrt{N})$ ，为了做到这一点，我们需要分块，也就是把长度为 **$N$** 的的数组分为 **$\sqrt{N}$** 的块，每个块的长度为**$\sqrt{N}$**。

1. 常规排序（基础版）

- **第一关键字：** 左端点 L 所在的**块编号**从小到大排序。
- **第二关键字：** 右端点 R 的位置从小到大排序。

2. 奇偶排序

- **第一关键字：** 左端点 L 所在的块编号从小到大排序。
- **第二关键字：** 如果 L 所在的块编号是**奇数**，则 R **从小到大**排序；如果 L 所在的块编号是**偶数**，则 R **从大到小**排序。

在莫队中，指针移动代码如下：

```c++
while (l > q.l) add(--l); // L左移，区间变大
while (r < q.r) add(++r); // R右移，区间变大
while (l < q.l) del(l++); // L右移，区间变小
while (r > q.r) del(r--); // R左移，区间变小
```

模板示例(以查询区间不同数字的个数为例)

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200005; // 根据题目修改范围
int a[N];         // 原数组
int cnt[N];       // 记录元素的出现次数
int ans[N];       // 记录每个查询的最终答案
int current_ans;  // 维护当前窗口内的答案
int block;        // 分块大小

// 1. 定义查询结构体
struct Query {
    int l, r, id;
};
vector<Query> q;

// 2. 排序函数（奇偶排序，极力推荐！）
bool cmp_oddeven(const Query& x, const Query& y) {
    if (x.l / block != y.l / block) {
        return x.l / block < y.l / block; // 第一关键字：L所在的块
    }
    // 第二关键字：奇数块升序，偶数块降序
    if ((x.l / block) & 1) return x.r < y.r; 
    else return x.r > y.r;
}

// （备用）常规排序（最容易懂的写法）
bool cmp_standard(const Query& x, const Query& y) {
    if (x.l / block != y.l / block) {
        return x.l / block < y.l / block;
    }
    return x.r < y.r;
}

// 3. 扩大区间时的状态转移（根据题目逻辑修改）
inline void add(int pos) {
    if (cnt[a[pos]] == 0) {
        current_ans++; // 如果加入前数量为0，说明出现了一个新数字
    }
    cnt[a[pos]]++;
}

// 4. 缩小区间时的状态转移（根据题目逻辑修改）
inline void del(int pos) {
    cnt[a[pos]]--;
    if (cnt[a[pos]] == 0) {
        current_ans--; // 如果移出后数量为0，说明少了一种数字
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return; // 应对多组输入

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 设定块的大小，通常设定为 sqrt(N)
    block = max(1.0, sqrt(n)); 
    // 注：若 N 和 M 差距极大，理论最优块大小是 max(1.0, n / sqrt(m))

    q.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i; // 记录原始查询顺序
    }

    // 将查询数组进行排序 (下标从1开始到m结束)
    sort(q.begin() + 1, q.begin() + 1 + m, cmp_oddeven);

    // 5. 初始化双指针（极其重要：设置为一个空区间）
    int l = 1, r = 0; 
    current_ans = 0;
    // 注意：如果需要多组测试数据清空，还要 memset(cnt, 0, sizeof(cnt));

    // 6. 执行莫队主循环
    for (int i = 1; i <= m; i++) {
        int ql = q[i].l;
        int qr = q[i].r;
        int id = q[i].id;

        // 核心：先扩大（add），再缩小（del）
        // 前缀自减、前缀自加、后缀自增、后缀自减千万别写错！
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (l < ql) del(l++);
        while (r > qr) del(r--);

        // 记录离线答案
        ans[id] = current_ans;
    }

    // 7. 按原顺序输出答案
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```





### 双堆维护中位数

```c++
struct MedianFinder {
    priority_queue<ll> maxp;                          // 大根堆，存较小的一半（含中位数）
    priority_queue<ll, vector<ll>, greater<ll>> minp;  // 小根堆，存较大的一半

    unordered_map<ll,int> delMax, delMin; // 分别记录两个堆各自"待懒删除"的值及次数
    ll szMax = 0, szMin = 0;              // 两个堆各自的真实（未被删除）元素个数

    // 清理 maxp 堆顶已经被标记删除的元素
    void cleanMax(){
        while(!maxp.empty()){
            auto it = delMax.find(maxp.top());
            if(it == delMax.end() || it->second == 0) break;
            it->second--;
            maxp.pop();
        }
    }
    // 清理 minp 堆顶已经被标记删除的元素
    void cleanMin(){
        while(!minp.empty()){
            auto it = delMin.find(minp.top());
            if(it == delMin.end() || it->second == 0) break;
            it->second--;
            minp.pop();
        }
    }

    // 根据真实计数 szMax / szMin 重新调整平衡
    void rebalance(){
        while(szMax > szMin + 1){
            cleanMax();
            minp.push(maxp.top()); maxp.pop();
            szMax--; szMin++;
        }
        while(szMin > szMax){
            cleanMin();
            maxp.push(minp.top()); minp.pop();
            szMin--; szMax++;
        }
        cleanMax(); cleanMin();
    }

    // 插入一个数
    void add(ll x){
        cleanMax();
        if(maxp.empty() || x <= maxp.top()){ maxp.push(x); szMax++; }
        else { minp.push(x); szMin++; }
        rebalance();
    }

    // 删除一个数（要求这个数确实存在于结构中，否则计数会出错）
    void erase(ll x){
        cleanMax(); cleanMin();
        if(!maxp.empty() && x <= maxp.top()){
            delMax[x]++; szMax--;   // 逻辑上认为 x 属于"较小的一半"
        } else {
            delMin[x]++; szMin--;   // 属于"较大的一半"
        }
        cleanMax(); cleanMin();      // 如果刚好在堆顶，立刻顺手清掉
        rebalance();
    }

    ll size() const {
        return szMax + szMin;
    }

    bool empty() const {
        return size() == 0;
    }

    // 中位数为浮点数版本（总数为偶数时取两堆堆顶均值）
    double getMedian(){
        cleanMax(); cleanMin();
        if(szMax > szMin) return (double)maxp.top();
        return (maxp.top() + minp.top()) / 2.0;
    }

    // 中位数保证是整数时使用
    ll getMedianInt(){
        cleanMax(); cleanMin();
        if(szMax > szMin) return maxp.top();
        return (maxp.top() + minp.top()); // 需要 /2 的话自行调整
    }

    // 若元素个数为偶数，分别取两个中位数（下中位数、上中位数）
    pair<ll,ll> getTwoMedians(){
        cleanMax(); cleanMin();
        // 调用前需保证 size() 为偶数且 size() > 0
        return {maxp.top(), minp.top()};
    }
};
```



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



# 值得注意的坑

##### sqrt(n)的浮点误差

**用 `sqrt()`（浮点数）直接当数组下标，存在精度问题**

`sqrt(r)` 返回的是 `double`，对于完全平方数，浮点误差可能导致：

- `sqrt(100000000)` 算出 `9999.99999999...`，被截断成 `9999` 而不是 `10000`，少算一个；

```c++
ll isqrt(ll x){
    ll r = (ll)sqrtl((long double)x);
    while (r > 0 && r*r > x) r--;
    while ((r+1)*(r+1) <= x) r++;
    return r;
}
```



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
//必须先排序
auto last = unique(a.begin(),a.end());
a.erase(last,a.end()); //配合vector::erase s
a.erase(unique(a.begin(), a.end()), a.end()); /


//用endl再极端情况下可能会TLE,建议直接使用'\n'   
//或者直接 #define endl '\'
    
//row+i 表示同一副对角线
//row-i 表示同一主对角线  因为会出现负值，所以我们通常会加一个常数，
   //row-i+n
cout <<fixed<< setprecision(8) << value << endl; // 改成8精度

//整数向上取整可以 (a+b-1)/b

对于矩阵中的任意2*2子块，想要其合为合数，只需顺序填入值
    


//对于一个矩阵有一点(r,c),顺时针旋转后为(c,len-1-r),逆时针旋转后为(len-1-c,r),len为矩阵边长
//当然这里的坐标是相对坐标并不是全局坐标，即左上角为(0,0)
    
勾股数的构造：给定一个数x，满足x^2+y^2=z^2;
if(x&1){
	y = (x*x)/2;
	z = (x*x+1)/2;
}else{
    y = (x*x)/4-1;
    z = (x*x)/4+1;
}

//读数据时内容中含有空格等制表符不能用cin，要用getline(cin,s);
//一个长度为n的字符串能产生n(n+1)/2个子串
//对于二维前缀和
pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + vec[i][j];
//对于其局部，当左上角坐标为(i,j),右下角为(ii,jj)时
sum = pre[ii][jj] - pre[i-1][jj] - pre[ii][j-1] + pre[i-1][j-1];

在 1e7 的数据范围内，相邻质数的最大间隙只有 154
```



## 图论

1. 对于任何森林（没有环的图），连通块数量  C 满足 $c = deg[u] - deg[v] - 1 - is\_adj(u,v)$ 其中 $$is\_adj(u,v)$$ 表示u和v是否为连边，是则为1，反之为0；

2. 对树上任意三个点 $u,v,w$ ，一定存在唯一一个点 $m$（**可能是 $u,v,w$之一，也可能是中间的某个点**），使得从 $m$ 出发有三条互不相交的"手臂"分别通向 $u,v,w$ 。这个 $m$ 就叫**中位点**



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



`std::transform`(<algorithm>)  复杂度:$O(n)$ ,因为底层由`for`循环实现 

```c++
//第一种用法：一元操作（处理单个区间）
//这是最常用的情况：将一个区间里的每个元素，经过某种转换后，存入目标区间。
//transform(起始迭代器1, 结束迭代器1, 目标起始迭代器, 一元操作函数);
transform(s.begin(),s.end(),s.begin(),::toupper);//将字符串从开始到结尾的字符全都转换为大写，再存回s；::tolower,可转换为小写，注意都是::,而并非是std::

//第二种用法：二元操作，可结合lambda使用
//transform(起始1, 结束1, 起始2, 目标起始, 二元操作函数);
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5, 6};

// 提前分配好结果数组的空间！
vector<int> res(3);

// 将 a 和 b 对应位置相加，结果存入 res
// std::plus<int>() 是标准库提供的一个仿函数，等价于返回 x + y
transform(a.begin(), a.end(), b.begin(), res.begin(), plus<int>());
//transform(a.begin(), a.end(), b.begin(), res.begin(), [](int x,int y){
//   return x+y;
//});
//若不想提前分配空间，可在目标起始填入 std::back_inserter(res)
for(auto x:res){
   cout<<x<<" ";
}
```




#自己的小壁画
在递归的过程中，例如dfs，在进行`for(auto v : adj[u])`的过程中，在for内部是对u的孩子节点进行操作的，而在for循环结束后则是对所有孩子节点给出的信息进行操作，这点在树上dp的时候要注意