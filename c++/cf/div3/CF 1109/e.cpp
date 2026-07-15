#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s = " " + s;

    ll cur = 1;
    char last = s[1];
    ll lasto = 0;
    ll lastz = 0;
    vector<ll>  pre(n+1,0);
    for(int i = 2;i<=n;i++)
    {   
        if(s[i] == s[i-1]){
            pre[i] = pre[i-1] + 1;
        }else{
            pre[i] = pre[i-1];
        }
    }

    // for(int i = 1;i<=n;i++){
    //     cout<<pre[i]<<" ";
    // }


    // for(int i = 1;i<=n;i++){
    //     cout<<ppo[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 1;i<=n;i++){
    //     cout<<ppz[i]<<" ";
    // }
 

    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        
        if((pre[r] - pre[l] + 1)/2 <= k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}