#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n, m;
vector<ll> parten;
vector<ll> siz;
vector<ll> ans;
ll co;

ll find(ll x){
    return parten[x] == x ? x : parten[x] = find(parten[x]);
}

bool merge(ll x,ll y){
    ll rootx = find(x);
    ll rooty = find(y);

    if(rootx == rooty) return true;

    if(siz[rootx]<siz[rooty]) swap(rootx,rooty);

    parten[rooty] = rootx;
    siz[rootx]+=siz[rooty];
    co--;
    return true;

}

bool cont(ll x,ll y){
    return find(x) == find(y);
}

void solve()
{
    cin>>n>>m;
    parten.resize(n+1);
    siz.resize(n+1,1);
    ans.resize(n+1,0);
    co = n;
    for(int i = 1;i<=n;i++){
        parten[i] = i;
    }

    for(int i = 1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        merge(a,b);
    }
    
    cout<<co-1<<" "<<(2*co-2+n-1)/n;

    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}