#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    vector<ll> dis(1e6 + 6, -1);
    if(a == b){
        cout<<0<<endl;
        return;
    }

    dis[a] = 1;
    queue<pair<ll,ll>> q;
    q.push({0,a});

    while(!q.empty()){
        auto [t,x] = q.front();
        ll nu = x;
        q.pop();

        if(x%10){
            string s = to_string(x);
            reverse(s.begin(),s.end());
            x = stoll(s);
            if(x>1e6) continue;
            if(x == b){
                cout<<t+1<<endl;
                return;
            }
            if(dis[x] == -1){
                dis[x] = t + 1;
                q.push({t + 1, x});
                
            }
        }

        if(nu+k<=1e6){
            nu += k;
            if (nu == b)
            {
                cout << t + 1 << endl;
                return;
            }
            if(dis[nu] == -1){
                dis[nu] = t + 1;
                q.push({t + 1, nu});
                
            }
        }
        

    }
    cout<<-1<<endl;

    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}