#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> p(n+1,0);
    map<ll, ll> pos;
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        pos[p[i]] = i;
    }

    vector<ll> ma(4 * n + 1,0);
    vector<ll> mi(4 * n + 1,0);

    auto pushup = [&](ll idx) -> void{
        ma[idx] = max(ma[idx<<1],ma[idx<<1 | 1]);
        mi[idx] = min(mi[idx<<1],mi[idx<<1 | 1]);
    };

    auto bulid = [&](auto &&self,ll l,ll r,ll idx) -> void{
        if(l == r){
            ma[idx] = mi[idx] = p[l];
            return;
        }

        ll mid = (l + r) >> 1;
        self(self,l,mid,idx<<1);
        self(self,mid+1,r,idx<<1 | 1);
        pushup(idx);
    };

    auto update = [&](auto &&self,ll l,ll r,ll idx,ll x) -> void{
        if(l == r){
            ma[idx] = mi[idx] = p[l];
            return;
        }

        ll mid = (l+r)>>1;
        if(x <= mid) self(self,l,mid,idx<<1,x);
        if(x > mid) self(self,mid+1,r,idx<<1 | 1,x);
        pushup(idx);
    };

    auto quer_min = [&](auto &&self,ll l,ll r,ll ql,ll qr,ll idx) -> ll{
        if(ql <= l && r <= qr){
            return mi[idx];
        }

        ll res = INF;
        ll mid = (l + r)>>1;
        if(ql <= mid) res = min(res,self(self,l,mid,ql,qr,idx<<1));
        if(qr > mid) res = min(res,self(self,mid + 1,r,ql,qr,idx<<1 | 1));
        return res;
    };

    auto quer_max = [&](auto &&self,ll l,ll r,ll ql,ll qr,ll idx) -> ll{
        if(ql <= l && r <= qr){
            return ma[idx];
        }

        ll res = -INF;
        ll mid = (l + r)>>1;
        if(ql <= mid) res = max(res,self(self,l,mid,ql,qr,idx<<1));
        if(qr > mid) res = max(res,self(self,mid + 1,r,ql,qr,idx<<1 | 1));
        return res;
    };


    bulid(bulid,1,n,1);
    while(m--){
        ll l,r;
        cin>>l>>r;

        ll ma_val = quer_max(quer_max,1,n,l,r,1);
        ll mi_val = quer_min(quer_min,1,n,l,r,1);

        ll p1 = pos[ma_val];
        ll p2 = pos[mi_val];

        swap(p[p1], p[p2]);

        pos[ma_val] = p2;
        pos[mi_val] = p1;

        update(update, 1, n, 1, p1);
        update(update, 1, n, 1, p2);
    }

    for(int i = 1;i<=n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}