#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll N1 = -1e9;



void solve(){
    ll n;
    cin>>n;
    bool ok = false;
    ll idx = 1;
    ll idx1 = 2;

    auto ask = [&](ll u,ll v){
        cout<<"? "<<u<<" "<<v<<endl;
        cout.flush();

        ll c;
        cin>>c;
        if(c){
            ok = true;
            idx = u;
            idx1 = v;
        }
    };

    ask(1,2);
    ask(2, 3);
    ask(1,3);
    
    if(ok){
        cout<<"! "<<idx<<endl;
        return;
    }

    for(int i = 4;i<=2*n-1;i+=2){
        ask(i,i+1);
    }

    if(ok){
        cout<<"! "<<idx<<endl;
    }else{
        cout<<"! "<<2*n<<endl;
    }

}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}