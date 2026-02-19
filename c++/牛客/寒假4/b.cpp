#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n,q,s;
    cin>>n>>q>>s;
    vector<ll> t(n+1,0);
    vector<ll> pre(n + 1, 0);
    for(int i = 1;i<=n;i++) {
        cin>>t[i];
        pre[i] = pre[i-1] + t[i];
    }

    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<pre[x-1]+s+y-1<<endl;
    }
    return 0;
}