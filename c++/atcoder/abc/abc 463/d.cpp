#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 676767677;

struct Node{
    ll l,r;
};

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<Node> vec(n+1);
    for(int i = 1;i<=n;i++){
        cin>>vec[i].l>>vec[i].r;
    }  
    sort(vec.begin()+1,vec.end(),[&](const auto&x,const auto&y){
        if(x.r != y.r) return x.r<y.r;
        else return x.l<y.l;
    });

    auto check = [&](ll mid) -> bool{
        ll lastr = vec[1].r;
        ll co = 1;
        for(int i = 2;i<=n;i++){
            if(vec[i].l - lastr >= mid){
                co++;
                lastr = vec[i].r;
            }
            if(co == k) return true;
        }
        return false;
    };

    ll l = 1,r = 1e9;
    ll ans = -1;
    while(l<=r){
        ll mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}