#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

vector<int> adj[7];

void init(){
    adj[1].push_back(3), adj[1].push_back(2), adj[1].push_back(4), adj[1].push_back(5);
    adj[2].push_back(3), adj[2].push_back(3), adj[2].push_back(4), adj[2].push_back(6);
    adj[3].push_back(1), adj[3].push_back(2), adj[3].push_back(5), adj[3].push_back(6);
    adj[4].push_back(1), adj[4].push_back(2), adj[4].push_back(5), adj[4].push_back(6);
    adj[5].push_back(1), adj[5].push_back(3), adj[5].push_back(4), adj[5].push_back(6);
    adj[6].push_back(2), adj[6].push_back(4), adj[6].push_back(3), adj[6].push_back(5);
}

void solve(){
    ll n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll ans = 0;
    for(int i = 2;i<=n;i++){
        if(a[i] + a[i-1] == 7 || a[i] == a[i-1]){
            ans++;
            a[i] = -1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    init();
    while(t--){
        solve();
    }
    return 0;
}