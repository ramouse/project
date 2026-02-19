#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int main(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;

    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
    vector<vector<ll>> dist(n+1,vector<ll>(m+1,1e18)); //到达该点的最小时间
    vector<vector<ll>> time(n+1,vector<ll>(m+1,0)); //蓝格子变白的时间

    for(int i = 1;i<=a;i++){
        ll x,y;
        cin>>x>>y;
        dist[x][y] = 0;
        pq.push({0,{x,y}});
    }

    for(int i = 1;i<=b;i++){
        ll x,y,t;
        cin>>x>>y>>t;
        time[x][y] = t;
    }

    ll ans = 0;
    while(!pq.empty()){
        auto [t,z] = pq.top();
        ll x = z.first;
        ll y = z.second;
        pq.pop();
        if(t>dist[x][y]) continue;
        ans = max(ans,t);

        for(int i = 0;i<4;i++){
            ll xx = x + dx[i];
            ll yy = y + dy[i];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m){
                if(max(t+1,time[xx][yy])<dist[xx][yy]){
                    dist[xx][yy] = max(t+1,time[xx][yy]);
                    pq.push({max(t+1,time[xx][yy]),{xx,yy}});
                }
            }
        }

    }

    cout<<ans;

    return 0;
}