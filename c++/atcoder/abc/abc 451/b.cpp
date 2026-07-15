#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1,0),b(n+1,0),ans(m+1,0);
    for(int i= 1;i<=n;i++){
        cin>>a[i]>>b[i];
        ans[a[i]]++;
    }
    vector<ll> ans1 = ans;
    for(int i = 1;i<=n;i++){
        ans1[a[i]]--;
        ans1[b[i]]++;
    }
    for(int i = 1;i<=m;i++){
        cout<<ans1[i]-ans[i]<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}