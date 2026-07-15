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
        return;
    }

    auto check = [&](string s) -> string{
        string t;
        for(char& c : s){
            t+=c;
            if(t.size() >= 4){
                string tt;
                ll in = 4;
                for(int i = t.length() - 4;i<t.length();i++){
                    tt+=t[i];
                }
                if(tt == "(xx)"){
                    t.erase(t.end()-4,t.end());
                    t+="xx";
                }
            }
        }
        return t;
    };

    if(check(a) == check(b)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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