#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;

   
    map<ll, int> mp;
    for (int j = 0; j < n; j++)
    {
        if (a[j] % 5 == 0)
        {
            ll base = a[j] / 5;
            ll t7 = base * 7; 
            ll t3 = base * 3; 

            
            if (mp.count(t7) && mp.count(t3))
            {
                ans += (ll)mp[t7] * mp[t3];
            }
        }
        
        mp[a[j]]++;
    }

    mp.clear();
    for (int j = n - 1; j >= 0; j--)
    {
        if (a[j] % 5 == 0)
        {
            ll base = a[j] / 5;
            ll t7 = base * 7;
            ll t3 = base * 3;

            if (mp.count(t7) && mp.count(t3))
            {
                ans += (ll)mp[t7] * mp[t3];
            }
        }

        mp[a[j]]++;
    }

    cout << ans << endl;

    return 0;
}