#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1,0);
    vector<ll> b(m+1,0);
    ll sum_a = 0,sum_b = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum_a+=a[i];
    }
    for(int i = 1;i<=m;i++){
        cin>>b[i];
        sum_b+=b[i];
    }

    sort(a.begin()+1,a.end(),greater<ll>());
    sort(b.begin()+1,b.end(),greater<ll>());

    ll ans = 0;
    ll diff = sum_a - sum_b;
    if(diff<0){
        for(int i = 1;i<=m;i++)
        {
            if(diff + b[i] >= 0){
                ans++;
                break;
            }else{
                ans++;
                diff += b[i];
            }
        }
    }else if(diff>0){
        for(int i = 1;i<=n;i++){
            if(diff - a[i] <= 0){
                ans++;
                break;
            }else{
                ans++;
                diff -= a[i];
            }
        }
    }else if(diff == 0) ans = 1;
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