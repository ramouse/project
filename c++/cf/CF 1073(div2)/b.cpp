#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    int zero = 0;
    int one = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] == 0) zero++;
        if(a[i] == 1) one++;
    }

    if(zero == 0 || (zero>=2 && one == 0)){
        cout<<"No"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;   
}