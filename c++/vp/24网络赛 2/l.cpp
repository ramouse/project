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
    ll n,a,b;cin>>n;
    if(n%2==0){
        a= (n/2+1)*(n/2+2)/2+(n-n/2-1)*(1+(n+1)/2);b=n;
        // a = 3*n + 2,b=8;
        ll t = gcd(a, b);
        cout <<a/t<< " " << b/t<< endl;
    }
    else {
        a=(n/2+2)*(n/2+3)/2+(n-n/2-2)*(n/2+2);b=n;
        ll t = gcd(a,b);
        cout << a/t << " " << b/t << endl;
    }
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