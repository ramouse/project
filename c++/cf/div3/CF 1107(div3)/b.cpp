#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

// vector<ll> vec;

// void init(){
//     set<ll> se;

//     for(int i = 0;i<=9;i++){
//         for(int j = i;j<=9;j++){
//             queue<ll> q;
//             if(i != 0) q.push(i);
//             if(j != 0 && j != i) q.push(j);

//             while(!q.empty()){
//                 ll u = q.front();
//                 q.pop();

//                 if(u >= 2 && u<=N){
//                     se.insert(u);
//                 }
//                 if(u >= N /10) continue;

//                 if(u * 10 + i <= N){
//                     q.push(u * 10 + i);
//                 }
//                 if(u * 10 + j <= N && i != j){
//                     q.push(u * 10 + j);
//                 }
//             }
            
//         }
//     }
//     for(ll v : se){
//         vec.push_back(v);
//     }
// }

void solve(){
    ll x;
    cin>>x;
    
    ll len = 0;
    ll t = x;
    ll ans = 1;
    while(t){
        t/=10;
        len++;
        ans *= 10;
    }

    cout<<ans + 1<<endl;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    // init();
    while(t--){
        solve();
    }
    return 0;
}