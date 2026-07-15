#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n+1,0),pre(n+1,0);
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        sum+=a[i];
    }
    vector<ll> c = a;
    map<ll,ll> mp;
    vector<pair<ll,ll>> vec;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(int i = 1;i<=m;i++){
        ll x,j;
        cin>>x>>j;
        pq.push({x,j});
        vec.push_back({x,j});
    }
    sort(vec.begin(),vec.end());

    ll ans = 0;
    ll cur = 0;

    for(int i = 0;i<vec.size();i++){
        ll d = vec[i].first;
        d-=cur;
        ll index = vec[i].second;
        if(pq.empty()) break;
        while(d > 0 && !pq.empty()){
            auto [s,id] = pq.top();
            pq.pop();
            s-=cur;

            if(c[id] >= d){
                ans+=d;
                sum-=d;
                c[id]-=d;
                d = 0;
                pq.push({s+cur,id});
            }else{
                ans+=c[id];
                sum-=c[id];
                d-=c[id];
                c[id] = 0;

            }
        }

        if(d > 0) break;

        sum += a[index] - c[index];
        c[index] = a[index];
        cur = vec[i].first;
    }
    ans+=sum;
    cout<<ans<<endl;

}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}