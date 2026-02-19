#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    ll cheng = 1;
    for(int i = 1;i<=n;i++){
        sum+=i;
        cheng *= i;
    }
    if(sum == cheng){
        cout<<"YES"<<endl;
        for(int i = 1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
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