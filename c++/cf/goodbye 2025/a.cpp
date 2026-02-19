#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int y = 0;
        int n = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'Y')
                y++;
            else
                n++;
        }
        if (y <= 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}