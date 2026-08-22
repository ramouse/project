#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

struct Node{
    ll l,r;
    ll tfull;
    ll tl,tr,bl,br;

    ll size(){
        return r - l + 1;
    }
};

void solve()
{
    ll n;
    cin>>n;
    vector<ll> p(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>p[i];
    }

    stack<Node> st;
    for(int i = 1;i<=n;i++){
        Node cur;
        cur.l = cur.r = p[i];
        cur.tfull = 0;
        cur.tl = cur.tr = cur.bl = cur.br = 0;

        while(!st.empty()){
            Node b = st.top();
            if(cur.r+1 == b.l){
                ll strat = max(cur.tr,b.bl);
                cur.tfull = strat + cur.size() + b.size() - 1;
                cur.tl = cur.br = strat + cur.size() + b.size() - 1;
                cur.tr = strat;
                cur.bl = strat;
                cur.r = b.r;
                st.pop();
            }else if(cur.l-1 == b.r){
                ll strat = max(cur.tl,b.br);
                cur.tfull = strat + cur.size() + b.size() - 1;
                cur.bl = cur.tr = strat+cur.size()+b.size()-1;
                cur.br = strat;
                cur.tl = strat;
                cur.l = b.l;
                st.pop();
            }else break;
        }

        st.push(cur);
    }

    if(st.size() == 1){
        cout<<st.top().tfull<<endl;
    }else{
        cout<<-1<<endl;
    }
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