#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> vec(n+1,0);
    multiset<ll> se;
    bool ok1 = true;
    for(int i = 1;i<=n;i++){
        cin>>vec[i];
        se.insert(vec[i]);
        if(se.count(vec[i]) >= 2){
            ok1 = false;
        }
    }
    if(ok1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    for(int i = 1;i<=m;i++){
        if(!se.count(i)){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}