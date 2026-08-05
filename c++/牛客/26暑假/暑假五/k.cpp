#include<bits/stdc++.h> 
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;


void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n,0);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }


    vector<ll> b = a;
    bool ok1 = false;
    while(1){
        k--;
        vector<ll> v = b;
        for (int i = 0; i < n; i++)
        {
            ll mex = 0;
            set<ll> se;
            se.insert(v[i]);
            se.insert(v[(i + 1) % n]);
            se.insert(v[(i + n - 1) % n]);
            while (se.count(mex))
            {
                mex++;
            }
            b[i] = mex;
        }
        vector<ll> vec = b;
        sort(vec.begin(),vec.end());
        ll num = 0;
        bool ok = true;
        for(int i = 0;i<n;i++){
            if(vec[i] == num){
                num++;
            }else{
                ok = false;
                break;
            }
        }
        if(ok) break;

        if(vec[0] == vec[n-1]){
            ok1 = true;
            break;
        }

        if(k == 0) break;
    }
    
    // cout<<k<<endl;
    if(ok1){
        // cout<<"ok1"<<endl;
        if(k > 0){
            for(int i = 0;i<n;i++){
                cout<<0<<" ";
            }
        }else{
            for(int i = 0;i<n;i++){
                cout<<b[i]<<" "; 
            }
        }
        return;
    }

    if(k == 0){
        for(int i = 0;i<n;i++){
            cout<<b[i]<<" ";
        }
    }else{
        a = b;
        for (int i = 0; i < n; i++)
        {
            ll mex = 0;
            set<ll> se;
            se.insert(b[i]);
            se.insert(b[(i + 1) % n]);
            se.insert(b[(i + n - 1) % n]);
            while (se.count(mex))
            {
                mex++;
            }
            a[i] = mex;
        }
 
        if(k&1){
            for(int i = 0;i<n;i++){
                cout<<a[i]<<" ";
            }
        }else{
            for(int i = 0;i<n;i++){
                cout<<b[i]<<" ";
            }
        }
    }
    
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}