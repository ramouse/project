#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0);
    ll maxx = 0;
    ll id = 0;
    deque<ll> dq;
    vector<ll> pre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        if(a[i]>a[pre[i-1]]){
            pre[i] = i;
        }else{
            pre[i] = pre[i-1];
        }
    }
    
    ll idx = pre[min(k+1,n)];
    for(int i = idx;i<=n;i++){
        cout<<a[i]<<" ";
    }
    for(int i = 1;i<idx;i++){
        dq.push_back(a[i]);
    }
    for(int i = 1;i<=k-1;i++){
        ll f = dq.front();
        dq.pop_front();
        ll se = dq.front();
        dq.pop_front();

        if(f>se){
            cout<<se<<" ";
            dq.push_front(f);
        }else{
            cout<<f<<" ";
            dq.push_front(se);
        }
    }
    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout<<endl;
    // if(k>=id){
    //     for(int i = id;i<=n;i++){
    //         cout<<a[i]<<" ";
    //     }
    //     for(int i = 1;i<id;i++){
    //         cout<<a[i]<<" ";
    //     }
    // }else{
    //     ll p = 1;
    //     for(int i = 1;i<=k;i++){
    //         ll f = dq.front();
    //         dq.pop_front();
    //         ll se = dq.front();
    //         dq.pop_front();

    //         if(f>se){
    //             dq.push_back(se);
    //             dq.push_front(f);
    //         }else{
    //             dq.push_back(f);
    //             dq.push_front(se);
    //         }
    //     }
    //     while(!dq.empty()){
    //         cout<<dq.front()<<" ";
    //         dq.pop_front();
    //     }
    // }
    // cout<<endl;
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