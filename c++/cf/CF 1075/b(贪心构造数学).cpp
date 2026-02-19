#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n,0);
    vector<ll> b(n, 0);
    vector<ll> c(n, 0);

    ll start = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        start += (b[i]-1) * a[i];
    }

    if(start>=x){
        cout<<0<<endl;
    }else{
        ll m = -2e30;
        for(int i = 0;i<n;i++){
            ll t = a[i] * b[i] - c[i];
            if(t>m) m = t;
        }

        if(m<=0) cout<<-1<<endl;
        else{
            ll need = x - start;
            cout<<(need+m-1)/m<<endl;
        }
    }

    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}