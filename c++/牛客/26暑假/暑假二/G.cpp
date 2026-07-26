#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
// 预处理 10^7 以内的素数
const ll N = 1e7+7;

vector<ll> prim;
vector<bool> vis(N+1, 0); 

// 线性筛 (欧拉筛) 预处理素数
void init() {
    vis[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) prim.push_back(i);

        for (int j = 0; j < prim.size(); j++) {
            ll p = prim[j];
            if (p * i > N) break;
            vis[p * i] = true;
            // 保证每个合数只被其最小素因子筛掉，达到 O(N) 复杂度
            if (i % p == 0) {
                break;
            }
        }
    }
}

// 容斥原理：计算区间 [1, X] 内与 n 互质的数的个数
// p_factors 是 n 的所有不同质因子
ll count_coprime(ll X, const vector<ll>& p_factors) {
    if (X == 0) return 0;
    ll res = 0;
    int k = p_factors.size();
    
    // 利用二进制状态压缩枚举质因数的所有组合子集
    // mask 的第 i 位为 1，表示选中了第 i 个质因子
    for (int mask = 0; mask < (1 << k); mask++) {
        ll prod = 1;
        int bits = 0; // 记录当前子集包含了几个质因子
        
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                prod *= p_factors[i];
                bits++;
            }
        }
        
        // 容斥核心逻辑：奇数个质因子的交集做减法，偶数个做加法
        if (bits % 2 == 1) res -= X / prod;
        else res += X / prod;
    }
    return res; // 返回最终与 n 互质的数的个数
}

void solve()
{
    ll l, r, n;
    cin >> l >> r >> n;
    ll ans = 0;
    ll p = 0;
    
    // 找到小于等于 n 的最大素数 p
    // 核心结论：对于所有 i <= p，因为 gcd(p, n) = 1 且 gcd(i, p) = 1 (当 i < p)
    // 总是存在中转路径 i -> p -> n，总代价为 1 + 1 = 2。
    // 因此对于 i <= p，到 n 的最短路最多就是 2 (即 min(gcd(i, n), 2))。
    for (int i = prim.size() - 1; i >= 0; i--) {
        if (prim[i] <= n) {
            p = prim[i];
            break;
        }
    }
    
    // 分解 n 的质因数，用于后面的容斥原理计算
    ll t = n;
    vector<ll> vec;
    for (int i = 2; i * i <= n; i++) {
        if (t % i == 0) {
            vec.push_back(i);
            while (t % i == 0) t /= i;
        }
    }
    // 不要忘记把最后剩下的大于 sqrt(n) 的素因子也加进去
    if (t > 1) vec.push_back(t);

    // 情况 1：查询区间的右端点 r 还在最大素数 p 的左边
    // 整个区间内的答案都可以直接用 min(gcd(i, n), 2) 的数学性质批量计算
    if (p >= r) {
        // 求出 [l, r] 区间内与 n 互质的数的个数 (代价为 1)
        ll cnt = count_coprime(r, vec) - count_coprime(l - 1, vec);
        // 不互质的代价为 2，互质的代价为 1。
        // 总代价 = 全部当成代价 2 算 - 互质的个数 (因为互质的只花 1 的代价，相当于多算了 1)
        ans = (r - l + 1) * 2 - cnt;
    } 
    // 情况 2：查询区间包含了大于 p 的部分
    else {
        // 第一部分：处理 <= p 的左半区间 (与情况 1 逻辑一致)
        if (l <= p) {
            ll cnt = count_coprime(p, vec) - count_coprime(l - 1, vec);
            ans = (p - l + 1) * 2 - cnt;
        }
        
        // 第二部分：处理 > p 的右半区间。
        // 因为相邻素数间隙很小 (10^7 内最大间隙 154)，所以用 DP 暴力求最短路
        int len = n - p; 
        vector<ll> dp(len + 1, INF); // dp[i] 表示从节点 (p + i) 走到 n 的最小代价
        dp[len] = 0; // 节点 n 到自身的代价为 0
        
        // 从大到小倒推，因为只能从小节点向大节点走
        for (int i = len - 1; i >= 1; i--) {
            ll u = p + i;
            dp[i] = gcd(u, n); // 策略 1：不经过任何中转，直接从 u 走到 n
            
            // 策略 2：枚举所有比 u 大的中转点 v (v 在 u 和 n 之间)
            for (int j = i + 1; j < len; j++) {
                ll v = p + j;
                // 状态转移方程：当前代价 vs (u走到v的代价 + v走到n的最短代价)
                dp[i] = min(dp[i], gcd(u, v) + dp[j]);
            }
        }
        
        // 将查询范围 [max(p + 1, l), r] 对应的 DP 结果累加进答案
        // 注意下标偏移：真实节点 i 对应 DP 数组下标为 i - p
        for (ll i = max(p + 1LL, l); i <= r; i++) {
            ans += dp[i - p];
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}