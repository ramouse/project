#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m+1,0),b(m+1,0);
    for(int i = 1;i<=m;i++){
        cin>>a[i]>>b[i];
    }

    ll u = a[1];
    vector<ll> cnt(n+1,0);
    ll c= 0;
    for(int i = 1;i<=m;i++){
        if(a[i] != u && b[i] != u){
            cnt[a[i]]++;
            cnt[b[i]]++;
            c++;
        }
    }
    
    ll ans1 = 0;
    for(int i = 1;i<=n;i++){
        if(i != u && cnt[i] == c) ans1++;
    }

    u = b[1];
    for(int i = 1;i<=n;i++){
        cnt[i] = 0;
    }
    c= 0;
    for(int i = 1;i<=m;i++){
        if(a[i] != u && b[i] != u){
            cnt[a[i]]++;
            cnt[b[i]]++;
            c++;
        }
    }

    ll ans2 = 0;
    bool ok = false;
    for(int i = 1;i<=n;i++){
        if(i != u && cnt[i] == c) ans2++;
        if(i == a[1] && cnt[i] == c) ok = true;
    }

    if(ok) ans1--;

    cout<<ans1+ans2<<endl;
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