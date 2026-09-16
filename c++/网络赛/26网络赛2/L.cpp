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
vector<vector<ll>> mul(const vector<vector<ll>> &a,const vector<vector<ll>>&b){
    ll n=a.size();
    vector<vector<ll>>res(n,vector<ll>(n,INF));
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            for(ll k=0;k<n;k++){
                res[i][j]=min(res[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return res;
}
vector<vector<ll>> qpow(vector<vector<ll>>a,ll b){
    ll n=a.size();
    vector<vector<ll>>res(n,vector<ll>(n,INF));
    for(ll i=0;i<n;++i)res[i][i]=0;
    while(b){
        if(b%2){
            res=mul(res,a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
void solve()
{
  ll n;cin>>n;
  ll val[n];
  for(ll i=0;i<n;i++)cin>>val[i];
  vector<vector<ll>>a(n,vector<ll>(n,INF));
  for(ll i=0;i<n;i++){

      a[i][(i + 1) % n] = val[(i + 1) % n];
      a[i][(i - 1 + n) % n] = val[(i - 1 + n) % n];
    //   cout << a[i][(i - 1 + n) % n]<<endl;
  }
//   for(int i = 0;i<n;i++){
//     for(int j = 0;j<n;j++){
//         cout<<a[i][j]<<" ";
//     }
//     cout<<endl;
//   }
    cout<<qpow(a,2*n-2)[0][0] + val[0]<<endl;;
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