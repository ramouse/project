#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, c, k;
    cin >> n >> c >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

   
    sort(a.begin(), a.end());


    for (int i = 0; i < n; i++)
    {
        if (a[i] <= c)
        {

            ll dif = c - a[i];
            ll use_k = min(k, dif);

            
            c += a[i] + use_k;
            k -= use_k;
        }
        else
        {
        
            break;
        }
    }

    cout << c << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}