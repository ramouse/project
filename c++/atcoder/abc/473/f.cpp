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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll q;
    cin>>q;

    vector<ll> tree(4*n+1,0);
    vector<ll> tag(4*n + 1,0);

    auto pushup = [&](ll p) -> void{
        tree[p] = tree[p<<1] + tree[p<<1 | 1];
    };

    auto pushdown = [&](ll p,ll len) -> void{
        if(tag[p]){
            tag[p<<1] += tag[p];
            tag[p<<1 | 1] += tag[p];

            tree[p<<1] += tag[p] * (len - len/2);
            tree[p<<1 | 1] += tag[p] * (len/2);

            tag[p] = 0;
        }
    };

    auto update = [&](auto &&self,ll p,ll l,ll r,ll ql,ll qr,ll k) ->void{
        if(ql <= l && r<= qr){
            tree[p] += k * (r-l+1);
            tag[p] += k;
            return;
        }

        pushdown(p,r-l+1);
        ll mid = (l + r) >> 1;
        if(ql <= mid) self(self,p<<1,l,mid,ql,qr,k);
        if(qr>mid) self(self,p<<1 | 1,mid+1,r,ql,qr,k);
        pushup(p);
    };

    auto query = [&](auto &&self,ll p,ll l,ll r,ll ql,ll qr) -> bool{
        
    };

    while(q--){

    }
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