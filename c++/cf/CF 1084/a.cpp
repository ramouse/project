#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    vector<int> pre(n+1,0);
    int sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        pre[i] = pre[i-1] + a[i];
    }

    if(n == 1){
        cout<<1<<endl;
        return;
    }
    
    set<int> ans;
    for(int i = 1;i<=n;i++){
        vector<int> cur = a;
        int pl = i;
        int sh = pre[n];
        int le = -1;
        
        while(sh>0){
            if(cur[pl]>0){
                cur[pl]--;
                sh--;
                le = pl;
            }
            
            pl = pl%n+1;
        }
        if(le!=-1){
            ans.insert(le);
        }
    }
    
    cout<<ans.size()<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}