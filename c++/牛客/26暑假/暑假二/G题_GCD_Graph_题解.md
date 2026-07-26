# G 题 - 最大公约数图（GCD Graph）

## 题目大意

有一个由所有正整数 $1, 2, 3, \ldots$ 构成的有向图。对于每对 $i < j$，存在一条从 $i$ 到 $j$、权值为 $\gcd(i, j)$ 的边。

记 $cost(u, v)$ 为从 $u$ 到 $v$ 的最短路径总代价。求：

$$\sum_{i = l}^{r} cost(i, n)$$

- $1 \leq l \leq r < n \leq 10^7$
- 多组询问，$T \leq 100$

---

## 核心观察

### 观察 1：最短路不超过 2

如果存在一个质数 $p$ 满足 $u < p < v$，那么：

$$cost(u, v) \leq \gcd(u, p) + \gcd(p, v)$$

即可以通过 $u \to p \to v$ 走两步。$\gcd(u, p)$ 和 $\gcd(p, v)$ 都较小。

实际上，由于质数的特殊性（与其他数的 gcd 通常为 1），在大多数情况下 $cost(u, v) \leq 2$。

### 观察 2：质数分布的密度

在 $10^7$ 范围内，相邻质数之间的最大间距不超过 $150$。

因此我们可以找到 $\leq r$ 的最大质数 $p_0$，将区间 $[l, r]$ 分成两部分处理。

### 观察 3：$cost = 1$ 的条件

$cost(x, n) = 1$ 当且仅当存在一条直接的边 $x \to n$，即 $\gcd(x, n) > 0$。实际上就是 $x$ 直接通过边走到 $n$。

等等，重新审视：图中边权 $\gcd(i, j)$ 可以很大。要判断最短路是否为 1，即能否直接从 $x$ 走到 $n$。这是当然可以的（因为 $x < n$，总有一条 $x \to n$ 的边），代价就是 $\gcd(x, n)$。

但题解说 "$dis(x, n)$ 等于 1 当且仅当 $x$ 和 $n$ 互质"，这实际上意味着：

> 如果 $\gcd(x, n) = 1$（互质），那么边权为 $1$，直接走这条边就是最短路径（代价 $1$）。

如果有公共因子，边权 $> 1$，可能需要绕路。关键是：借助质数中转，代价通常不超过 2。

### 更精确的理解

对于 $x \in [l, r]$：
- 若 $\gcd(x, n) = 1$：直接走 $x \to n$，代价 $1$
- 否则：可以走 $x \to p \to n$，其中 $p$ 是介于 $x$ 和 $n$ 之间的某个质数（代价 $= \gcd(x, p) + \gcd(p, n)$，通常就是 $1+1=2$ 或更小）
- 对于 $x \geq p_0$（即 $r$ 到小于它的最大质数之间的部分）：由于范围很小（$\leq 150$），直接 DP 求解

---

## 算法

### 第一部分：$[l, p_0)$（$p_0$ 为 $\leq r$ 的最大质数）

对于这些 $x$，$cost(x, n) \leq 2$。$cost(x, n) = 1$ 当且仅当 $\gcd(x, n) = 1$。

所以：
- 互质的 $x$ 贡献 $1$
- 不互质的 $x$ 贡献 $2$

互质的个数可以用**容斥原理**计算：
- 设 $n$ 的质因子集合为 $\{q_1, q_2, \ldots, q_k\}$
- 区间 $[l, p_0)$ 中与 $n$ 互质的数的个数 = 总个数 - 能被某个 $q_i$ 整除的个数 + 能被某两个 $q_i, q_j$ 同时整除的个数 - ...

$$count_{coprime} = \sum_{mask} (-1)^{popcount(mask)} \cdot \left\lfloor\frac{p_0 - 1}{\prod_{i \in mask} q_i}\right\rfloor - \left\lfloor\frac{l - 1}{\prod_{i \in mask} q_i}\right\rfloor$$

