#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = a[i] + pre[i-1];
    }
    while(q--){
        ll num = 0;
        cin>>num;
        if(num == 1){
            ll x;
            cin>>x;
            pre[x] = pre[x] - a[x] + a[x+1];
            swap(a[x],a[x+1]);
        }else{
            ll l,r;
            cin>>l>>r;
            cout<<pre[r] - pre[l-1]<<endl;
        }
    }
}