#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    if(!(n&1)){cout<<"YES"<<endl;
        int k = n/2;
        for(int i = 1;i<=n/2;i++){
            cout<<i+k<<" "<<i<<" ";
        }
        cout<<endl;
        return;
    }else{cout<<"YES"<<endl;
        int k = (n-1)/2;
        for(int i = 1;i<=(n-1)/2;i++){
            cout<<i+k<<" "<<i<<" ";
        }
        cout<<n<<endl;
        return;
    }
    cout<<"NO"<<endl;
}   

int main(){
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}