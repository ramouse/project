#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    
    vector<ll> vec;
    vec.push_back(0);
    ll cur = 1;
    for(int i = 2;i<=n;i++){
        if(a[i] == a[i-1]){
            cur++;
        }else{
            vec.push_back(cur);
            cur = 1;
        }
    }
    vec.push_back(cur);

    ll m = vec.size() - 1;
    sort(vec.begin() +1,vec.end());
    vector<ll> suf(m+2,0);
    for(int i = m;i;i--){
        suf[i] = vec[i] + suf[i+1];
    }
    ll ans = 0;
    for(int i = 1;i<=m;i++){
        if(i == 1 || vec[i] != vec[i-1]){
            cur = vec[i];
            ll sh = suf[i] - (m - i + 1) * (cur - 1);
            if (k >= sh && (k - sh) % (m - i + 1) == 0)
            {
                ans++;
            }
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