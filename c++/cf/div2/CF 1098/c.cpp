#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define endl '\n'

const ll INF = 2e18;

ll get_diff(ll a, unsigned long long b)
{
    if ((unsigned long long)a >= b)
        return (ll)((unsigned long long)a - b);
    return (ll)(b - (unsigned long long)a);
}

void solve()
{
    ll a,n;
    cin>>a>>n;
    vector<ll> d(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>d[i];
    }
    sort(d.begin()+1,d.end());
    // for(int i = 1;i<=n;i++){
    //     cout<<d[i]<<" ";
    // }
    // cout<<endl;

    ll ans = INF;
    if(d[1] == 0){
        ans = a;
    }
    string t = to_string(a);
    ll len = t.length();
    t = " "+ t;

    string s = ""; 
    for(int i = 1;i<=len;i++){
        ll cur = t[i]-'0';
        for(int k = 1;k<=n;k++){
                ll u = d[k];

                if(i == 1 && u == 0 && len>1) continue;

                string temp = s;
                if(u<cur){
                    temp += u + '0';
                    for(int j = i + 1;j<=len;j++){
                        temp+=d[n] + '0';
                    }
                    ll num = stoull(temp);
                    ans = min(ans, get_diff(a,num));
                }
                if(u>cur){
                    temp += u + '0';
                    for(int j = i+1;j<=len;j++){
                        temp += d[1] + '0';
                    }
                    ll num = stoull(temp);
                    ans = min(ans, get_diff(a,num));
                
                }
        }
                

        bool ok = false;
        for(int k = 1;k<=n;k++){
            ll u = d[k];
            if(u == cur){
                ok = true;
            }
        }
        if(ok){
            s += t[i];
        }else{
            break;
        }

        
    }

    if(s.length() == len){
        ans = min(ans,get_diff(a , stoull(s)));
    }
    

    s = "";
    len--;
    if(len>=1){
        if(d[n]>0){
            for (int i = 1; i <= len; i++)
            {
                s += d[n] + '0';
            }
            ll num = stoull(s);
            ans = min(ans, get_diff(a,num));
        }
        
    }

    len+=2;
    s = "";
    if(d[1] == 0){
        if(n>=2){
            ll index = lower_bound(d.begin()+1,d.end(),1)-d.begin();
            if(index <= n){
                s += d[index] + '0';
                for (int i = 2; i <= len; i++)
                {
                    s += d[1] + '0';
                }
            }
            
        }
        
    }else{
        for (int i = 1; i <= len; i++)
        {
            s += d[1] + '0';
        }
    }
    if(s != ""){
        ll num = stoull(s);
        ans = min(ans,get_diff(a,num));
    }
    
    

    cout<<ans<<endl;
    

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}