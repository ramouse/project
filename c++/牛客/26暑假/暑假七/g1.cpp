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
    ll n,temp;
    cin >> n;
  set<ll>s;
  for(ll i=0;i<n;i++){cin>>temp;s.insert(temp);}
  if(s.size()>=4)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
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