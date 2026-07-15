#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;
    if(k>=n && k<=2*n-1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
        return;
    }

    ll m = k-n;
    if(m == 0){
        for(int i = 1;i<=n;i++){
            cout<<i<<" "<<i<<" ";
        }
        cout<<endl;
        return;
    }else{
        cout<<"1 2 ";
        for(int i = 1;i<=m-1;i++){
            cout<<i+2<<" "<<i<<" ";
        }
        cout<<m<<" "<<m+1<<" ";
        for(int i = m+2;i<=n;i++){
            cout<<i<<" "<<i<<" ";
        }
        cout<<endl;
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