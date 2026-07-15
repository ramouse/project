#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zero = 0;
    for(char c:s){
        if(c == '0') zero++;
    }
    vector<int> ans;
    for(int i = 0;i<zero;i++){
        if(s[i] == '1') ans.push_back(i);
    }
    for(int i = zero;i<n;i++){
        if(s[i] == '0') ans.push_back(i);
    }

    if(ans.size() == 0){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
        cout<<ans.size()<<endl;
        for(auto i : ans){
            cout<<i+1<<" ";
        }
        cout<<endl;
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