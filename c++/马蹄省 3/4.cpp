#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 998244353;

void solve()
{   
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        if(r-l+1<3){
            cout<<"No"<<endl;
        }else{
            ll cur = 1;
            bool ok = false;
            vector<ll> low(n+1,0);
            ll len = 0;
            for(int i = l;i<=r;i++){
                if(a[i] > low[len]){
                    
                    len++;
                    low[len] = a[i];
                }else if(a[i] < low[len]){
                    ll idx = lower_bound(low.begin()+1,low.begin()+len+1,a[i])-low.begin();
                    low[idx] = a[i];
                }
                if(len>=3){
                    ok = true;
                    break;
                }
            }
            // len = 1;
            // low[l] = 1;
            // for(int i = l+1;i<=r;i++){
            //     low[i] = 1;
            //     for(int j = l;j<i;j++){
            //         if(a[j]<a[i]){
            //             low[i] = max(low[i],low[j]+1);
            //             len = max(len,low[i]);
            //         }
            //         if(len >= 3){
            //             ok = true;
            //             break;
            //         }
            //     }
            //     if(len>=3){
            //         ok = true;
            //         break;
            //     }
            // }
            
            if(ok){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
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