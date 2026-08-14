#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<multiset<ll>> vec(n+1);
    vector<T> p(m+1);
    for(int i = 1;i<=m;i++){
        ll x,s;
        cin>>x>>s;
        p[i] = {s,x,i};
        vec[x].insert(s);
    }


    vector<ll> dist(n+1,INF);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<ll> pre(n+1,0);
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        for(ll v : adj[u]){
            if(d + 1 < dist[v]){
                dist[v] = d+1;
                pq.push({dist[v],v});
                pre[v] = u;
            }
        }
    }

    string s = string(m,'0');

    for(int i = 1;i<=m;i++){
        auto [d,u,idx] = p[i];

        while(1){
            if(u <= 1){
                break;
            }
            ll next = pre[u];
            u = next;
            d++;
            vec[next].insert(d);
        }
    }

    sort(all0(p));
    for(int i = 1;i<=m;i++){
        bool ok = true;
        auto [d,u,idx] = p[i];

        // cout<<"u: "<<u<<endl;
        // for(ll v : vec[u]){
        //     cout<<v<<" ";
        // }
        // cout<<endl;

        int cnt = 0;
        if(!vec[u].empty()){
            for (ll v : vec[u])
            {
                // cout << "i: " << i << " ";
                // cout << "u: " << u << " next: " << u << " ";
                // cout << "v: " << v << " d: " << d << endl;
                if (v == d)
                {
                    cnt++;
                }
                if (cnt == 2)
                    break;
            }
        }
        

        if(cnt >= 2){
            while(1){
                if (u <= 1)
                {
                    break;
                }
                ll next = pre[u];
                u = next;
                d++;
                vec[next].extract(d);
            }

            continue;
        }


        while(1){
            ll uu = u;
            u = pre[u];
            d++;
            cnt = 0;
            // cout << "u: " << u << endl;
            // for (ll v : vec[u])
            // {
            //     cout << v << " ";
            // }
            // cout << endl;
            if (!vec[u].empty())
            {
                for (ll v : vec[u])
                {
                    // cout<<"i: "<<i<<" ";
                    // cout<<"u: "<<uu<<" next: "<<u<<" ";
                    // cout<<"v: "<<v<<" d: "<<d<<endl;
                    if(v == d){
                        cnt++;
                    }
                    if (cnt == 2)
                        break;
                }
            }

            if(cnt == 2){
                ok = false;
                while (1)
                {
                    if (u <= 1)
                    {
                        break;
                    }
                    ll next = pre[u];
                    u = next;
                    d++;
                    vec[next].extract(d);
                }
                break;
            }
            if(u <= 1){
                break;
            }
        }
        if(ok){
            s[idx-1]='1';
        }else{
            // s+='0';
        }
    }   
    cout<<"a"<<endl;
    cout<<s<<endl;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}