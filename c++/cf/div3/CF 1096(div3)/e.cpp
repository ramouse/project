#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    vector<ll> suf(n+2,INF);
    ll ans = 0;
    ll id = -1;
    ll maxx = 0;
    for(int i = n;i;--i){
        suf[i] = min(suf[i+1],a[i]);
        if (a[i] > suf[i])
            ans += a[i] - suf[i];
    }
    
    ll cur = 0;
    for(int i = 1;i<n;i++){
        if(suf[i] == suf[i+1]){
            cur++;
        }else{
            cur=0;
        }
        maxx = max(maxx,cur);
    }
   
    cout<<ans+maxx<<endl;
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