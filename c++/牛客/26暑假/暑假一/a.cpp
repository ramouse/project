#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    string s;
    cin>>s;
    if(s.length() != 8){
        cout << "Well-Being"<<endl;
        return;
    }

    s = " " + s;
    bool ok = true;
    for(int i = 1;i<=s.length();i+=2){
        if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
            ok = false;
            break;
        }
    }
    for(int i = 2;i<=s.length();i+=2){
        if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "Suspected Virus"<<endl;
    }else{
        cout << "Well-Being" << endl;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}