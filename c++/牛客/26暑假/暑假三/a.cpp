#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
ll cut(ll n)
{
    ll cnt = 0;

    ll len = 64 - __builtin_clzll(n);
    // cout<<len<<endl;
    for(int i = 0;i<len;i++){
        if(((n>>i) & 1) ^ ((n>>(i+1))) & 1 == 1) cnt++;
    }
    return cnt;
}

void solve()
{
    ll a, b;
    ll n, m;
    cin >> n;
    ll mx = -1;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    // cout<<mx<<endl;
    ll len = 64 - __builtin_clzll(mx);

    ll have = 0;
    // cout<<len<<endl;
    for (int i = 0; i < len; i++)
    {
        have += (1 << i);
    }
    // have = (have << (64 - len)) >> (64 - len);
    // cout<<have<<endl;
    ll index = -1;
    cin >> m;
    pair<ll, ll> cz[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        cz[i] = pair(a, b);
    }
    for (ll i = 0; i < m; i++)
    {
        if (cz[i].first == 1)
        {
            have &= cz[i].second;
        }
        if (cz[i].first == 2)
        {
            have &= (~cz[i].second);
        }
        if (have == 0)
        {
            index = i;
            break;
        }
    }
    // cout << "h" << have << endl;
    ll ans = 0;
    if (index == -1)
    {
        for (ll i = 0; i < m; i++)
        {
            ans = 0;
            if (cz[i].first == 1)
            {
                for (ll j = 0; j < n; j++)
                {
                    arr[j] &= cz[i].second;
                    ans += cut(arr[j]);
                }
            }
            else if (cz[i].first == 2)
            {
                for (ll j = 0; j < n; j++)
                {
                    arr[j] |= cz[i].second;
                    ans += cut(arr[j]);
                }
            }
            else
            {
                for (ll j = 0; j < n; j++)
                {
                    arr[j] ^= cz[i].second;
                    ans += cut(arr[j]);
                }
            }
            cout << ans << endl;
        }
    }
    else
    {
        for (ll i = 0; i <= index; i++)
        {
            ans = 0;
            if (cz[i].first == 1)
            {
                for (ll j = 0; j < n; j++)
                {
                    arr[j] &= cz[i].second;
                    ans += cut(arr[j]);
                }
            }
            else if (cz[i].first == 2)
            {
                for (ll j = 0; j < n; j++)
                {
                    arr[j] |= cz[i].second;
                    ans += cut(arr[j]);
                }
            }
            else
            {
                for (ll j = 0; j < n; j++)
                {
                    arr[j] ^= cz[i].second;
                    ans += cut(arr[j]);
                }
            }
            cout << ans << endl;
        }
        ll temp = arr[1];
        for (ll j = index + 1; j < m; j++)
        {
            if (cz[j].first == 1)
            {
                temp &= cz[j].second;
                cout << cut(temp) * n << endl;
            }
            if (cz[j].first == 2)
            {
                temp |= cz[j].second;
                cout << cut(temp) * n << endl;
            }
            if (cz[j].first == 3)
            {
                temp ^= cz[j].second;
                cout << cut(temp) * n << endl;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // cin>>t;
    // cout<<cut(15)<<endl;
    while (t--)
    {
        solve();
    }
    return 0;
}