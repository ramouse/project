#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,h,l;
    cin>>n>>h>>l;
    int row = 0;
    int col = 0;
    int both = 0;

    vector<int> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
       
        if (a[i] <= h && a[i] <= l)
        {
            both++;
        }else
        if (a[i] <= h)
        {
            row++;
        }
        else if (a[i] <= l)
        {
            col++;
        }
    }
    int ans = min({row+both,col+both,(row+col+both)/2});
    cout<<ans<<endl;
    
    
   
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}