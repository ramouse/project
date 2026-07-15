#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9 + 5;
const ll MOD = 676767677;

void solve()
{
    ll n,x,y,z;
    cin>>n>>x>>y>>z;
    ll t1 = (n + x + y - 1)/(x+y);
    ll t2 = 0;
    if(x * z > n){
        cout<<t1<<endl;
        return;
    }

    t2+=z;
    n-=x * z;
    // t2 += (x + 10 * y + n - 1) / n;
    t2 += (n + x + 10 *y - 1)/(x+10*y);
    cout<<min(t1,t2)<<endl;
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