#include <bits/stdc++.h>
using namespace std;


int p(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main()
{
    

    int n;
    cin >> n;

    set<int> v;

    while (n != 1 && v.find(n) == v.end())
    {
        v.insert(n);
        n = p(n);
    }

    if (n == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}