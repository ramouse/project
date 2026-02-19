#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll q;
    cin>>q;
    bool music = false;
    ll loude = 0;
    while(q--){
        ll a = 0;
        cin>>a;
        if(a == 1){
            loude++;
        }else if(a == 2){
            if(loude >= 1) loude--;
        }else if(a == 3){
            if(music) music = false;
            else music = true;
        }

        if(loude >= 3 && music) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}