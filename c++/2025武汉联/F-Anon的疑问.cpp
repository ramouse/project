#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const ll N = 2e7;
vector<ll> vec(N + 10, 0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin >> q;
    ll n = sqrt(N);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i * i + j * j > N)
                break;
            vec[i * i + j * j] = 1;
        }
    }
    while (q--)
    {
        ll n;
        cin >> n;
        if (vec[n])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}