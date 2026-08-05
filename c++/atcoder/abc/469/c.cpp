#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s = " " + s;
    vector<ll> pre(n+1,0),ppre(n+1,0);
    vector<ll> vec;
    for(int i = 1;i<=n;i++){
        if(s[i] == 'o'){
            pre[i] = pre[i-1] + 1;
            ppre[i] = ppre[i-1];
        }
        else{
            ppre[i] = ppre[i-1] + 1;
            pre[i] = pre[i-1];
            vec.push_back(i);
        }
    }

    vector<ll> ans(n+1,0);

    for(int i = 1;i<=n;i++){
        if(i > vec.size()){
            ans[i] = n;
        }else{
            // ans[i] = vec[min((ll)vec.size()-1,pre[i] - 1 + ppre[i])];
            ans[i] = vec[i-1];
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}