#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<int> p(n);
    vector<int> pos(n + 1); 
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i; 
    }

    int L = -1, R = -1;

    for (int i = 0; i < n; i++)
    {
        int target = n - i;
        if (p[i] != target)
        {
            L = i;
            R = pos[target];
            break;
        }
    }

    if (L != -1)
    {
        reverse(p.begin() + L, p.begin() + R + 1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
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