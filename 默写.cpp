#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e5;
ll tree[N];
ll a[N];
ll lowbit(ll x){
    return x&(-x);
}

void add(ll i,ll x){
    for(;i<=N;i+=lowbit(i)){
        tree[i]+=x;
    }
}

ll qurrey(ll i){
    ll sum = 0;
    for(;i>0;i-=lowbit(i)){
        sum+=tree[i];
    }
    return sum;
}

ll qu_range(ll l,ll r){
    return qurrey(r) - qurrey(l-1);
}

struct DSU{
    ll n;
    vector<ll> pare;
    vector<ll> size;
    ll count;
    DSU (ll n) : pare(n+1),size(n+1,1),count(n){
        iota(pare.begin(),pare.end(),0);
    }

    ll find(ll x){
        return pare[x] == x ? x : pare[x] = find(pare[x]);
    }

    bool merger(ll x,ll y){
        ll root_x = find(x);
        ll root_y = find(y);

        if(root_x == root_y) return false;

        if(size[root_x]<size[root_y]) swap(root_x,root_y);

        pare[root_y] = root_x;
        size[root_x] += size[root_y];
        count--;
        return true;
    }

    bool connction(ll x,ll y){
        if(find(x) == find(y)){
            return true;
        }else{
            return false;
        }
    }
};

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b/=2;
        return res;
    }
}

void pushup(ll p,ll l,ll r){
    tree[p] = tree[p<<1] + tree[p<<1 | 1];
}

void bulid(ll p,ll l,ll r){
    if(l == r){
        tree[p] = a[l];
        return;
    }
    ll mid = (l+r)>>1;
    bulid(p<<1,l,mid);
    bulid(p<<1 | 1,mid+1,r);
}

void sovle(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin>>t;
    while(t--){
        sovle();
    }
    return 0;
}