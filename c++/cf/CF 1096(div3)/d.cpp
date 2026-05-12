#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(2*n+1,0);
    ll l = 0,r = 0;
    for(int i = 1;i<=2*n;i++){
        cin>>a[i];
        if(a[i] == 0){
            if(l==0) l = i;
            else r = i;
        }
    }

    auto check = [&](ll L,ll R){
        vector<bool> vis(n+1,0);
        while(L>=1 && R<=2*n && a[L] == a[R]){
            vis[a[L]] = 1;
            L--;
            R++;
        }

        ll mex = 0;
        while(vis[mex]){
            mex++;
        }
        return mex;
    };

    ll ans = 1;
    ans = max({ans,check(l,l),check(r,r),check((l+r)/2,(l+r+1)/2)});
    cout<<ans<<endl;
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