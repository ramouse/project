#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;

    if(n<=3){
        cout<<min(abs(x1 - x2), n - abs(x1 - x2))<<endl;
        return;
    }
    cout << min(abs(x1 - x2), n - abs(x1-x2)) + k << endl;
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