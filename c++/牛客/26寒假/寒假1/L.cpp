#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main()
{
    ll n;
    cin >> n;
    ll a = n % 10;
    if(a == 5) cout<<2;
    else if( a == 0) cout<<1;
    else if(a % 2 == 0) cout<<5;
    else cout<<10;
        
    return 0;
}