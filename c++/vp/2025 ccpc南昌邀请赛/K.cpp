#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll INF = 1e18;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),zero,one,two,sre;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]%4==0) zero.push_back(i);
        if(a[i]%4 == 1) one.push_back(i);
        if(a[i]%4 == 2) two.push_back(i);
        if(a[i]%4 == 3) sre.push_back(i);
    }
    
    vector<ll> ans;
    for(auto i : zero) ans.push_back(i);

    while(!sre.empty() && !one.empty()){
        ans.push_back(sre.back());
        ans.push_back(one.back());
        sre.pop_back();
        one.pop_back();
    }

    while(!two.empty() && one.size()>=2){
        ans.push_back(two.back());
        ans.push_back(one.back());
        one.pop_back();
        ans.push_back(one.back());
        two.pop_back();
        one.pop_back();
    }

    while(sre.size()>=2 && !two.empty()){
        ans.push_back(sre.back());
        sre.pop_back();
        ans.push_back(sre.back());
        ans.push_back(two.back());
        sre.pop_back();
        two.pop_back();
    }

    while(!two.empty()){
        ans.push_back(two.back());
        two.pop_back();
    }

    if(one.empty() && two.empty() && sre.empty()){
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }

    
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