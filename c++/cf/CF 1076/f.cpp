#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,ax,ay,bx,by;
    cin>>n>>ax>>ay>>bx>>by;
    vector<ll> x(n+1,0);
    vector<ll> y(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>x[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>y[i];
    }

    map<ll,ll> mx,mn;
    mx[ax] = mn[ax] = ay;
    mx[bx] = mn[bx] = by;
    vector<ll> dp[2];
    dp[1].resize(n+5);
    dp[0].resize(n+5);

    for(int i = 1;i<=n;i++){
        mx[x[i]] = max(mx[x[i]],y[i]);

        if(!mn.count(x[i])) mn[x[i]] = y[i];
        else mn[x[i]] = min(mn[x[i]],y[i]);
    }

    ll need = 0,qian = ax,cnt = 0;
    dp[0][0] = dp[1][0] = 0;
    for(auto i : mx){
        if(i.first == ax){
            continue;
        } 

        need = (i.first - qian) + (mx[i.first] - mn[i.first]);
        cnt++;

        dp[0][cnt] = min(dp[0][cnt-1] + abs(mx[i.first] - mn[qian]),dp[1][cnt-1] + abs(mx[i.first] - mx[qian])) + need;
        dp[1][cnt] = min(dp[0][cnt-1] + abs(mn[i.first] - mn[qian]),dp[1][cnt-1] + abs(mn[i.first] - mx[qian])) + need;

        qian = i.first;
    }
    cout<<dp[0][cnt]<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}