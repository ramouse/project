#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct Node{
    ll l,r,id;
};

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll block = sqrt(n);
    vector<Node> q(m+1);
    for(int i = 1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        q[i] = {l,r,i};
    }
    vector<pair<ll,ll>> ans(m+1);
    vector<ll> cnt(n+1,0);
    ll sum = 0;
    sort(q.begin()+1,q.end(),[&](const Node& x,const Node& y){
        if(x.l/block == y.l/block) return x.r<y.r;
        else return x.l/block < y.l/block;
    });

    auto add = [&](ll i){
        sum+=cnt[i];
        cnt[i]++;
    };

    auto del = [&](ll i){
        cnt[i]--;
        sum-=cnt[i];
    };

    ll l = 1,r = 0;
    for(int i = 1;i<=m;i++){
        ll ql = q[i].l;
        ll qr = q[i].r;
        ll id = q[i].id;

        if(ql == qr){
            ans[id] = {0,1};
            continue;
        }

        while(l>ql) add(a[--l]);
        while(r<qr) add(a[++r]);
        while(l<ql) del(a[l++]);
        while(r>qr) del(a[r--]);
        ans[id] = {sum,(r-l+1)*(r-l)/2};
        if(ans[id].first != 0){
            ll g = gcd(ans[id].first,ans[id].second);
            ans[id].first/=g;
            ans[id].second /= g;
        }else{
            ans[id].second = 1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << ans[i].first << "/" << ans[i].second << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}