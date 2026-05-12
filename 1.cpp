#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n, m, seed, v;
struct Node {
    ll l, r;
    mutable ll v;
    bool operator<(const Node& o) const { return l < o.l; }
};

set<Node> odt;

ll qpow(ll a,ll b,ll mod){
    ll res = 1;
    a=a%mod;
    while(b){
        if(b&1) res = res*a%mod;
        b/=2;
        a = a*a%mod;
    }
    return res;
}

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
        ll num = it->v;
        res = (res + (it->r - it->l + 1) * qpow(num,x,mod) % mod) % mod;
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
    cin>>n>>m>>seed>>v;
    vector<ll> a(n+1,0);
    auto rnd = [&](){
        ll res = seed;
        seed = (seed * 7 + 13) % 1000000007;
        return res;
    };
    for(int i = 1;i<=n;i++){
        a[i] = (rnd() % v) +1;
        odt.insert({i,i,a[i]});
    }

    for(int i = 1;i<=m;i++){
        ll op;
        op = (rnd()%4)+1;
        if(op==1){
            ll l,r,x;
            l = (rnd() % n)+1;
            r = (rnd() % n)+1;
            if(l>r) swap(l,r);
            x = (rnd() % v) + 1;
            range_add(l,r,x);
        }
        if(op==2){
            ll l,r,x;
            l = (rnd() % n) + 1;
            r = (rnd() % n) + 1;
            if (l > r) swap(l, r);
            x = (rnd() % v)+1;
            assign(l,r,x);
        }
        if(op==3){
            ll l,r,x;
            l = (rnd() % n) + 1;
            r = (rnd() % n) + 1;
            if (l > r) swap(l, r);

            x = (rnd() % (r-l+1)) +1;
            cout<<kth_smallest(l,r,x)<<endl;
        }
        if(op==4){
            ll l,r,x,y;
            l = (rnd() % n) + 1;
            r = (rnd() % n) + 1;
            if (l > r) swap(l, r);
            x = (rnd() % v) + 1;
            y = (rnd() % v) +1;
            cout<<range_sum(l,r,x,y)<<endl;
        }
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