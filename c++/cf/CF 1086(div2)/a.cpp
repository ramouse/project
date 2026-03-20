#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    map<int,int,greater<int>> mp;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int a;
            cin>>a;
            mp[a]++;
        }
    }
    int maxx = 0;
    for(int i = 1;i<=n*n;i++){
        maxx= max(maxx,mp[i]);
    }
    int can = (n-1)*n;
    
    if(maxx<=can){
        cout<<"YES"<<endl;
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