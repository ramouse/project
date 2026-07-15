#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 998244353;

void solve()
{   
    ll n,m,t1,t2;
    cin>>n>>m>>t1>>t2;
    vector<vector<int>> vec(n+1,vector<int>(m+1,0));
    ll ans = 0;
    ll cur = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>vec[i][j];
        }
    }

    ll lie = m/t2;
    ll hang = n/t1;


    for(int h = 1;h<=n;h+=t1){
        for(int l = 1;l<=m;l+=t2){
            for(int i = h;i<=t1+h-1;i++){
                for(int j = l;j<=t2+l-1;j++){
                    cur^=vec[i][j];
                }
            }
            ans+=cur;
            cur=0;
        }
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