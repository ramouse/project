#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll,ll,ll>
#define pll pair<ll,ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;
const ll N = 1e6+10;

struct Node{
    ll l,r,id;
};

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    ll block = sqrt(n);
    vector<ll> cnt(N,0);
    vector<ll> sum(N,0);
    vector<ll> ans(q+1,0);
    ll maxx = 0;

    vector<Node> qu(q+1);
    for(int i = 1;i<=q;i++){
        cin>>qu[i].l>>qu[i].r;
        qu[i].id = i;
    }
    sort(qu.begin(),qu.end(),[&](const Node&x,const Node&y){
        if(x.l/block != y.l/block) return x.l/block < y.l/block;
        else return x.r<y.r;
    });

    auto add = [&](ll pos) ->void{
        ll x = a[pos];
        sum[cnt[x]]--;
        cnt[x]++;
        sum[cnt[x]]++;
        maxx = max(maxx,cnt[x]);
    };

    auto del = [&](ll pos) -> void{
        ll x = a[pos];
        sum[cnt[x]]--;
        if(cnt[x] == maxx && sum[cnt[x]] == 0) maxx--;
        cnt[x]--;
        sum[cnt[x]]++;
    };

    ll l = 1,r = 0;
    for(int i = 1;i<=q;i++){
        ll ql = qu[i].l;
        ll qr = qu[i].r;
        ll id = qu[i].id;

        while(l>ql) add(--l);
        while(r<qr) add(++r);
        while(l<ql) del(l++);
        while(r>qr) del(r--);

        // ans[id] = maxx;
        for(auto nu : cnt){
            ans[id] = max(ans[id],nu);
        }
    }

    for(int i = 1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
    
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}