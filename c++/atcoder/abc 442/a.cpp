#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    string s;
    cin>>s;
    ll ans = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == 'i' || s[i] == 'j') ans++;
    }
    cout<<ans;
}