#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>
#define all1(x) x.begin() + 1,x.end()
#define all0(x) x.begin(),x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{   
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    vector<ll> ans;
    for(int i = 1;i<=n;i++){
        bool ok = true;
        for(int j = 1;j<=n;j++){
            if(i == j) continue;
            if(abs(a[i] - a[j]) < d){
                ok = false;
                break;
            }
        }
        if(ok) ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for(ll u : ans){
        cout<<u<<" ";
    }
    cout<<endl;
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