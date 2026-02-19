#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);

        for(int i = 1;i<=n;i++) cin>>a[i];
        for(int i = 1;i<=n;i++) cin>>b[i];

        ll c = 0,d = 0;
        ll last = 0;
        for(int i = 1;i<=n;i++){
            if(i&1){
                if(a[i] != b[i]){
                    c++;
                    last = i;
                }
            }else{
                if(a[i] != b[i]){
                    d++;
                    last = i;
                }
            }
        }
        
        if((c+d)%2 == 0){
            cout<<"Tie"<<endl;
        }else{
            if(last&1){
                cout<<"Ajisai"<<endl;
            }else{
                cout<<"Mai"<<endl;
            }
        }
    }
    return 0;
}