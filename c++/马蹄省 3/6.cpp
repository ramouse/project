#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 998244353;

struct Node{
    ll l,r,v;
};

void solve()
{   
    ll n,m;
    cin>>n>>m;
    vector<Node> vec(m+1);
    vector<ll> a(n+1,0),tree(4*n+5,0),tag(4*n+5,0);

    auto pushup = [&](ll p) -> void{
        tree[p] = tree[p<<1] + tree[p<<1 | 1];
    };

    auto pushdown = [&](ll p) -> void{
        if(tag[p]){
            tag[p<<1] = tag[p];
            tag[p<<1 | 1] = tag[p];

            tree[p<<1] = tag[p];
            tree[p<<1|1] = tag[p];

            tag[p] = 0;
        }
    };

    auto build = [&](auto &&self,ll p,ll l,ll r) -> void{
        if(l == r) return;

        ll mid = (l+r)>>1;
        self(self,p<<1,l,mid);
        self(self,p<<1 | 1,mid+1, r);
        pushup(p);
    };

    auto update = [&](auto &&self,ll p,ll l,ll r,ll ql,ll qr,ll k) -> void{
        if(ql<=l && r<=qr){
            tree[p] = k;
            tag[p] = k;
            return;
        }

        ll mid = (l+r)>>1;
        pushdown(p);
        if(ql<=mid) self(self,p<<1,l,mid,ql,qr,k);
        if(qr > mid) self(self,p<<1 | 1,mid+1,r,ql,qr,k);
        pushup(p);
    };

    auto query = [&](auto &&self,ll p,ll l,ll r,ll ql,ll qr) -> ll{
        if(ql<= l && r<=qr ) return tree[p];

        pushdown(p);
        ll res = 0;
        ll mid = (l+r)>>1;
        if(ql<=mid) res+=self(self,p<<1,l,mid,ql,qr);
        if(qr>mid) res+=self(self,p<<1 | 1,mid+1,r,ql,qr);
        return res;
    };

    //利用线段树维护区间最大值
    auto pushmax = [&](ll p) -> void{
        tree[p] = max(tree[p<<1],tree[p<<1 | 1]);
    };

    auto buildmax = [&](auto &&self,ll p,ll l,ll r) -> void{
        if(l == r){
            tree[p] = a[l];
            return;
        }

        ll mid = (l+r)>>1;
        self(self,p<<1,l,mid);
        self(self,p<<1 | 1,mid+1,r);
        pushmax(p);
    };

    auto query_max = [&](auto &&self,ll p,ll l,ll r,ll ql,ll qr) -> ll{
        if(ql<=l && r<=qr) return tree[p];

        ll mid = (l+r)>>1;
        ll res = 0;
        if(ql<=mid) res = max(res,self(self,p<<1,l,mid,ql,qr));
        if(qr>mid) res = max(res,self(self,p<<1 | 1,mid+1,r,ql,qr));
        return res;
    };

    build(build,1,1,n);

    for(int i = 1;i<=m;i++){
        cin>>vec[i].l>>vec[i].r>>vec[i].v;
    }
    sort(vec.begin()+1,vec.end(),[&](const auto&x,const auto&y){
        return x.v>y.v;
    });

    for(int i = 1;i<=m;i++){
        auto [f_l,f_r,f_v] = vec[i];
        update(update,1,1,n,f_l,f_r,f_v);
    }

    
    //将判断完的数组取出
    for(int i = 1;i<=n;i++){
        a[i] = query(query,1,1,n,i,i);
        if(a[i] == 0) a[i] = 1;
    }
    //将线段树更新为区间最大线段树
    buildmax(buildmax, 1, 1, n);

    for(int i = 1;i<=m;i++){
        auto [f_l, f_r, f_v] = vec[i];
        if(f_v != query_max(query_max,1,1,n,f_l,f_r)){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}