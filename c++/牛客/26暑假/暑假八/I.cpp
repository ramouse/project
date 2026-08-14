#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>
#define all1(x) x.begin() + 1,x.end()
#define all0(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(2*n+1,0);
    for(int i = 1;i<=2*n;i++){
        cin>>a[i];
    }
    ll num = a[1];
    ll ans1 = 0;
    ll ans2 = 0;
    if(a[2]>num+m){
        ans1++;
    }
    if(a[2] + m > num){
        ans2++;
    }
    for(int i = 3;i<=2*n;i+=2){
        ll n1 = num+m - a[i];
        ll n2 = num+m - a[i+1];
        if(n1 < 0 && n2 < 0){
            ans1+=2;
        }else if(n1 < 0 || n2<0){
            ans1++;
        } else
        if(n1 + n2 < m){
            ans1++;
        }

        ll req1 = max(0LL, num - a[i]);
        ll req2 = max(0LL, num - a[i + 1]);

        if (req1 + req2 < m)
        {
            ans2 += 2;
        }
        else if (req1 < m || req2 < m)
        {
            ans2 += 1;
        }
    }

    cout<<ans1<<" "<<ans2<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}