#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll h,w,k;
    cin>>h>>w>>k;
    vector<string> vec(h+1);
    vector<int> row(h+1,1),col(w+1,1);
    for(int i = 1;i<=h;i++){
        string s;
        cin>>s;
        s = " " + s;
        vec[i] = s;
        for(int j = 1;j<=w;j++){
            if(s[j] == '#'){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    ll ans = 0;
    vector<pll> pos;
    for(int i = 1;i<=h;i++){
        if(row[i]){
            for(int j = 1;j<=w;j++){
                if(col[j]){
                    pos.pb({i, j});
                    // cout << i << " " << j << endl;
                }
            }
        }
    }

    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    vector<vector<int>> vis(h+1,vector<int>(w+1,0));
    for(auto [r,c] : pos){
        queue<T> q;
        q.push({r,c,0});
        if(!vis[r][c]) ans++;
        vis[r][c] = 1;

        while(!q.empty()){
            auto [x,y,d] = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                ll xx = x + dx[i];
                ll yy = y + dy[i];
                if(xx <= h && xx >= 1 && yy <= w && yy >= 1){
                    if(vec[xx][yy] == '.'){
                        if(!vis[xx][yy] && d + 1 <= k){
                            ans++;
                            vis[xx][yy] = 1;
                            q.push({xx,yy,d+1});
                        }else if(vis[xx][yy] && d + 1 <= k){
                            q.push({xx,yy,d+1});
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

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