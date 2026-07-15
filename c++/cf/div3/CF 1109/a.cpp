#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s = " " + s;
    ll ans = 0;
    ll cur = 0;
    for(int i = 1;i<=n;i++){
        if(s[i] == '#'){
            cur++;
        }else{
            cur=0;
        }
        ans = max(ans,cur);
    }
    ans = max(ans,cur);
    
    cout<<(ans + 1)/2<<endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}