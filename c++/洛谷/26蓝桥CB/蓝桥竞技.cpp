#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    ll maxx = 0;
    ll sum = 0;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxx= max(maxx,a[i]);
    }
    ll zu = sum/5;
    for(int i = 1;i<=n;i++){
        if(a[i]>zu){
            cout<<"F"<<endl;
            return;
        }
    }
    if(sum%5==0){
        cout<<"T"<<endl;
    }else{
        cout<<"F"<<endl;
    }
    
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