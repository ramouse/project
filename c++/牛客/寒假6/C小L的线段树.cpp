#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MAXN = 1e6+5;
ll tree[MAXN*4];
ll tag[MAXN*4];
ll val[MAXN*4];

void push_up(ll p,ll l,ll r) {
    if(tag[p]){
        if(l == r) val[p] =0;
        else val[p] = val[p<<1] + val[p<<1 | 1];
    }else{
        val[p] = 1;
    }
}

void build(ll p, ll l, ll r) {
    tag[p] = 0;
    val[p] = 1;
    if (l == r) {
        return;
    }
    ll mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void update(ll p,ll l,ll r,ll tl,ll tr){
    if(l == tl && r == tr){
        tag[p] = 1;
        push_up(p,l,r);
        return;
    }

    ll mid = (l + r) >> 1;
    if(tr <= mid) update(p<<1,l,mid,tl,tr);
    else if(tl > mid) update(p<<1 | 1,mid + 1,r,tl,tr);
    push_up(p,l,r);
}

ll qurrey(ll p,ll l,ll r,ll tl,ll tr){
    if (l > tr || r < tl) return 0;
    ll res = 0;
    if(tl<=l && r<=tr){
        return val[p];
    }else{
        if (tag[p] == 0)
        {
            res += 1;
        }
        
        ll mid = (l + r) >> 1;
        res += qurrey(p << 1, l, mid, tl, tr);
        res += qurrey(p << 1 | 1, mid + 1, r, tl, tr);

    }
    return res;
}

int main(){
    ll n;
    cin>>n;
    build(1,1,n);
    ll t= n;
    while(t--){
        int o;
        cin>>o;
        if(o == 1){
            ll l,r;
            cin>>l>>r;
            update(1,1,n,l,r);
        }else{
            ll l,r;
            cin>>l>>r;
            cout<<qurrey(1,1,n,l,r)<<endl;
        }
    }

    return 0;
}