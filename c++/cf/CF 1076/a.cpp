#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,s,x;
    cin>>n>>s>>x;
    int total = 0;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        total += a;
    }
    int sh = s - total;
    if(sh<0){
        cout<<"No"<<endl;
    }else if(sh == 0){
        cout<<"Yes"<<endl;
    }else{
        if(sh%x==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}