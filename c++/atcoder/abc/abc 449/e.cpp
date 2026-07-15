#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a;
    map<ll,ll> mp;
    for(int i = 1;i<=n;i++){
        ll u;
        cin>>u;
        a.push_back(u);
        mp[u]++;
    }
    ll cnt_zero = 0;
    ll maxx = 0;
    vector<ll> lost;
    for(int i = 1;i<=m;i++){
        if(!mp.count(i)){
            cnt_zero++;
            lost.push_back(i);
        }else{
            maxx = max(maxx,mp[i]);
        }
    }
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}