#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(m+1);
    vector<ll> F[m+1];
    for(int i = 1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        F[u].push_back(i);
        F[v].push_back(i);
        a[v].second++;
        a[u].second++;
    }
    sort(a.begin()+1,a.end(),[](const auto&x,const auto&y){
        return x.second>y.second;
    });
    ll maxx = a[1].second;
    vector<ll> v;
    for(int i = 1;i<=m;i++){
        if(a[i].second == maxx){
            v.push_back(i);
        }
    }
    

    vector<bool> vis(n + 1, 0);
    vector<ll> vv;
    if(v.size() == 1){
        ll ma = -1;
        
        bool f = false;
        for(int i = 1;i<=m;i++){
            if(a[i].second != maxx && !f){
                ma = a[i].second;
                f = true;
            }
            if(a[i].second == ma){
                vv.push_back(i);
            }
        }
        
        
        ll ans = 0;
        for(auto &x:vv){
            for(auto &y:F[x]){
                if(!vis[y]){
                    ans++;
                    vis[y] = true;
                }
            }
            
        }

        cout<<ans<<endl;
        return;
    }else{
        ll ans = 0;
        for(auto&x:v){
            for(auto &y:F[x]){
                if(!vis[y]){
                    ans++;
                    vis[y] = true;
                }
            }
        }
        cout<<ans<<endl;
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