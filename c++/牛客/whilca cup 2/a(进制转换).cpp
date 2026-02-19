#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

string ch(int n){
    if(n == 0) return "00";
    int x;
    char c;
    string t;
    string s;
    while(n>0){
        x = n%16;
        if(x<10){
            c = x+'0';
        }else{
            c = x + 'a' -10;
        }
        s = c+s;
        n/=16;
    }
    if(s.length() == 1){
        t = string(2-1,'0') + s;
        return t;
    }
    return s;
}

void solve(){
    string s;
    cin>>s;
    string s1 = s.substr(1,2);
    string s2 = s.substr(3,2);
    string s3 = s.substr(5,2);
    int t1 = 255 - stoi(s1, 0, 16);
    int t2 = 255 - stoi(s2,0,16);
    int t3 = 255 - stoi(s3,0,16);
    cout<<"#"<<ch(t1)<<ch(t2)<<ch(t3)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}