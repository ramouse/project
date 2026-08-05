#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> b = a;
    vector<ll> last = a;
    ll cnt = 0;
    for(int i = 1;i<=50;i++)
    {
        if(i == k){
            if (i & 1)
            {
                for (int j = 0; j < n; j++)
                {
                    ll mex = 0;
                    set<ll> se;
                    se.insert(a[j]);
                    se.insert(a[(j + 1) % n]);
                    se.insert(a[(j + n - 1) % n]);
                    while (se.count(mex))
                    {
                        mex++;
                    }
                    b[j] = mex;
                }
                for(int j = 0;j<n;j++){
                    cout<<b[i]<<" ";
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    ll mex = 0;
                    set<ll> se;
                    se.insert(b[j]);
                    se.insert(b[(j + 1) % n]);
                    se.insert(b[(j + n - 1) % n]);
                    while (se.count(mex))
                    {
                        mex++;
                    }
                    a[j] = mex;
                }
                for(int j = 0;j<n;j++){
                    cout<<a[j]<<" ";
                }
                
            }
            return;
        }
        if (i & 1)
        {
            for (int j = 0; j < n; j++)
            {
                ll mex = 0;
                set<ll> se;
                se.insert(a[j]);
                se.insert(a[(j + 1) % n]);
                se.insert(a[(j + n - 1) % n]);
                while (se.count(mex))
                {
                    mex++;
                }
                b[j] = mex;
            }
        }
        else
        {
            last = a;
            for (int j = 0; j < n; j++)
            {
                ll mex = 0;
                set<ll> se;
                se.insert(b[j]);
                se.insert(b[(j + 1) % n]);
                se.insert(b[(j + n - 1) % n]);
                while (se.count(mex))
                {
                    mex++;
                }
                a[j] = mex;
            }
            if(last == a){
                cnt = i;
                break;
            }
        }
    }
    // cout<<cnt<<endl;
    if((k - cnt) & 1){
        for(int i = 0;i<n;i++){
            cout<<b[i]<<" ";
        }
    }else{
        for(int i = 0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}