#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> a(2*n+2,0);
    vector<ll> ans(n+1,0);
    vector<ll> vec(n+1,0),v(n+1,0);
    // k--;
    ans[k] = x;
    ll sum = 0;
    ll index = -1;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(a[i] == x){
            index = i;
        }
    }

    for(int i = n;i<2*n;i++){
        a[i] = a[i-n];
    }

    // for(int i = 0;i<2*n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    // cout<<k<<" "<<index<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[(i + index - k + n) % n] << " ";
    }

    // ans[0] = 1,ans[1] = 3,ans[2] = 2,ans[3] = 0;
    // for(int i = index - k+1;i<=index - k + n;i++){
    //     cout<<a[i]<<" ";
    // }
    // for(int i = 0;i<n;i++){
    //     cout<<a[i + index - k]<<" ";
    // }
    // for(int i = 0;i<n;i++){
    //    sum += (n - i - 1) * (-1 * ans[i]) + (i)*ans[i];
    // }
    // cout<<sum;
    // for(int i = 0;i<n;i++){
    //     cout<<vec[i]<<" "<<v[i]<<endl;
    // }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}