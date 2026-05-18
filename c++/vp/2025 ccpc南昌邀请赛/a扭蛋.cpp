#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0),pre(n+1,0);
    ll maxx = 0;
    ll r = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        r+=a[i];
    }
    sort(a.begin()+1,a.end(),greater<ll>());
    for(int i = 1;i<=n;i++){
        pre[i] = pre[i - 1] + a[i];
    }

    auto check = [&](ll x){
        ll t = 0;
        ll cur = 0;
        ll sum = x;
        ll index = -1;
        for(int i = 1;i<=n;i++){
            if(pre[i]>=x){
                t+=i;
                index = i;
                break;
            }
        }

        for(int i = 1;i<=index;i++){
            if(i != index) cur+=a[i]-1,sum-=a[i];
            else if(sum>0){
                cur += sum-1;
            }
        }
        t+=cur/k;
        
        if(t>=n) return true;
        else return false;
    };

    ll l = n;
    ll ans = 0;
    while(l<=r){
        ll mid = (l+r)>>1;
        if(check(mid)){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}