#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define endl '\n'

struct SegTree {
    int n;

    vector<int> cnt;
    vector<int> tag;

    SegTree(const string &s) {
        n = (int)s.size() - 1;

        cnt.resize(4 * n + 5);
        tag.assign(4 * n + 5, -1);

        build(1, 1, n, s);
    }

    void pull(int o) {
        cnt[o] = cnt[o << 1] + cnt[o << 1 | 1];
    }

    void apply(int o, int l, int r, int v) {
        cnt[o] = v * (r - l + 1);
        tag[o] = v;
    }

    void push(int o, int l, int r) {
        if (tag[o] == -1 || l == r)
            return;

        int mid = (l + r) >> 1;

        apply(o << 1, l, mid, tag[o]);
        apply(o << 1 | 1, mid + 1, r, tag[o]);

        tag[o] = -1;
    }

    void build(
        int o,
        int l,
        int r,
        const string &s
    ) {
        if (l == r) {
            cnt[o] = (s[l] == 'H');
            return;
        }

        int mid = (l + r) >> 1;

        build(o << 1, l, mid, s);
        build(o << 1 | 1, mid + 1, r, s);

        pull(o);
    }

    // 区间全部赋成 v
    void assignRange(int ql, int qr, int v) {
        if (ql > qr)
            return;

        assignRange(
            1, 1, n,
            ql, qr, v
        );
    }

    void assignRange(
        int o,
        int l,
        int r,
        int ql,
        int qr,
        int v
    ) {
        if (ql <= l && r <= qr) {
            apply(o, l, r, v);
            return;
        }

        push(o, l, r);

        int mid = (l + r) >> 1;

        if (ql <= mid)
            assignRange(
                o << 1,
                l, mid,
                ql, qr,
                v
            );

        if (qr > mid)
            assignRange(
                o << 1 | 1,
                mid + 1, r,
                ql, qr,
                v
            );

        pull(o);
    }

    bool has(
        int o,
        int l,
        int r,
        int v
    ) {
        if (v == 1)
            return cnt[o] > 0;

        return cnt[o] < r - l + 1;
    }

    // [ql,qr] 中最靠左的 v
    int findFirst(
        int ql,
        int qr,
        int v
    ) {
        if (ql > qr)
            return -1;

        return findFirst(
            1, 1, n,
            ql, qr, v
        );
    }

    int findFirst(
        int o,
        int l,
        int r,
        int ql,
        int qr,
        int v
    ) {
        if (
            r < ql ||
            qr < l ||
            !has(o, l, r, v)
        )
            return -1;

        if (l == r)
            return l;

        push(o, l, r);

        int mid = (l + r) >> 1;

        int res = findFirst(
            o << 1,
            l, mid,
            ql, qr,
            v
        );

        if (res != -1)
            return res;

        return findFirst(
            o << 1 | 1,
            mid + 1, r,
            ql, qr,
            v
        );
    }

    // [ql,qr] 中最靠右的 v
    int findLast(
        int ql,
        int qr,
        int v
    ) {
        if (ql > qr)
            return -1;

        return findLast(
            1, 1, n,
            ql, qr, v
        );
    }

    int findLast(
        int o,
        int l,
        int r,
        int ql,
        int qr,
        int v
    ) {
        if (
            r < ql ||
            qr < l ||
            !has(o, l, r, v)
        )
            return -1;

        if (l == r)
            return l;

        push(o, l, r);

        int mid = (l + r) >> 1;

        int res = findLast(
            o << 1 | 1,
            mid + 1, r,
            ql, qr,
            v
        );

        if (res != -1)
            return res;

        return findLast(
            o << 1,
            l, mid,
            ql, qr,
            v
        );
    }

    // 把 [ql,qr] 的每一位取出来
    // 按下标从小到大
    void collect(
        int ql,
        int qr,
        vector<int> &vec
    ) {
        collect(
            1, 1, n,
            ql, qr,
            vec
        );
    }

    void collect(
        int o,
        int l,
        int r,
        int ql,
        int qr,
        vector<int> &vec
    ) {
        if (r < ql || qr < l)
            return;

        if (l == r) {
            vec.push_back(cnt[o]);
            return;
        }

        push(o, l, r);

        int mid = (l + r) >> 1;

        collect(
            o << 1,
            l, mid,
            ql, qr,
            vec
        );

        collect(
            o << 1 | 1,
            mid + 1, r,
            ql, qr,
            vec
        );
    }

    // 把 vec 写回 [ql,qr]
    void write(
        int ql,
        int qr,
        const vector<int> &vec
    ) {
        int idx = 0;

        write(
            1, 1, n,
            ql, qr,
            vec, idx
        );
    }

