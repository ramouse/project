#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    string t;
    cin>>t;

    ll total = 0;
    for(int i = 0;i<t.length();i++){
        total += t[i]-96;
    }

    
    string s1 = "promise";
    string s2 = "esimorp";
    string s3 = "promisesimorp";
    ll a1 = 'p'-96+'r'-96+'o'-96+'m'-96+'i'-96+'s'-96+'e'-96;
    ll a2 = a1*2 -('e'-96);
    ll a3 = a1*2;

    ll p = 2 * t.length();

    if(total>=a2 && total<a3){
        ll diff = total - a2;
        char c = diff/2;
        cout<<c<<s3<<c<<endl;
    }else if(total>=a3){
        if(total&1){
            string s4 = "promiseaesimorp";
            ll diff = total - a3 - ('a'-96);
        }else{
            string s4 = "promiseesimorp";
        }
    }


}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}