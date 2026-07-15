#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),del(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    stack<ll> st;
    for(int i = 1;i<=n;i++){
        while((!st.empty()) && a[st.top()] < a[i]){
            st.pop();
        }
        st.push(i);
        del[i] += i-st.size();
    }
    while(!st.empty()){
        st.pop();
    }

    for(int i = n;i;--i){
        while((!st.empty()) && a[st.top()] < a[i]){
            st.pop();
        }
        st.push(i);
        del[i] += n-i+1-st.size();
    }

    ll ans = 1e9;
    for(int i = 1;i<=n;i++){
        ans = min(ans,del[i]);
    }
    cout<<ans<<endl;

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