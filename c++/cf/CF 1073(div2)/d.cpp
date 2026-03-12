#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cou = 0;
    for(int i = n-1;i>=0;--i){
        if(s[i] == '('){
            cou++;
        }else{
            if(cou>=2){
                cout<<n-2<<endl;
                return;
            }
        }
    }
    cout<<"-1"<<endl;

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