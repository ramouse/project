#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    map<ll,ll> cnt,ccnt;
    ll kind = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(all1(a));

    vector<ll> vec;

    for(auto [f,s] : cnt){
        ccnt[s]++;
        vec.push_back(s);
    }

    bool ok = true;
    ll cur = 0;
    for(auto [f,s] : ccnt){
        kind++;
    }
    // cout<<cur<<endl;

    if (kind == 1 && a.size() == 2)
    {
        cout << "NO" << endl;
        return;
    }

    ll cur = 0;
    for(ll u : vec){
        u -= cur;
        
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}