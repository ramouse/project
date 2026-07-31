#include<bits/stdc++.h> 
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;

void solve(){
    ll n,p;
    cin>>n>>p;
    vector<ll> a(n+1,0),pre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }

    ll ans = 0,r = 0,l = 0;;
    set<pair<ll,ll>> se;
    se.insert({0,0});
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        sum = (sum + a[i]) % p;
        auto idx = se.upper_bound({sum,n+1});
        if(idx != se.end()){
            if((sum - idx->first + p) % p > ans){
                ans = (sum - idx->first + p) % p;
                r = i-1;
                l = idx->second;
            }
        }
        idx = se.begin();
        if(idx!=se.end()){
            if((sum - idx->first + p) % p > ans){
                ans = (sum - idx->first + p) % p;
                r = i-1;
                l = idx->second;
            }
        }
        se.insert({sum,i});
    }
    cout<<l<<" "<<r<<" "<<ans<<endl;
}

int main( )
{
    int t = 1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}