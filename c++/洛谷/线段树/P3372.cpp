#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin>>n>>m;
    vector<ll> a(n+1,0);
    vector<ll> tree(4*n+5,0);
    vector<ll> t(4*n+5,0);

    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    auto pushup = [&](ll p) -> void{
        tree[p] = tree[p<<1] + tree[p<<1 | 1];
        return;
    };

    auto pushdown = [&](ll p,ll len) -> void{
        if(t[p]){
            t[p<<1] += t[p];
            t[p << 1 | 1] += t[p];

            tree[p << 1] += t[p] * (len - len / 2);
            tree[p << 1 | 1] += t[p] * (len / 2);

            t[p] = 0;
        }
    };

    auto build = [&](auto && self,ll p,ll l,ll r) -> void{
        t[p] = 0;
        if(l == r){
            tree[p] = a[l];
            return;
        }
        ll mid = (l+r)>>1;
        self(self,p<<1,l,mid);
        self(self,p<<1 | 1,mid+1,r);
        pushup(p);
        return;
    };

    auto upd = [&](auto &&self,ll p,ll l,ll r,ll tl,ll tr,ll k) -> void{
        if(tl<=l && r<=tr){
            tree[p] += k*(r-l+1);
            t[p] += k;
            return;
        }

        pushdown(p,r-l+1);
        ll mid = (l+r)>>1;
        if(tl<=mid) self(self,p<<1,l,mid,tl,tr,k);
        if(tr>mid) self(self,p<<1 | 1 ,mid+1,r,tl,tr,k);
        pushup(p);
    };

    auto query = [&](auto &&self,ll p,ll l,ll r,ll tl,ll tr){
        if(tl<=l && r<=tr) return tree[p];

        pushdown(p, r - l + 1); 
        ll mid = (l + r) >> 1;
        ll res = 0;
        if (tl <= mid)
            res += self(self,p << 1, l, mid, tl, tr);
        if (tr > mid)
            res += self(self,p << 1 | 1, mid + 1, r, tl, tr);
        return res;
    };

    build(build,1,1,n);

    while(m--){
        int num;
        cin>>num;
        if(num == 1){
            ll x,y,k;
            cin>>x>>y>>k;
            upd(upd,1,1,n,x,y,k);
        }else{
            ll x,y;
            cin>>x>>y;
            cout<<query(query,1,1,n,x,y)<<endl;
        }
    }

    return 0;
}