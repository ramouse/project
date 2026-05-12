#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    
    vector<vector<ll>> bit(n+1,vector<ll>(32,0));
    vector<int> vis(32,0);
    ll co = 0;
    for (int j = 0; j <= 31; j++)
    {
        if((x>>j)&1){
            vis[j]=1;
            co++;
        }
    }
    for(int i = 1;i<=n;i++){
        
        for(int j = 0;j<=31;j++){
            if((a[i]>>j)&1){
                bit[i][j]++;
            }
        }
        bool ok = true;
        for (int j = 0; j <= 31; j++)
        {
            if ((a[i] >> j) & 1)
            {
                if(!vis[j]){
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            for (int j = 0; j <= 31; j++)
            {
                if ((a[i] >> j) & 1)
                {
                    if(vis[j]==1){
                        vis[j]=2;
                        co--;
                    }
                }
            }
        }
        if(co==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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