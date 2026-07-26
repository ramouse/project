#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);
    double ans = 0.0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin() + 1,a.end());
    for(int i = 1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    // cout<<fixed<<setprecision(2);
    // cout<<fixed<<setprecision(2)<<(double)(3 + 6)/2<<endl;
    double last = 0.0;
    ll cnt = 0;
    // for(int i = 1;i<=n-k+1;i++){
    //     double mid = 0.0;
    //     if(k & 1){
    //         mid = (double)(a[(i+i+k-1)/2]);
    //     }else{
    //         mid = (double)((a[(i+i+k-1)/2] + a[(i+i+k)/2])/2.0);
    //     }
    //     // cout<<i+i+k-1<<" ";
    //     // cout<<"mid "<<mid<<" "<<endl;
    //     // cout<<"index "<<i-1<<" "<<i+k-1<<" "<<endl;
    //     double cur = pre[n];
    //     for(int j = i;j<=i+k-1;j++){
    //         cur += (double)(mid - a[j]);
    //     }
    //     // cout<<cur<<endl;
    //     ans = max(ans,cur);
    // }

    vector<ll> vec,vvec;
    if(k&1){
        for(int i = 1;i<=k/2;i++){
            vec.push_back(a[i]);
        }
        // for(int i = n;i>=n-k/2 + 1;i--){
        //     vvec.push_back(a[i]);
        // }
    }else{
        for(int i = 1;i<=k/2 - 1;i++) vec.push_back(a[i]);
        // for(int i = n;i>=n-k/2 + 2;i--) vvec.push_back(a[i]);
    }

    if(k == 1){
        cout<<pre[n]<<endl;
        return;
    }
    // if(k == 2){
    //     for(int i = 1;i<=n-k+1;i++){
    //         double mid = 0.0;
    //         if(k & 1){
    //             mid = (double)(a[(i+i+k-1)/2]);
    //         }else{
    //             mid = (double)((a[(i+i+k-1)/2] + a[(i+i+k)/2])/2.0);
    //         }
    //         // cout<<i+i+k-1<<" ";
    //         // cout<<"mid "<<mid<<" "<<endl;
    //         // cout<<"index "<<i-1<<" "<<i+k-1<<" "<<endl;
    //         double cur = pre[n];
    //         for(int j = i;j<=i+k-1;j++){
    //             cur += (double)(mid - a[j]);
    //         }
    //         // cout<<cur<<endl;
    //         ans = max(ans,cur);
    //     }
    //     cout<<ans<<endl;
    //     return;
    // }
    for(int i = 1;i<=n;i++){
        if(k & 1){
            ll t = k/2 + 1;
            if(i<t || i>n-t+1) continue;

            double cur = pre[n];
            for(ll u : vec){
                cur += a[i] - u;
            }
            for(int j = i;j<=i + t - 1;j++){
                cur += a[i] - a[j];
            }
            ans = max(ans,cur);
        }else{
            if(i == n) continue;
            ll t = k/2;
            double mid = (a[i] + a[i+1])/2.0;
            if(i < t || i > n - t) continue;

            // cout<<mid<<endl;
            double cur = pre[n];
            for(ll u : vec){
                cur += mid - u;
            }
            for(int j = i;j<= i + t;j++){
                cur += mid - a[j];
            }
            // cout<<cur<<" ";
            ans = max(ans,cur);
        }
    }


    cout<<ans<<endl;

}

int main()
{
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}