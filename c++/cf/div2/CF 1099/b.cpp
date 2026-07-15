#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    
    ll k = 0;
    for(int i = 2;i<=n;i++){
        if(a[i-1]>a[i]){
            k = max(k,a[i-1] - a[i]);
        }
    }

    ll p = a[1];
    for(int i = 2;i<=n;i++){
        if(a[i]>=p){
            p = a[i];
        }else if(a[i] + k >= p){
            p = a[i] + k;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    
    
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