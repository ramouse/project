#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n, m;
const ll N = 2e5+5;
ll tree[N*4];
ll tag[N*4];
vector<pair<ll, ll>> vec(N + 1);

void push(ll p){
    tree[p] = max(tree[p<<1],tree[p<<1 | 1]);
}

void push_down(ll p)
{
    if(tag[p]){
        tag[p<<1] += tag[p];
        tag[p<<1 | 1] += tag[p];

        tree[p<<1] += tag[p];
        tree[p<<1 | 1] += tag[p];
        tag[p] = 0;
    }
}

void bulid(ll p,ll l,ll r){
    tag[p] = 0;
    tree[p] = 0;
    if(l == r){
        return;
    }

    ll mid = (l+r)>>1;
    bulid(p<<1,l,mid);
    bulid(p<<1 | 1,mid+1,r);
    push(p);
}

void update(ll p,ll l,ll r,ll ql,ll qr,ll k){
    if(r<=qr && l>=ql){
        tree[p] += k;
        tag[p] += k;
        return;
    }

    push_down(p);
    ll mid = (l+r)>>1;
    if(ql<=mid) update(p<<1,l,mid,ql,qr,k);
    if(qr>mid) update(p<<1 | 1,mid+1,r,ql,qr,k);
    push(p);
}

void solve(){

    cin>>n>>m;

    
    for(int i = 1;i<=n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    bulid(1,1,n);
    ll l = 1;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        update(1,1,n,vec[i].first,vec[i].second,1);

        while(tree[1]>m){
            update(1, 1, n, vec[l].first, vec[l].second, -1);
            l++;
        }
        ans = max(ans,i-l+1);
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}