#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string r;
        cin >> r;
        int ans = 0;
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i] == 's')
                continue;
            if (r[i] == 'u')
            {
                if (i == 0 || i == r.size() - 1)
                {
                    ans++;
                    r[i] = 's';
                }
                if (i != 0 && r[i + 1] == 'u')
                {
                    r[i + 1] = 's';
                    ans++;
                }
                else
                    continue;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}