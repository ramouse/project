#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0),diff(n+1,0),pre(n+1,0);
    map<ll,vector<ll>> mp;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        diff[i] = b[i]-a[i];
    }
    for(int i = 1;i<=n;i++){
        pre[i] = pre[i-1] + (diff[i]==0);
        mp[diff[i]].push_back(i);
    }

    ll ans = 0;

    for(auto it:mp){
        if(it.first == 0) continue;
        vector<ll> p = it.second;
        ll cur = 1;
        for(int i = 0;i<p.size();i++){
            if(!i) cur = 1;
            else cur = max(1LL,cur+1-pre[p[i]]+pre[p[i-1]-1]); //在差值为k的情况下，相邻两个k中间的0是消掉更优还是不消更优
            ans = max(ans,cur);
        }
    }

    cout<<ans+pre[n]<<endl;
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