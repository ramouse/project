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

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    ll cur = 0;
    for(int i = 1;i<=n-1;i++){
        if(gcd(a[i],a[i+1]) == 1){
            ans++;
            cur++;
            if (!(cur&1))
            {
                ans--;
            }
        }else{
            cur = 0;
        }
        
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}