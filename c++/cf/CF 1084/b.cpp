#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    vector<int> diff(n+1,0);
    bool ok = false;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        diff[i] = a[i] - a[i-1];
        if(diff[i] < 0) ok = true;
    }
    
    if(ok){
        cout<<1<<endl;
    }else{
        cout<<n<<endl;
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