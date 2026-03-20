#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int h,w;
    cin>>h>>w;
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        if(n == 1){
            ll r;
            cin>>r;
            cout<<r*w<<endl;
            h-=r;
        }else{
            int c;
            cin>>c;
            cout<<c*h<<endl;
            w-=c;
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