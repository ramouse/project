#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 676767677;

void solve(){
    ll n;
    cin>>n;
    vector<ll> p(n+1,0),q(n+1,0);
    string s,t;
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        s+=(p[i] + '0' + '0');
    }
    for(int i = 1;i<=n;i++){
        cin>>q[i];
        t+=(q[i] + '0' + '0');
    }
    // s = " " + s;
    // t = " " + t;
    // cout<<s<<" "<<t;

    queue<pair<string,ll>> qu;
    // if(p[1] > q[1]){
    //     cout<<0<<endl;
    //     return;
    // }

    for(int i = 1;i<=n;i++){
        string tt;
        tt += i + '0' + '0';
        qu.push({tt,1});
    }
    
    ll ans = 0;
    while(!qu.empty()){
        auto [tt,d] = qu.front();
        qu.pop();

        if(d==n){
            if(tt > s && tt < t){
                ans++;
                continue;
            }
        }

        vector<bool> vis(n+2,0);
        // cout<<"tt:"<<tt<<" "<<d<<endl;
        for(char c : tt){
            // cout<<c-'0'<<endl;
            vis[c-'0'-'0'] = 1;
        }
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                string ttt = tt;
                ttt += (i + '0'+'0');
                qu.push({ttt,d+1});
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cout<<'j'-'0'-'0'<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}