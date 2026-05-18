#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == n)
    {
        cout << "No\n";
        return;
    }

    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            root = i;
            break;
        }
    }

    vector<int> vis(n + 1, 0);
    queue<int> q;

    q.push(root);
    vis[root] = 1;

    
    vector<vector<int>> ans;


    int coun = 1; 

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        vector<int> vec;

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                vec.push_back(v);
                coun++;

                if (!a[v])
                {
                    q.push(v);
                }
            }
        }

        if (!vec.empty())
        {
            vector<int> step;
            step.push_back(u);                
            step.push_back(vec.size());
            for (int v : vec)
            {
                step.push_back(v); 
            }
            ans.push_back(step);
        }
    }

    if (coun < n)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes"<<endl;
        cout << ans.size() << endl;
        // cout<<root<<" ";
        for ( auto &step : ans)
        {
            for (int x : step)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}