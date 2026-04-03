#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 676767677;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    if(n-k+1>k){
        for(int i= 1;i<=n;i++){
            if(b[i] != -1){
                if(a[i] != b[i]){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
        cout<<"Yes"<<endl;
        return;
    }else if(n-k+1<=k){
        for(int i = 1;i<n-k+1;i++){
            if (b[i] != -1)
            {
                if (a[i] != b[i])
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
        for(int i = k+1;i<=n;i++){
            if (b[i] != -1)
            {
                if (a[i] != b[i])
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
        multiset<ll> se,se1;
        ll co = 0;
        for(int i = n-k+1;i<=k;i++){
            se.insert(a[i]);
        }
        for(int i = n-k+1;i<=k;i++){
            if(b[i] != -1){
               if(se.count(b[i])){
                    se.extract(b[i]);
               }else{
                    se1.insert(b[i]);
               }
            }else{
                se1.insert(b[i]);
            }
            
        }
        for(auto v : se){
            if(se1.count(v)){
                se1.extract(v);
                se.extract(v);
            }else{
                if(se1.count(-1)){
                    se1.extract(-1);
                    se.extract(v);
                }
            }
        }
        if(se.empty()) cout << "Yes" << endl;
        else cout<<"No"<<endl;
        return;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}