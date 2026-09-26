#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n;ll temp;
    cin>>n;map<ll,ll>mapb,mapc;ll ans=0;vector<ll>a,b;
    for(ll i=0;i<n;i++){
        cin>>temp;a.push_back(temp);
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        b.push_back(temp);
        mapb[temp]=i;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        mapc[temp] = i;
    }
    ll temp1=-1,temp2=-1;
    for(ll i=0;i<n;i++){
        temp1=max(temp1,mapb[a[i]]);
        temp2 = max(temp2, mapc[a[i]]);
        if(temp1==i||temp2==i)ans++;
        if(temp1==i&&temp2==i)ans--;
    }
    temp=-1;
    for (ll i = 0; i < n; i++)
    {
        temp = max(temp, mapc[b[i]]);
        if (i==temp)
            ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}