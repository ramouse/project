#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<string> vec(n+1);
    for(int i = 1;i<=n;i++){
        cin>>vec[i];
    }
    vector<ll> d(m+1,0);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<m;j++){
            if(vec[i][j] == '1'){
                d[j]++;
            }
        }
    }

    for(int i = 1;i<=n;i++){
        ll pre = 0;
        for(int j = 0;j<m;j++){
            if(vec[i][j] == '1'){
                pre+=n-d[j];
            }else{
                pre+=d[j];
            }
        }

        vector<ll> c(m+1,0);
        for(int j = 0;j<m;j++){
            if(vec[i][j] == '1') c[j] = 2*d[j]-n-1;
            else c[j] = n - 2*d[j]-1;
        }

        ll cur = 0;
        ll minn = 0;
        for(int j = 0;j<m;j++){
            cur = min(c[j],cur+c[j]);
            minn = min(cur,minn);
        }
        cout<<pre+minn<<endl;
    }

}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}