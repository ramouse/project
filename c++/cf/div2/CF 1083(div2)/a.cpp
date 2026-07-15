#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> p(n+1,0);
    int in = 0;
    int maxx = 0;
    vector<int> pm(n+1,0);
    vector<int> index;
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        pm[i] = max(pm[i-1],p[i]);
        if(i == pm[i]){
            index.push_back(i);
        }
        if(maxx<p[i]){
            maxx = p[i];
            in = i;
        }
    }
    swap(p[1],p[in]);

    for(int i = 1;i<=n;i++) cout<<p[i]<<" ";

    cout<<endl;
    

    

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}