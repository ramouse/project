#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, len;
    cin >> n >> len;
    ll limt = 0;
    if (n > 30)
    {
        limt = len + 1;
    }
    else
    {
        limt = 1LL << (n - 1);
    }
    ll temp = 0;
    for (int i = 1; i <= len; i++)
    {
        if (temp < limt)
        {
            cout << '1';
            temp++;
        }
        else
        {
            cout << '0';
            temp--;
        }
    }
    return 0;
}
