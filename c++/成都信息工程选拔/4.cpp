#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    ll lowbit(int x){
        return x & (-x);
    }
    
    void add(int i, ll delta,ll li) {
        for (; i <= li; i += lowbit(i)) {
            tree[i] = tree[i] + delta;
        }
    }
    
    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= lowbit(i)) {
            sum = sum + tree[i];
        }
        return sum;
    }
    
    ll query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    
    ll maxx = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        maxx = max(maxx,a[i]);
    }
    BIT bit(maxx);
    vector<ll> l(n+1,0),r(n+1,0);
    ll ans = 0;
    bit.add(a[1],1,maxx);
    for(int i = 2;i<=n;i++){
        l[i] = (l[i]+bit.query(a[i]))%MOD;
        bit.add(a[i],1,maxx);
    }
    BIT bit1(n);
    bit1.add(a[n],1,maxx);
    for(int i = n-1;i;i--){
        r[i] = (r[i]+bit1.query_range(a[i],maxx))%MOD;
        bit1.add(a[i],1,maxx);
    }
    for(int i = 1;i<=n;i++){
        ans = (ans + l[i]*r[i]%MOD)%MOD;
    }
    cout<<ans;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}