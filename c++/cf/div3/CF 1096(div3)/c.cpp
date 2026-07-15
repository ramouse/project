#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    vector<bool> vis(n+1,0);
    vector<ll> two,s,six,o;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]%6==0){
            six.push_back(i);
        }else if(a[i]%2==0){
            two.push_back(i);
        }else if(a[i]%3==0){
            s.push_back(i);
        }else{
            o.push_back(i);
        }
    }

    for(int i = 0;i<six.size();i++){
        cout<<a[six[i]]<<" ";
    }

    for(int i = 0;i<two.size();i++){
        cout<<a[two[i]]<<" ";
    }

    for(auto i : o) cout<<a[i]<<" ";
    for(auto i : s) cout<<a[i]<<" ";
    cout<<endl;

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