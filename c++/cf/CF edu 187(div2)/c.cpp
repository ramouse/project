#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll s,m;
    cin>>s>>m;
    vector<ll> ve;
    set<ll> se;
    ll len = 0;
    string mmm = to_string(m);
    ll ss = stoll(mmm,0,2);
    string mm = to_string(ss);
    for(int i = 1;i<=mm.length();i++){
        string t = string(i,'1');
        ll tt = stoll(t);
        ll ttt = tt&m;
        ve.push_back(ttt);
        se.insert(ttt);
    }
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    sort(ve.begin(),ve.end(),greater<ll>());

    ll ans = 0;
    ll index = 0;
    cout<<ve[index]<<endl;
    while(s>0){
        if(s>=ve[index]){
            s-=ve[index];
            ans++;
        }else{
            index++;
        }
        if(s<ve.back()) break;
    }
    
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