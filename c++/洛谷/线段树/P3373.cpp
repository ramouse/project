#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q >>m;
    vector<ll> a(n + 1, 0);
    vector<ll> tree(4 * n + 5, 0);
    vector<ll> t(4 * n + 5, 0);
    vector<ll> tt(4 * n + 5, 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    auto pushup = [&](ll p) -> void
    {
        tree[p] = (tree[p << 1] + tree[p << 1 | 1])%m;
        return;
    };

    auto pushdown = [&](ll p, ll len) -> void
    {
        if (tt[p] != 1)
        {
            tt[p << 1] = (tt[p] * tt[p << 1]) % m;
            tt[p << 1 | 1] = (tt[p] * tt[p << 1 | 1]) % m;

            t[p<<1] = (t[p<<1] * tt[p] ) % m;
            t[p<<1 | 1] = (t[p<<1 | 1] * tt[p]) % m;

            tree[p << 1] = (tree[p << 1] * tt[p]) % m;
            tree[p << 1 | 1] = (tree[p << 1 | 1] * tt[p]) % m;

            tt[p] = 1;
        }
        if (t[p] != 0)
        {
            t[p << 1] = (t[p<<1] + t[p]) % m;
            t[p << 1 | 1] =(t[p<<1 | 1] + t[p]) % m;

            tree[p << 1] = (tree[p<<1] + t[p] * (len - len / 2) % m) % m;
            tree[p << 1 | 1] = (tree[p<<1 | 1] + t[p] * (len / 2) % m) % m;

            t[p] = 0;
        }
    };

    auto build = [&](auto &&self, ll p, ll l, ll r) -> void
    {
        t[p] = 0;
        tt[p] = 1;
        if (l == r)
        {
            tree[p] = a[l]%m;
            return;
        }
        ll mid = (l + r) >> 1;
        self(self, p << 1, l, mid);
        self(self, p << 1 | 1, mid + 1, r);
        pushup(p);
        return;
    };

    auto upd = [&](auto &&self, ll p, ll l, ll r, ll tl, ll tr, ll k) -> void
    {
        if (tl <= l && r <= tr)
        {
            tree[p] = (tree[p] + k * (r - l + 1)) % m;
            t[p] = (t[p] + k) % m;
            return;
        }

        pushdown(p, r - l + 1);
        ll mid = (l + r) >> 1;
        if (tl <= mid)
            self(self, p << 1, l, mid, tl, tr, k);
        if (tr > mid)
            self(self, p << 1 | 1, mid + 1, r, tl, tr, k);
        pushup(p);
    };

    auto upd1 = [&](auto &&self, ll p, ll l, ll r, ll tl, ll tr, ll k) -> void
    {
        if (tl <= l && r <= tr)
        {
            tree[p] = (tree[p] * k) % m;
            tt[p] = (tt[p] * k)%m;
            t[p] = (t[p] * k) % m;
            return;
        }

        pushdown(p, r - l + 1);
        ll mid = (l + r) >> 1;
        if (tl <= mid)
            self(self, p << 1, l, mid, tl, tr, k);
        if (tr > mid)
            self(self, p << 1 | 1, mid + 1, r, tl, tr, k);
        pushup(p);
    };

    auto muery = [&](auto &&self, ll p, ll l, ll r, ll tl, ll tr)
    {
        if (tl <= l && r <= tr)
            return tree[p];

        pushdown(p, r - l + 1);
        ll mid = (l + r) >> 1;
        ll res = 0;
        if (tl <= mid)
            res = (res + self(self, p << 1, l, mid, tl, tr)) % m;
        if (tr > mid)
            res = (res + self(self, p << 1 | 1, mid + 1, r, tl, tr)) % m;
        return res;
    };

    build(build, 1, 1, n);

    while (q--)
    {
        int num;
        cin >> num;
        if(num == 1){
            ll x,y,k;
            cin>>x>>y>>k;
            upd1(upd1,1,1,n,x,y,k);
        }else 
        if (num == 2)
        {
            ll x, y, k;
            cin >> x >> y >> k;
            upd(upd, 1, 1, n, x, y, k);
        }
        else if(num == 3)
        {
            ll x, y;
            cin >> x >> y;
            cout << muery(muery, 1, 1, n, x, y) << endl;
        }
    }

    return 0;
}