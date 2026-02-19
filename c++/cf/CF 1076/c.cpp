#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1;i<=n;i++){
        if(b[i]>a[i]) a[i] = b[i];
    }

    vector<int> suf(n+2,0);
    for(int i = n;i;--i){
        suf[i] = max(a[i],suf[i+1]);
    }

    vector<int> pre(n+1,0);
    for(int i = 1;i<=n;i++){
        pre[i] = pre[i-1] + suf[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<pre[r] - pre[l-1]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}