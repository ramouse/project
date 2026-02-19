#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin>>n;
    int c_1 = 0;
    int c_0 = 0;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(a[0] == 0 && a[n-1] == 0){
        cout<<"Bob\n";
    }else{
        cout<<"Alice\n";
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