#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> a(n+1);
    for(int i = 1;i<=n;i++){
        ll l;
        cin>>l;
        vector<ll> t(l+1,0);
        for(int i = 1;i<=l;i++){
            cin>>t[i];
        }
        reverse(t.begin()+1,t.end());
        set<ll> in;
        for(int j = 1;j<=l;j++){
            if(!in.count(t[j])){
                a[i].push_back(t[j]);
                in.insert(t[j]);
            }
        }
    }

    vector<ll> ans;
    set<ll> in;
    vector<bool> vis(n+1,0);

    for(int i = 1;i<=n;i++){
        ll id = -1;
        vector<ll> best(n,1e7);

        for(int j = 1;j<=n;j++){
            if(vis[j]) continue;
            
            vector<ll> cur;
            for(ll x:a[j]){
                if(!in.count(x)){
                    cur.push_back(x);
                }
            }

            if(cur<best){
                id = j;
                best = cur;
            }
        }

        for(ll x : best){
            if(!in.count(x)){
                ans.push_back(x);
                in.insert(x);
            }
        }
        vis[id] = true;
    }

    for(ll x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}