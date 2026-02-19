#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+3,0);
    

    return 0;
}