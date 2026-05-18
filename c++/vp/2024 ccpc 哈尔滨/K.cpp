#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct Node{
    ll w,l,r;
};

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<Node> vec(n+1);
    vector<ll> preval(n+1,0);
    vector<ll> pretime(n+1,0);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>vec[i].w>>vec[i].l>>vec[i].r;
        ans+=vec[i].w * vec[i].l;
    }
    sort(vec.begin()+1,vec.end(),[&](const auto& x,const auto& y){
        return x.w>y.w;
    });

    ll t = m;
    for(int i = 1;i<=n;i++){
        preval[i] = preval[i-1] + vec[i].w * (vec[i].r - vec[i].l);
        pretime[i] = pretime[i-1] + vec[i].r - vec[i].l;
        t-=vec[i].l;
    }
    ll sum = ans;
   

    for(int i = 1;i<=n;i++){
        ll cur = sum - vec[i].w * vec[i].l;
        ll tt = t + vec[i].l;
        if(tt>=pretime[i-1]){
            cur+=preval[i-1];
            tt-=pretime[i-1];
            cur+=tt*vec[i].w;            
        }else{
            ll idx = upper_bound(pretime.begin(),pretime.end(),tt)-pretime.begin()-1;
            cur+=preval[idx];
            tt-=pretime[idx];
            if(tt>0){
                cur+=vec[idx+1].w*tt;
            }
        }
        ans = max(ans,cur);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}