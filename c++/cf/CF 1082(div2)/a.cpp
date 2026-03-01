#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll x,y;
    cin>>x>>y;
    if(x<2){
        cout<<"NO"<<endl;
        return;
    }
    
    if(y>=0){
        x-=2*y;
        if(x%3 == 0 && x>=0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        x-=4*abs(y);
        if (x % 3 == 0 && x>=0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main(){
    int t;
    t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}