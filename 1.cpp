#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        while(n>=4){
            n-=4;
            ans++;
        }
        if(n!=0) ans++;
        cout << ans << endl;
    }
    return 0;
}