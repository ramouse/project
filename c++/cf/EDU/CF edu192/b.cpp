#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);

    ll cur = 0;
    ll id = -1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    for(int i = 1;i<=n-2;i++){
        if(a[i] == 1) cur++;
        else cur--;

        if(cur>=0){
            id = i;
            break;
        }
    }
    if(id == -1){
        cout<<"No"<<endl;
        return;
    }

    for(int i = id+1;i<=n-2;i++){
        if(a[i] == 3 && cur > 0){
            cur--;
            id++;
        }else{
            break;
        }
    }

    ll id2 = -1;
    cur = 0;
    for(int i = id+1;i<=n-1;i++){
        if(a[i] == 1 || a[i] == 2) cur++;
        else cur--;

        // cout<<cur<<" ";
        if(cur >= 0){
            id2 = i;
            break;
        }
    }
    // cout<<id2<<" ";
    if(id2 == -1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }


}

int main()
{
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}