#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;

    //解法一：
//------------------------------------------------------------

    // vector<ll> a(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // ll front = 0;
    // ll back = -a[n - 1];
    // for (int i = n - 2; i >= 1; i--)
    // {
    //     ll s = max(a[i] + front, back);

    //     ll next_f = max(s, front - a[i]);
    //     ll next_b = back - a[i];

    //     front = next_f;
    //     back = next_b;
    // }

    // cout << max(a[0] + front, back) << endl;


    //解法二：
//------------------------------------------------------------

    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);//维护一个-a[i]的前缀和
    vector<ll> suf(n+1,0);//维护一个除a[1]外 abs(a[i])的前缀和

    //之所以要这么维护，是因为我们的解法是枚举每一个孩子未被选中时的最大值，从而得出全局最大值
    //注意到，一个未被选中的孩子的左侧，我们总是可以使其贡献为正数(除第一个孩子以外)；所以我们维护一个suf[i]来预处理数据
    //一个未被选中的孩子的右侧，我们发现，其所有孩子的贡献只能是-a[i]，所以我们维护了一个pre[i]来预处理数据



    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]-a[i];
        if(i>1){
            suf[i] = suf[i - 1] + abs(a[i]);
        }else{
            suf[i] = suf[i - 1] + a[i];
        }
    }

    ll ans = -2e9;
    for(int i = 1;i<=n;i++){
        ll temp = 0;
        temp = suf[i-1] + (pre[n] - pre[i]);
        ans = max(temp,ans);
    }
    cout<<ans<<endl;
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}