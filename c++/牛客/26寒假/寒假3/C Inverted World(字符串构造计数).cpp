#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    string s,t;
    cin>>s;

    //按目标字符串取出位置不对的，构成一个字符串后，贪心查找要开多少条链即可
    //101..
    for(int i = 0;i<n;++i){
        if((i&1) && s[i] == '0') t+=s[i];
        if(!(i&1) && s[i] == '1') t+=s[i];
    }

    ll ans1 = 0;
    ll e1 = 0,e0 = 0;
    for(int i = 0;i<t.length();i++){
        if(t[i] == '1'){
            if(e0>0){
                e0--;
            }
            e1++;
        }else{
            if(e1>0){
                e1--;
            }
            e0++;
        }
    }
    ans1 = e1 + e0;

    //010...
    t="";
    ll ans2 = 0;
    e1 = 0,e0 = 0;
    for(int i = 0;i<n;++i){
        if((i&1) && s[i] == '1') t+=s[i];
        if(!(i&1) && s[i] == '0') t+=s[i];
    }

    for(int i = 0;i<t.length();i++){
        if(t[i] == '1'){
            if(e0>0){
                e0--;
            }
            e1++;
        }else{
            if(e1>0){
                e1--;
            }
            e0++;
        }
    }
    ans2 = e1 + e0;
    cout<<min(ans1,ans2)<<endl; 



    //101..
    // for(int i = 0;i<n;++i){
    //     if((i&1) && s[i] == '0') t+=s[i];
    //     if(!(i&1) && s[i] == '1') t+=s[i];
    // }
    // ll maxx = 0,minn = 0,now = 0;
    // for(int i = 0;i<t.length();++i){
    //     if(t[i] == '1') now++;
    //     else now--;
    //     if(now<0) now = 0;
    //     maxx = max(maxx,now);
    // }
    // now = 0;
    // for(int i = 0;i<t.length();++i){
    //     if(t[i] == '0') now++;
    //     else now--;
    //     if(now<0) now=0;
    //     minn = max(minn,now);
    // }
    // ll ans1 = max(maxx,minn);

    //010...
    // t="";
    // for(int i = 0;i<n;++i){
    //     if((i&1) && s[i] == '1') t+=s[i];
    //     if(!(i&1) && s[i] == '0') t+=s[i];
    // }
    // maxx = 0,minn = 0,now = 0;
    // for(int i = 0;i<t.length();++i){
    //     if(t[i] == '1') now++;
    //     else now--;
    //     if(now<0) now = 0;
    //     maxx = max(maxx,now);
    // }
    // now = 0;
    // for(int i = 0;i<t.length();++i){
    //     if(t[i] == '0') now++;
    //     else now--;
    //     if(now<0) now=0;
    //     minn = max(minn,now);
    // }
    // cout<<min(ans1,max(maxx,minn))<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}