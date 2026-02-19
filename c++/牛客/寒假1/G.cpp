#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


void solve(){
    string L,R;
    cin>>L>>R;
    string t = "1";
    for(int i = 1;i<R.length();i++){
        t+='0';
    }

    if(R == t){
        if(L==R) cout<<1<<endl;
        else cout<<stoll(R)-1<<endl;
        return;
    }
    if (L.size() < R.size())
    { 
        L = t;
        L.back() += 1;
        assert(L.size() == R.size());
    }

    ll k = -1;
    for(int i = 0;i<R.length();i++){
        if(L[i] != R[i]){
            k = i;
            break;
        }
    }
    string ans;
    if (k == -1)
    {
        ans = L;
        while (ans.size() > 1 && ans.back() == '0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
    }
    else
    {
        bool ok = 1;
        for (int i = k + 1; i < R.length(); i++)
        {
            ans += '9';
            ok &= (R[i] == '9');
        }
        ans += (R[k] - !ok);
        for (int i = k - 1; i >= 0; i--)
        {
            ans += L[i];
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}