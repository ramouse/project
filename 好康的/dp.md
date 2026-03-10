# 基础dp



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

# 背包dp





### 01背包

由于每个物体只有两种可能的状态（取与不取），对应二进制中的 0![0](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 和 1![1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7)，这类问题便被称为「0-1 背包问题」

#### 解释

若已知条件有第i个物品的重量(或代价)$w_i$,价值$v_i$,以及背包的总容量W

设dp状态$f_{i,j}$为在只放前i的物品的情况下，背包容量剩余j所能到达的最大价值

考虑转移，假设当前已经处理好前 i-1 个物品的状态，那么对于第 i 个物品，当其不放入背包时，背包剩余容量不变，总价值也不变，这种情况下的最大价值就是 $f_{i-1,j}$ ;当放入背包时，背包容量减少 $w_i$,背包价值增加$v_i$,所以这种情况下的最大价值为 $f_{i-1,j-w_i}+v_i$ 

所以状态转移方程为 $f_{i,j} = max(f_{i-1,j},f_{i-1,j-w_i}+v_i)$

当然还可以进行优化，由于对$f_i$有影响的只有$f_{i-1}$,所以可以去掉第一维，直接用$f_i$来表示处理到当前物品时的背包容量为 i 时所能达到的最大价值，故得出以下方程：

​							       $f_j = max(f_{j-1},f_{j-w_i}+v_i)$



核心代码如下：

```c++
 for (int i = 1; i <= n; i++)
    {
        for (int j = W; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans;
```

从后往前遍历，是为了防止可能出现一个物品多次装入