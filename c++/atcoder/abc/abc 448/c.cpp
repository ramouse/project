#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    vector<pair<ll,ll>> a(n+1);
    for(int i = 1;i<=n;i++){
        ll t;
        cin>>t;
        a[i] = make_pair(t,i);
    }
    sort(a.begin(),a.end());

    while(q--){
        ll k;
        cin>>k;
        vector<ll> b(k+1,0);
        for(int i = 1;i<=k;i++){
            cin>>b[i];
        }
        sort(b.begin()+1,b.end());

        for(int i = 1;i<=6;i++){
            bool mo = false;
            for(int j = 1;j<=k;j++){
                if(b[j] == a[i].second){
                    mo = true;
                    break;
                }
            }
            if(!mo){
                cout<<a[i].first<<endl;
                break;
            }
        }
        
    }
    return 0;
}