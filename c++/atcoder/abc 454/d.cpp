#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"Yes"<<endl;
    }

    stack<char> st;
    ll c = 0;
    for(int i = 0;i<a.length();i++){
        if(st.top() == '('){
            if(a[i] == ')' && c>=2){
                st.pop();
            }else{
                st.push(a[i]);
            }
        }else{
            if(a[i] == 'x'){
                c++;
                
            }

        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin>>t;

    while (t--)
    {
        solve();
    }
    return 0;
}