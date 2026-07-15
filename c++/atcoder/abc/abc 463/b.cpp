#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 676767677;

void solve(){
    ll n;
    char x;
    cin>>n>>x;
    vector<string> s(n+1);
    map<char,int> mp;
    ll c = 0;
    for(char i = 'A';i<='E';i++){
        mp[i] = c++;
        // cout<<i<<" "<<mp[i]<<endl;
    }
    // cout<<mp[x]<<endl;
    bool ok = false;
    for(int i = 1;i<=n;i++){
        // getline(cin,s[i]);
        cin>>s[i];
        // cout<<s[i]<<endl;
        // cout<<s[i][0]<<endl;
        if(s[i][mp[x]] == 'o'){ok = true;}
    }

    if(ok){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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