#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

ll xzx(int x)
{
    return x*(x-1)/2;
}

void solve()
{
    ll n,m;
    cin>>n>>m;

    // if(n-1<m){
    //     cout<<0<<endl;
    //     return;
    // }


    // ll ans = 0;
    // ll cnt = 0;
    // auto dfs = [&](auto &&self,ll u,ll fa) -> void{
    //     cnt++;
    //     if(cnt <= m && u<=n){
    //         self(self, u + 1, u);
    //         ans += max(0LL,u - 2);
    //     }
        
    // };
    // dfs(dfs,1,0);
    // cout<<ans<<endl;
    if(m<=1) {cout<<0<<'\n';return;}
    // else if(m<=n-1) cout<<xzx(m)<<'\n';
    // else if(m<n*(n-1)/2){
    //     cout<<xzx(n-1)-(m-(n-1))<<'\n';
    // }
    // else cout<<0<<'\n';
    if(n>=m+1){n=m+1;cout<<m*(m-1)/2<<endl;return;}
    if(n<=m){cout<<max(0LL,(n-1)*(n-2)/2-(m-n+1))<<endl;return;}
}

int main()
{
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}