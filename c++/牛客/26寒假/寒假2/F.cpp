#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll gcd(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

void solve(){
    ll n;
    cin>>n;
    ll x = n<<32;
    ll y = x+n;
    cout<<x<<" "<<y<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}