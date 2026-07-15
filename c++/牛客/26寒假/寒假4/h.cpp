#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int n, m,q;

int dx[] = {0,1,-1,2,-2,0,0,0,0,1,-1,1,-1};
int dy[] = {0,0,0,0,0,1,-1,2,-2,1,1,-1,-1};

bool check(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}

int main(){
    cin>>n>>m>>q;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> sum(n + 1, vector<ll>(m + 1, 0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    ll maxx = -1;
    ll xx = 0,yy = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            ll cur = 0;
            for(int k = 0;k<13;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(check(nx,ny)){
                    cur+=a[nx][ny];
                }

            }
            sum[i][j] = cur;

            if(cur>=maxx){
                maxx = cur;
                xx = i;
                yy = j;
            }
        }
    }

    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;

        for(int k = 0;k<13;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(check(nx,ny)){
                sum[nx][ny] += z;

                if(sum[nx][ny] >= maxx){
                    maxx = sum[nx][ny];
                    xx = nx;
                    yy = ny;
                }
            }
        }
        cout<<xx<<" "<<yy<<endl;
    }

    return 0;
}