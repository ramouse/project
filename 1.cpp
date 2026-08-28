#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct LeftistHeap {
    struct Node {
        int l = 0, r = 0;
        int dis = 1;
        int val = 0;
    };

    vector<Node> tr;

    LeftistHeap(int n = 0) {
        tr.resize(n + 1);
        tr[0].dis = 0;
    }

    int merge(int x, int y) {
        if (!x || !y)
            return x | y;

        // 大根堆
        if (tr[x].val < tr[y].val)
            swap(x, y);

        tr[x].r = merge(tr[x].r, y);

        if (tr[tr[x].l].dis < tr[tr[x].r].dis)
            swap(tr[x].l, tr[x].r);

        tr[x].dis = tr[tr[x].r].dis + 1;

        return x;
    }

    int pop(int x) {
        return merge(tr[x].l, tr[x].r);
    }
};

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // 原树父亲。
    // 实际算法不需要使用，只需要读掉。
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
    }

    /*
        每个约束对应一个左偏树节点，
        所以最多 q 个节点。
    */
    LeftistHeap hp(q + 5);

    vector<int> root(n + 1, 0);

    int tot = 0;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        ++tot;
        hp.tr[tot].val = v;
        hp.tr[tot].l = hp.tr[tot].r = 0;
        hp.tr[tot].dis = 1;

        root[u] = hp.merge(root[u], tot);
    }

    vector<int> fa(n + 1, 0);

    /*
        祖先编号一定更小，
        因此倒序处理。
    */
    for (int u = n; u >= 2; u--) {

        if (!root[u]) {
            // 没有任何额外要求，直接挂根上
            fa[u] = 1;
            continue;
        }

        int p = hp.tr[root[u]].val;

        // 最深的必须祖先直接作为父亲
        fa[u] = p;

        /*
            所有值为 p 的约束都已经满足，
            必须全部删掉。
        */
        while (root[u] && hp.tr[root[u]].val == p) {
            root[u] = hp.pop(root[u]);
        }

        /*
            剩余约束转移给 p：
            它们现在必须成为 p 的祖先。
        */
        root[p] = hp.merge(root[p], root[u]);

        root[u] = 0;
    }

    /*
        fa[u] 一定 < u，
        所以正序即可计算新树深度。
    */
    vector<ll> dep(n + 1, 0);

    ll ans = 0;

    for (int u = 2; u <= n; u++) {
        dep[u] = dep[fa[u]] + 1;
        ans += dep[u];
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}