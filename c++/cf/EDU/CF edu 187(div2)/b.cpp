#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll x;
    cin>>x;
    
    string s = to_string(x);
    ll len = s.length();

    ll sum = 0;
    vector<pair<ll,ll>> p;
    for(int i = 1;i<len;i++){
        sum+=s[i] - '0';
        p.push_back({s[i]-'0',i});
    }
    sum+=s[0]-'0';
    sort(p.begin(),p.end(),greater<pair<ll,ll>>());

    if(sum<=9){
        cout<<0<<endl;
        return;
    }

    ll summ = sum;
    ll ans = 0;
    for(int i = 0;i<p.size();i++){
        if(summ<=9) break;
        summ -= p[i].first;
        ans++;
    }

    sum-=s[0]-'0';
    sum+=1;
    ll ans1 = 0;
    if(s[0] !='1') ans1++;

    for(int i = 0;i<p.size();i++){
        if(sum<=9) break;
        sum -= p[i].first;
        ans1++;
    }

    cout<<min(ans,ans1)<<endl;

    
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}