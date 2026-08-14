#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

struct DSU{
    ll n;
    vector<ll> par;
    vector<ll> siz;
    ll count;

    DSU(ll n):n(n),siz(n+1,1),par(n+1) {
        iota(par.begin(),par.end(),0);
    }

    ll find(ll x){
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    bool merge(ll x,ll y){
        ll rootx = find(x);
        ll rooty = find(y);

        if(rootx == rooty) return false;

        if(siz[rootx] < siz[rooty]) swap(rootx,rooty);
        par[rooty] = rootx;
        siz[rootx] += siz[rooty];

        return true;
    }

    ll conected(ll x,ll y){
        return find(x) == find(y);
    }

};

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    ll ma = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        ma = max(a[i],ma);
    }
    vector<bool> vis(ma+1,0);
    for(int i = 1;i<=n;i++){
        vis[a[i]] = 1;
    }
    DSU dsu(ma);


    ll c = 0;
    ll ans = 0;
    for(int i = ma;i;i--){
        ll num1 = -1,num2 = -1;
        for(int j = i;j<=ma;j+=i){
            if(vis[j]){
                if(num1 == -1){
                    num1 = j;
                }else{
                    if(dsu.merge(num1,j)){
                        ans+=i;
                        c++;
                    }
                }
            }
        }
        if(c == n-1) break;
    }

    cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}