$n \leq 10^7$ 的质因子个数不超过 $8$（$2 \times 3 \times 5 \times 7 \times 11 \times 13 \times 17 \times 19 > 10^7$），所以容斥枚举 $2^k \leq 256$ 种情况即可。

区间贡献 = $count_{coprime} \times 1 + (total - count_{coprime}) \times 2$

### 第二部分：$[\max(l, p_0), r]$

范围很小（$\leq 150$），直接用 DP：
- $dp[i]$ 表示从 $i$ 出发到 $n$ 的最短路径代价
- $dp[n] = 0$
- 从大到小转移：$dp[u] = \min_{v = u+1}^{n} (dp[v] + \gcd(v, u))$

每个 $dp[u]$ 需要 $\mathcal{O}(n-u)$ 的枚举，范围最多 $150$。

---

## 复杂度

- 容斥部分：$\mathcal{O}(2^{\text{prime\_factor\_count}(n)})$，最多 $2^8 = 256$
- DP 部分：$\mathcal{O}(\text{prime\_gap}^2)$，最多 $150^2 = 22500$
- 有 $T \leq 100$ 组询问
- 但注意预处理 $n$ 的质因子只需要一次

总体可行。

---

## 举例说明

### 例 1：$l=1, r=5, n=6$

$n=6=2\times3$，质因子 $\{2,3\}$。

$r=5$，小于等于 $5$ 的最大质数是 $p_0 = 5$。

第一部分 $[1, 5)$（即 $1$ 到 $4$）：
- 总个数 $4$
- 与 $6$ 互质的数（容斥）：$[1,4]$ 中不被 $2$ 或 $3$ 整除的数
  - 总数 $4$
  - 被 $2$ 整除：$2,4$ → $2$ 个
  - 被 $3$ 整除：$3$ → $1$ 个
  - 被 $6$ 整除：无
  - 互质个数 = $4 - 2 - 1 + 0 = 1$（即 $\{1\}$）
- 贡献 = $1 \times 1 + 3 \times 2 = 7$

第二部分 $[5, 5]$：
- $dp[5] = dp[6] + \gcd(5,6) = 0 + 1 = 1$
- 贡献 = $1$

总和 = $7 + 1 = 8$ ✅

---

## 参考代码框架

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prime_factors(int n) {
    vector<int> res;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            res.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

int largest_prime_le(int x) {
    // 埃氏筛预处理或直接枚举判断
    for (int p = x; p >= 2; p--) {
        bool is_p = true;
        for (int d = 2; d * d <= p; d++)
            if (p % d == 0) { is_p = false; break; }
        if (is_p) return p;
    }
    return 2;
}

ll count_coprime(ll l, ll r, const vector<int>& primes) {
    int k = primes.size();
    ll total = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        ll prod = 1;
        int bits = 0;
        for (int i = 0; i < k; i++)
            if (mask >> i & 1)
                prod *= primes[i], bits++;
        ll cnt = r / prod - (l - 1) / prod;
        total += (bits & 1) ? -cnt : cnt;
    }
    return total;
}

void solve() {
    ll l, r, n;
    cin >> l >> r >> n;

    auto pf = prime_factors(n);
    ll p0 = largest_prime_le(r);
    ll ans = 0;

    if (l < p0) {
        ll cnt = count_coprime(l, p0 - 1, pf);
        ll total = (p0 - 1) - l + 1;
        ans += cnt * 1 + (total - cnt) * 2;
    }

    // 剩余部分 DP
    int gap = r - max(l, p0) + 1;
    if (gap > 0) {
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int u = n - 1; u >= max(l, p0); u--) {
            for (int v = u + 1; v <= n; v++)
                dp[u] = min(dp[u], dp[v] + __gcd(v, u));
        }
        for (int i = max(l, p0); i <= r; i++)
            ans += dp[i];
    }

    cout << ans << '\n';
}
```
