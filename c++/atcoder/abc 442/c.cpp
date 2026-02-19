#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1,1);
    for(int i = 1;i<=m;i++){
        ll b,c;
        cin>>b>>c;
        a[b]++,a[c]++;
    }
    for(int i = 1;i<=n;i++)
    {
        ll co = n - a[i];
        ll t = co--;
        ll tt = co--;

        cout<<(co * t * tt) / 6<<" ";
    }
    return 0;
}