#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int maxx = n + m;

    vector<int> unique_a = a;
    sort(unique_a.begin(), unique_a.end());
    unique_a.erase(unique(unique_a.begin(), unique_a.end()), unique_a.end());
    int k = unique_a.size();

    vector<int> c(maxx + 1, 0);
    for (int x : unique_a)
    {
        if (x > maxx)
            continue;

        for (int multi = x; multi <= maxx; multi += x)
        {
            c[multi]++;
        }
    }

    int aa = 0;
    int bb = 0;
    int both = 0;

    for (int i = 0; i < m; i++)
    {
        int y = b[i];
        if (c[y] == k)
        {
            aa++;
        }
        else if (c[y] == 0)
        {
            bb++;
        }
        else
        {
            both++;
        }
    }

    if (both % 2 == 1)
    {
        if (aa >= bb)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    else
    {
        if (aa > bb)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}