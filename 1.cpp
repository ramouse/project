#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    // ll n;
    // cin>>n;
    // string s = "";
    // set<char> se;
    // vector<ll> pre(n+1,0);
    // for(int i = 1;i<=n;i++){
    //     char c;
    //     cin>>c;
    //     se.insert(c);
    //     s+=c;
    //     pre[i] = se.size();
    // }

    // ll ans = 1e9;
    // map<char,ll> mp;
    // ll cur = 0;
    // ll l = 0;

    // for(int r = 0;r<n;r++){
    //     mp[s[r]]++;
    //     if(mp[s[r]] == 1){
    //         cur++;
    //     }

    //     while(cur == se.size()){
    //         ans = min(r-l+1,ans);

    //         mp[s[l]]--;
    //         if(mp[s[l]] == 0){
    //             cur--;
    //         }
    //         l++;
    //     }
    // }

    // cout<<ans<<endl;

    // ll n;
    // cin>>n;
    // vector<ll> a(n+1,0);
    // ll sum = 0;
    // for(int i = 1;i<=n;i++){
    //     cin>>a[i];
    //     sum+=a[i];
    // }
    // ll num = sum/(n/2);
    
    // vector<bool> vis(101,0);
    // for(int i = 1;i<=n;i++){
    //     for(int j = i+1;j<=n;j++){
    //         if(a[i] + a[j] == num && !vis[i] && !vis[j]){
    //             cout<<i<<" "<<j<<endl;
    //             vis[i] = 1,vis[j] = 1;
    //         }
    //     }
    // }


    ll n,m;
    cin>>n>>m;
    vector<bool> x(n+1,0);
    vector<bool> y(n+1,0);
    ll cntx = 0;
    ll cnty = 0;
    while(m--){
        ll xx,yy;
        cin>>xx>>yy;
        ll ans = 0;

        if(x[xx] == 0){
            x[xx] = 1;
            cntx++;
        }
        if(y[yy] == 0){
            y[yy] = 1;
            cnty++;
        }
        ans = (n-cntx)*(n-cnty);
        cout<<ans<<" ";
    }

}

int main()
{
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}