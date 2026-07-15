#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1,0),b(m+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=m;i++) cin>>b[i];

    vector<ll> prebu(n+1,0),prefa(n+1,0);
    for(int i = 1;i<=n;i++){
        prebu[i] = prebu[i-1] + a[i];
        prefa[i] = prefa[i-1] - a[i];
    }

    sort(b.begin() + 1,b.end());
    vector<ll> vec;
    ll ans = 0;
    ll last = 0;
    for(int i = 1;i<=m;i++){
        ll index = b[i];
        ll c = max({prefa[index] - prefa[last],prebu[index] - prebu[last]});
        ans += c;
        last = index;
        // cout<<cur<<" ";
    }
    if(b[m] != n) ans += prebu[n] - prebu[b[m]];
    // if(b[m] != n){
    //     ll c = max(prefa[b[m]],prebu[b[m]]);
    //     cur = max(c,cur + c);
    //     ans = max(ans,cur);
    // }

    cout<<ans<<endl;

}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}