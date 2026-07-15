#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<ll> a(n+1,0);
    ll chu = 0;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    ll aa = a[p];

    if(k>=n){
        cout<<m/a[p]<<endl;
        return;
    }
    
    vector<ll> pre = a;
    ll c1 = 0;
    if(p<=k){
        c1 = a[p];
    }else{
        sort(pre.begin()+1,pre.begin()+p);
        for(int i = 1;i<=p-k;i++){
            c1+=pre[i];
        }
        c1+=a[p];
    }
    
    if(m<c1){
        cout<<0<<endl;
        return;
    }

    ll c2 = 0;
    pre = a;
    pre.erase(pre.begin()+p);
    sort(pre.begin()+1,pre.end());
    for(int i = 1;i<=n-k;i++){
        c2+=pre[i];
    }
    c2+=aa;
    m-=c1;
    ll ans = 1;
    if(c2>0) ans += m/c2;
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