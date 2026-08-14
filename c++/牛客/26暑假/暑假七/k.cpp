#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    string m;
    getline(cin,m);
    vector<string> vec(n+1);
    for(int i = 1;i<=n;i++){
        string s;
        getline(cin,s);
        vec[i] = s;
    }

    vector<vector<bool>> vis(n+1,vector<bool>(n+1,0));

    vector<string> ans(n+1);
    map<ll,vector<string>> mp;
    for(int i = 1;i<=n;i++){
        string s = vec[i];
        string t;
        for(char c : s){
            t+=c;
            if(isspace(c)){
                t.pop_back();
                mp[i].push_back(t);
                t = "";
            }
            if(isupper(c)) ans[i]+=c;
        }
        mp[i].push_back(t);
    }

    while(1){
        bool ok = true;
        for(int i = 1;i<=n;i++){
            string s = ans[i];
            bool ok1 = false;
            for(int j = 1;j<=n;j++){
                if(i != j){
                    string t = ans[j];
                    if(s == t && !vis[i][j]){
                        ok = false;
                        ll cnt = 0;
                        ll idx = -1;
                        for(int k = 0;k<s.length()-1;k++){
                            if(isupper(s[k])){
                                cnt++;
                            }
                            if(isupper(s[k]) && isupper(s[k+1])){
                                if(mp[i][cnt-1] == mp[j][cnt-1] && mp[i][cnt-1].size() == 1){
                                    continue;
                                }
                                idx = k;
                                break;
                            }
                        }
                        if(idx == -1){
                            cnt++;
                            idx = s.length()-1;
                        }
                        if(idx == -1){
                            continue;
                        }
                        string b;
                        if(!ok1){
                            ok1 = true;
                            for (int k = idx + 1; k < ans[i].length(); k++)
                            {
                                b += ans[i][k];
                            }
                            ans[i].erase(idx, ans[i].length() - idx);
                            ans[i] += mp[i][cnt - 1];
                            ans[i] += b;
                        }
                       

                        b = "";
                        for(int k = idx + 1;k<ans[j].length();k++){
                            b += ans[j][k];
                        }
                        ans[j].erase(idx,ans[j].length() - idx);
                        ans[j] += mp[j][cnt-1];
                        ans[j] += b;

                        if(ans[i] == ans[j] && idx == s.length()-1){
                            vis[i][j] = vis[j][i] = 1;
                            vis[i][i] = vis[j][j] = 1;
                        }
                    }
                }
            }
        }
        if(ok) break;
    }

    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}