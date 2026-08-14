#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int>a(n+1,0);
    set<int>b;
    ll sum=0;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            sum^=a[x];
            a[x]++;
            sum^=a[x];
            if(a[x]>=1) b.insert(x);
        }
        if(op==2)
        {
            for(auto it=b.begin();it!=b.end();)
            {
                int x=*it;
                sum^=a[x];
                a[x]--;
                sum^=a[x];
                if(a[x]==0)
                {
                    it=b.erase(it);
                }
                else ++it;
            }
            
        }
        cout<<sum<<'\n';
    }
    return 0;
}