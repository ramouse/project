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
    vector<ll> a(n+1,0);
    map<ll,ll> cnt;
    ll root = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(a[i] > a[root]){
            root = i;
        }
    }

    vector<ll> stk;
    vector<ll> ls(n+1,0);
    vector<ll> rs(n+1,0);
    vector<ll> fa(n+1,0);

    for(int i = 1;i<=n;i++){
        ll last = 0;

        while(!stk.empty() && a[stk.back()] < a[i]){
            last = stk.back();
            stk.pop_back();
        }

        if(!stk.empty()){
            rs[stk.back()] = i;
            fa[i] = stk.back();
        }

        if(last){
            ls[i] = last;
            fa[last] = i;
        }

        stk.pb(i);
    }

    vector<ll> ord;
    stk.clear();
    stk.push_back(root);

    while(!stk.empty()){
        ll u = stk.back();
        stk.pop_back();
        ord.pb(u);

        if(ls[u]) stk.pb(ls[u]);
        if(rs[u]) stk.pb(rs[u]);
    }
    
    vector<ll> sz(n+1,1);
    reverse(all0(ord));

    for(int i = 0;i<ord.size();i++){
        ll u = ord[i];

        if(ls[u]) sz[u] += sz[ls[u]];
        if(rs[u]) sz[u] += sz[rs[u]];
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(fa[i] && a[fa[i]] > a[i]){
            ans += sz[i];
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    ll n;
    cin >> t;
    while (t--){
        solve();
    }
        
}