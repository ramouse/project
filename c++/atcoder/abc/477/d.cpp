#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>
#define all1(x) x.begin() + 1,x.end()
#define all0(x) x.begin(),x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

struct Node{
    bool has = false;
    char clo = 'a';
    ll tim = 0;
};

void solve()
{   
    ll n,q;
    cin>>n>>q;

    vector<Node> vec(n+1);
    char last = 'a';
    ll tim = 0;
    ll cou = 0;

    while(q--){
        cou++;
        ll op;
        cin>>op;
        if(op == 1){
            ll x;
            cin>>x;

            if(!vec[x].has){
                if(tim > vec[x].tim) vec[x].clo = last;
                vec[x].has = true;
            }else{
                vec[x].has = false;
            }
            vec[x].tim = cou;

        }else{
            char c;
            cin>>c;

            tim = cou;
            last = c;
        }
    }

    for(int i = 1;i<=n;i++){
        if(!vec[i].has && tim > vec[i].tim) cout<<last;
        else cout<<vec[i].clo;
    }
    cout<<endl;
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