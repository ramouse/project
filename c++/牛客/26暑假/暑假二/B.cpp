#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

// 线性基结构体
struct L {
    ll d[64];        // d[i] 存储最高有效位（主位）刚好为第 i 位的基元素
    bool has;        // 标记是否存在线性相关（即插入时出现冗余，能否组合出 0）
    set<ll> se;      // 记录插入的所有原始元素（可选，本题未实际使用）
    vector<ll> vec;  // 记录插入的所有原始元素（可选，本题未实际使用）

    L() {
        memset(d, 0, sizeof(d));
        has = false;
    }

    // 1. 将数值 x 插入线性基
    void insert(ll x) {
        se.insert(x);
        vec.push_back(x);
        for (int i = 62; i >= 0; i--) {
            if ((x >> i) & 1) { // 从最高位开始扫描 1
                if (!d[i]) {    // 如果第 i 位还没有基元素，直接填入
                    d[i] = x; 
                    return;  
                }
                x ^= d[i];      // 消去 x 的第 i 位上的 1，继续尝试插入低位
            }
        }
        has = true;             // x 被消成 0，说明存在线性相关性
    }

    // 2. 查询当前线性基能组合出的最大异或和
    ll query_max() {
        ll res = 0;
        for (int i = 62; i >= 0; i--) {
            // 贪心选择：如果异或 d[i] 能让结果变大，则进行异或
            if ((res ^ d[i]) > res) {
                res ^= d[i];
            }
        }
        return res;
    }

    // 3. 检查数值 x 能否由线性基中的元素异或组合得到
    bool check(ll x) {
        for (int i = 62; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!d[i]) return false; // 如果需要的基元素不存在，则无法组合
                x ^= d[i];           
            }
        }
        return x == 0; // 最终能消成 0 说明可以组合出来
    }
};

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    ll s = 0;

    // 读取输入并计算数组的全异或和 S
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s ^= a[i];
    }

    ll t = s;      // t 保存原始全异或和 S 的值
    s = (~s);      // s 取反生成掩码 mask：原 S 中为 0 的二进制位变 1，为 1 的位变 0

    L l;
    for (int i = 1; i <= n; i++) {
        // 关键操作：过滤掉原 S 中为 1 的位，只保留为 0 的位，然后插入线性基
        l.insert(a[i] & s);
    }

    // 计算最高得分：S + 2 * MaxXOR
    // t 表示原异或和必得的基础分，l.query_max() 表示在 S=0 的二进制位上争取到的最大进位得分
    cout << t + 2 * l.query_max() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}