#include <bits/stdc++.h>
using ll = long long;
using i128 = __int128_t;
using namespace std;
#define endl '\n'
 
const ll MOD = 998244353;
const ll INF = 1e18;
void solve()
{
   ll ans,sum,a,b;cin>>sum>>a>>b;ll n,m,l=1,r=1e7,p,q;i128 dag;
   if(a==1){
    cout<<sum/b+(!(sum%b==0))<<endl;return;
   }
   ll num = INF;
   while(l<=r){
        n=(l+r)/2;
         dag=n*(n+1)/2*a-n*(n+1)/2+n;
        if(dag<sum)l=n+1;
        else{
            r = n-1;
            num = min(num,n);
        }
     }
   if(a>b){
     cout<<num<<endl;return;
   }
   else {
        m=sum/b+(!(sum%b==0));
        // cout<<m<<endl;
       ans= min(num,m);
       l=1;r=ans;num=INF;
        while(l<=r){
        p=(l+r)/2;
        //dag=p+(a*p-1)*p/2+b*b/2/(1+a)
        dag=p*2*(1+a)+(a*p-1)*(1+a)*p+b*b;
        if(dag<(i128)sum*2*(1+a))l=p+1;
        else {r=p-1;
         num=min(num,p);
        }
        // cout<<num<<endl;
     }
     cout<<min(ans,num);
   }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
 
    return 0;
}