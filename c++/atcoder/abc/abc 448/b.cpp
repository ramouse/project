#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll> c(m+1,0),a(n+1,0),b(n+1,0);
    for(int i = 1;i<=m;i++){
        cin>>c[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(b[i]>=c[a[i]]){
            ans+=c[a[i]];
            c[a[i]] = 0;
        }else{
            ans+=b[i];
            c[a[i]]-=b[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}