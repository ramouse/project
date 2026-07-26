#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll LOG = 31;
const ll MOD = 998244353;

void solve()
{  //qing hou zu yo 0123
    // ll state;
    // ll n;cin>>n;
    // ll arrx[n];ll arry[n];for(ll i=0;i<n;i++){cin>>arrx[i];cin>>arry[i];}
    //  for(ll i=1;i<n-1;i++){
    // if(arrx[i]==arrx[i-1]){
    //     if (arry[i] > arry[i - 1]){
    //         if(arrx[i+1]>arrx[i])
    //             cout << "RIGHT" << " ";
    //         else if (arrx[i + 1]<arrx[i])
    //             cout << "LEFT" << " ";
    //         else cout<<"STRAIGHT ";
    //     }
    //     if (arry[i] < arry[i - 1])
    //     {
    //         if (arrx[i + 1] > arrx[i])
    //             cout << "LEFT ";
    //         else if (arrx[i + 1] < arrx[i])
    //             cout << "RIGHT ";
    //         else
    //             cout << "STRAIGHT ";
    //     }
    // }
    // if(arry[i]==arry[i-1]){
    //     if (arrx[i] >arrx[i - 1])
    //     {
    //         if (arry[i + 1] >arry[i])
    //             cout << "LEFT ";
    //         else if (arry[i + 1] < arry[i])
    //             cout << "RIGHT ";
    //         else
    //             cout << "STRAIGHT ";
    //     }
    //     if (arrx[i] < arrx[i - 1])
    //     {
    //         if (arry[i + 1] < arry[i])
    //             cout << "LEFT ";
    //         else if (arry[i + 1] > arry[i])
    //             cout << "RIGHT ";
    //         else
    //             cout << "STRAIGHT ";
    //     }
    // }

    //  }
    //  cout<<endl;
    ll n;
    cin>>n;
    vector<ll>x(n);
    vector<ll>y(n);
    cin>>x[0]>>y[0]>>x[1]>>y[1];
    int x0=x[0],y0=y[0];
    int x1=x[1],y1=y[1];
    for(int i=2;i<n;i++)
    {
        cin>>x[i]>>y[i];
        ll cross=(x1-x0)*(y[i]-y0)-(y1-y0)*(x[i]-x0);
        if(cross>0) cout<<"LEFT ";
        else if(cross<0) cout<<"RIGHT ";
        else cout<<"STRAIGHT ";
        x0=x[i-1];y0=y[i-1];
        x1=x[i];y1=y[i];
    }
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}