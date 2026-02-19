#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n,m,l;
    cin>>n>>m>>l;
    vector<ll> x(n+1,0);
    vector<ll> pre(n+1,0);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> idx;
    for(int i = 1;i<=n;i++){
        cin>>x[i];
        pre[i] = pre[i-1] + x[i];
    }
    ll sum = 0;
    idx.push({0,l});
    for(int i = 1;i<=m;i++){
        ll y;
        cin>>y;
        sum+=y;
        idx.push({sum, sum + l});
    }

    ll i = 1;
    while(!idx.empty()){
        auto[h,q] = idx.top();
        idx.pop();

        while(i<=n && pre[i]<=h) i++;
        if(i>n) break;
        if(pre[i]<q){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}