#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    bool ok1 = false;
    bool ok2 = false;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] == 67) ok2 = true;
    }
    if(ok2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}