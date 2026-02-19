#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 1e5+5;

int tir[N][6];
int cnt[N];
int idx;

int get_id(char s){
    if(s == 'w') return 0;
    if(s == 'h') return 1;
    if(s == 'a') return 2;
    if(s == 'l') return 3;
    if(s == 'i') return 4;
    if(s == 'c') return 5;
    return 0;
}

void insert(string &s){
    int p = 0;
    for(auto c : s){
        int u = get_id(c);
        if(!tir[p][u]) tir[p][u] = ++idx;
        p = tir[p][u];
        cnt[p]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<string> s(n+1,"");
    for(int i = 1;i<=n;i++){
        cin>>s[i];
        insert(s[i]);
    }

    int shift = 0;

    while(q--){
        int o;
        cin>>o;
        if(o == 1){
            string t;
            cin>>t;
            ll ans = 0;
            int p = 0;
            for(auto c : t){
                int u = get_id(c);
                u = (u-shift+6)%6;

                if(tir[p][u]){
                    p = tir[p][u];
                    ans+=cnt[p];
                }else break;
            }
            cout<<ans<<endl;
        }else{
            shift = (shift +1)%6;
        }
    }
    return 0;
}