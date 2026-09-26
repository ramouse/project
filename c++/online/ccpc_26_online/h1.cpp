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

void solve()
{
    string s;
    cin >> s;
    if (s == "first")
    {
        ll n;
        cin >> n;
        vector<ll> p(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        ll s[n][n];
        // for(ll i=0;i<n-2;i++){
        //     for(ll j=0;j<n-1;j++){
        //         if(i==j)s[i][j]=p[n-1];
        //         else s[i][j]=p[j];
        //     }
        // }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n-1;j++){
                if(i==j)s[i][j]=p[n-1];
                else s[i][j]=p[j];
            }
        }
        for(ll i=0;i<n;i++)s[i][n-1]=p[i];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n-1;j++){
                cout<<s[i][j]<<" ";
            }
            cout<<s[i][n-1]<<endl;
        }
    }
    else
    {
        ll n;
        cin >> n;
        ll temp1,temp2,temp3;
        vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> vec[i][j];
            }
        }
        ll sum=0,h=n*(n+1)/2;
        for(ll i=0;i<n-1;i++){
            temp1=vec[0][i];
            temp2=vec[1][i];
            temp3=vec[2][i];
            if(temp1==temp2||temp1==temp3){cout<<temp1<<" ";sum+=temp1;}
            else {cout<<temp2<<" ";sum+=temp2;}
        }
        cout<<h-sum<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}