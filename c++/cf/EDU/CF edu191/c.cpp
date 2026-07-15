#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9 + 5;
const ll MOD = 676767677;
const ll INF = 1e18;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string t = s;
    s = " " + s;

    vector<ll> pre(n+1,0),suf(n+2,0);
    for(int i = 1;i<=n;i++){
        if(s[i] == '('){
            pre[i] = pre[i-1] + 1;
        }else{
            pre[i] = pre[i-1];
        }
    }

    for(int i = n;i;--i){
        if(s[i] == ')'){
            suf[i] = suf[i+1] + 1;
        }else{
            suf[i] = suf[i+1];
        }
    }

    ll cur = INF;
    ll index = -1;
    for(int i = 1;i<=n;i++){
        if(pre[i] + suf[i] <= cur){
            cur = pre[i] + suf[i];
            index = i;
        }
    }
    // cout<<index<<endl;
    string ans = string(n,'0');
    // if(k > 0){
    //     ans[index - 1] = '1';
    //     k--;
    // }

    for(int i = 1;i<index;i++){
        if(s[i] == '(' && k != 0){
            ans[i-1] = '1';
            k--;
        }else{
            ans[i-1] = '0';
        }
    }
    for(int i = index;i<=n;i++){
        if(s[i] == ')' && k!= 0){
            ans[i-1] = '1';
            k--;
        }else{
            ans[i-1] = '0';
        }
    }

    cout<<ans<<endl;
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