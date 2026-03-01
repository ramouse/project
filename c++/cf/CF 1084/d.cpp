#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> p(n+1,0);
    for(int i = 1;i<=n;i++) cin>>p[i];

    ll minn = 2e5+5;
    ll id = 0;
    for(int i = x+1;i<=y;i++){
        if(p[i]<minn){
            minn = p[i];
            id = i;
        }
    }

    ll idd = -1;
    for (int i = 1; i <= x; i++)
    {
        if (p[i] > minn)
        {
            idd = i;
            break;
        }
    }

    if (idd != -1)
    {
        for (int i = 1; i < idd; i++)
        {
            cout << p[i] << " ";
        }
        for (int i = id; i <= y; i++)
        {
            cout << p[i] << " ";
        }
        if (id != x + 1)
        {
            for (int i = x + 1; i < id; i++)
            {
                cout << p[i] << " ";
            }
        }
        for (int i = idd; i <= x; i++)
        {
            cout << p[i] << " ";
        }
        for (int i = y + 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
    }
    else
    {
        for (int i = 1; i <= x; i++)
            cout << p[i] << " ";

        for (int i = y + 1; i <= n; i++)
        {
            if (p[i] < minn)
                cout << p[i] << " ";
            else
            {
                idd = i;
                break;
            }
        }
        for (int i = id; i <= y; i++)
        {
            cout << p[i] << " ";
        }
        if (id != x + 1)
        {
            for (int i = x + 1; i < id; i++)
            {
                cout << p[i] << " ";
            }
        }
        if (idd != -1)
        {
            for (int i = idd; i <= n; i++)
            {
                cout << p[i] << " ";
            }
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 