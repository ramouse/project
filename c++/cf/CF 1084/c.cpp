#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    stack<char> st;
    for(int i = 0;i<s.length();i++){
        if(!st.empty()){
            if(st.top() == s[i]){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);
    }

    if(st.empty()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}