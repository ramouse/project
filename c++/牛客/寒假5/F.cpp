#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;

    // 1. 策略 zu: 尽可能 1:1 配对 (n/8)
    ll zu = n /8;
    ll sh = n%8;
    ll res1 = zu*(a+b) + max(sh>=7 ? a:0,sh/2 *b);

    // 2. 策略 zu1: 全做 td (n/2)
    ll zu1 = n/2;
    ll sh1 = n%2;
    ll res2 = zu1 * b;

    // 3. 策略 zu2: 尽可能多做 qcjjkkt (n/7)
    ll zu2 = n/7;
    ll sh2 = n%7;
    // 公式逻辑：先用剩余字符给 qcjjkkt 配 d (每个b耗1字符)，剩下的再做独立 td (每个b耗2字符)
    ll res3 = zu2 * a + min(zu2,sh2) * b+ (sh2 - min(zu2,sh2))/2 * b;

    // 4. 策略 zu3: 补漏情况 (n/8 + 1)
    //可能全局最优解在 n/8和n/7之间
    ll zu3 = n/8+1;
    ll sh3 = n - zu3*7;
    ll res4 = zu3*7<=n ? zu3*a+min(zu3,sh3)*b+(sh3-min(zu3,sh3)) / 2 *b : 0;

    cout<<max({res1,res2,res3,res4})<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}