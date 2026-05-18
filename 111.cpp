#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 10007;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n+1,vector<int>(m+1,0)),pre(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>vec[i][j];
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + vec[i][j];
        }
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int ii = i;ii<=n;ii++){
                for(int jj = j;jj<=m;jj++){
                    if((pre[ii][jj]-pre[i-1][jj] - pre[ii][j-1] + pre[i-1][j-1]) * 2> (ii-i+1)*(jj-j+1)){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
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