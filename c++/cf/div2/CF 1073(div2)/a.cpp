#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    for(int i =1;i<=n;i++){
        int t;
        cin>>t;
        a.push_back({t,i});
    }
    sort(a.begin(),a.end());
    for(int i = 0;i<n-1;i++){
        if(a[i].second & 1){
            if(a[i+1].second & 1){
                cout<<"No"<<endl;
                return;
            }
        }else{
            if(!(a[i+1].second & 1)){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
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