    void write(
        int o,
        int l,
        int r,
        int ql,
        int qr,
        const vector<int> &vec,
        int &idx
    ) {
        if (r < ql || qr < l)
            return;

        if (l == r) {
            apply(
                o, l, r,
                vec[idx++]
            );
            return;
        }

        push(o, l, r);

        int mid = (l + r) >> 1;

        write(
            o << 1,
            l, mid,
            ql, qr,
            vec, idx
        );

        write(
            o << 1 | 1,
            mid + 1, r,
            ql, qr,
            vec, idx
        );

        pull(o);
    }

    string getAns() {
        string ans(n + 1, 'N');

        getAns(
            1, 1, n,
            ans
        );

        return ans.substr(1);
    }

    void getAns(
        int o,
        int l,
        int r,
        string &ans
    ) {
        if (l == r) {
            ans[l] = cnt[o]
                ? 'H'
                : 'N';

            return;
        }

        push(o, l, r);

        int mid = (l + r) >> 1;

        getAns(
            o << 1,
            l, mid,
            ans
        );

        getAns(
            o << 1 | 1,
            mid + 1, r,
            ans
        );
    }
};

void solve() {
    int n, T;
    cin >> n >> T;

    string s;
    cin >> s;

    s = " " + s;

    SegTree st(s);

    const ull MASK =
        (1ULL << 60) - 1;

    // 从 q 开始，沿 dir 做 +1
    auto plusOne =
    [&](int q, int dir) {

        // 向右
        if (dir == 1) {
            int pos =
                st.findFirst(
                    q, n, 0
                );

            // 后面全是 1
            if (pos == -1) {
                st.assignRange(
                    q, n, 0
                );
            }
            else {
                st.assignRange(
                    q, pos, 0
                );

                st.assignRange(
                    pos, pos, 1
                );
            }
        }

        // 向左
        else {
            int pos =
                st.findLast(
                    1, q, 0
                );

            if (pos == -1) {
                st.assignRange(
                    1, q, 0
                );
            }
            else {
                st.assignRange(
                    pos, q, 0
                );

                st.assignRange(
                    pos, pos, 1
                );
            }
        }
    };

    // 从 q 开始，沿 dir 做 -1
    auto minusOne =
    [&](int q, int dir) {

        if (dir == 1) {
            int pos =
                st.findFirst(
                    q, n, 1
                );

            // 后面全是 0
            if (pos == -1) {
                st.assignRange(
                    q, n, 1
                );
            }
            else {
                st.assignRange(
                    q, pos, 1
                );

                st.assignRange(
                    pos, pos, 0
                );
            }
        }

        else {
            int pos =
                st.findLast(
                    1, q, 1
                );

            if (pos == -1) {
                st.assignRange(
                    1, q, 1
                );
            }
            else {
                st.assignRange(
                    pos, q, 1
                );

                st.assignRange(
                    pos, pos, 0
                );
            }
        }
    };

    while (T--) {
        int op, p;
        ull k;

        cin >> op >> p >> k;

        if (k == 0)
            continue;

        // 方向
        int dir =
            (op <= 2)
            ? 1
            : -1;

        // 加还是减
        bool add =
            (op == 1 || op == 3);

        // 总共有多少位
        int m =
            (dir == 1)
            ? n - p + 1
            : p;

        // 只处理最低 60 位
        int L = min(m, 60);

        int l, r;

        if (dir == 1) {
            l = p;
            r = p + L - 1;
        }
        else {
            l = p - L + 1;
            r = p;
        }

        vector<int> bits;
        bits.reserve(L);

        st.collect(
            l, r,
            bits
        );

        // 转成整数
        ull x = 0;

        if (dir == 1) {
            // p 是 bit0
            for (int i = 0; i < L; i++) {
                if (bits[i])
                    x |= 1ULL << i;
            }
        }
        else {
            // p 是 bit0
            for (int i = 0; i < L; i++) {
                if (bits[L - 1 - i])
                    x |= 1ULL << i;
            }
        }

        ull y;
        bool carry = false;

        // 整个数字只有 <= 60 位
        if (m <= 60) {
            ull mask =
                (1ULL << m) - 1;

            if (add)
                y = (x + k) & mask;
            else
                y = (x - k) & mask;
        }

        // 后面还有高位
        else {
            if (add) {
                ull z = x + k;

                y = z & MASK;

                carry =
                    (z >> 60) & 1;
            }
            else {
                // 是否借位
                carry = (x < k);

                y =
                    (x - k) & MASK;
            }
        }

        // 转回字符串
        vector<int> newBits(L);

        if (dir == 1) {
            for (int i = 0; i < L; i++) {
                newBits[i] =
                    (y >> i) & 1;
            }
        }
        else {
            for (int i = 0; i < L; i++) {
                newBits[L - 1 - i] =
                    (y >> i) & 1;
            }
        }

        st.write(
            l, r,
            newBits
        );

        // 向第 61 位传播一次
        if (m > 60 && carry) {
            int q =
                p + dir * 60;

            if (add)
                plusOne(q, dir);
            else
                minusOne(q, dir);
        }
    }

    cout << st.getAns()
         << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}