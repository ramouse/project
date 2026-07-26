#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve() {
    ll n,a,b;
    cin>>n>>a>>b;

    ll cnt = 0;
    ll t = a^b;
    for(int i = 0;i<=n-1;i++){
        if(t>>i&1) cnt++;
    }
    if(!(cnt & 1)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
        return;
    }

    vector<bool> vis((1<<n),0);
    vis[a] = 1,vis[b] = 1;

    vector<pair<ll,ll>> ans;
    for(int i = 0;i<(1<<n);i++){
        if(vis[i]) continue;
        for(int j = i+1;j<(1<<n);j++){
            if(vis[i] || vis[j]) continue;
            else{
                ll now = i^j;
                cnt = 0;
                for(int k = 0;k<n;k++){
                    if(now>>k&1) cnt++;
                }
                if(cnt != 2) continue;
                cout<<i<<" "<<j<<endl;
                vis[i] = 1;
                vis[j] = 1;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}