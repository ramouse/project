#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, int> memo;

struct res
{
    ll num, f, g;

    bool operator<(const res &other) const
    {
        if (g != other.g)
        {
            return g > other.g;
        }
        return num < other.num;
    }
};

vector<res> cand;

void solve()
{
    auto calc = [&](ll x)
    {
        ll res = 1;
        for (auto v : to_string(x))
            res *= isdigit(v) * (v - '0');
        return res;
    };
    function<int(ll)> get = [&](ll x)
    {
        if (x < 10)
            return 0;
        if (memo.count(x))
            return memo[x];

        ll nxt = calc(x);
        return memo[x] = 1 + get(nxt);
    };
    function<void(int, ll, ll, int)> dfs = [&](int len, ll cur, ll prod, int lst)
    {
        if (len > 0)
        {
            int p = 0;
            if (cur < 10)
                p = 0;
            else
                p = 1 + get(prod);

            cand.push_back({cur, prod, p});
        }

        if (len == 18)
            return;

        for (int d = lst; d <= 9; d++)
        {
            dfs(len + 1, cur * 10 + d, prod * d, d);
        }
    };
    for (int i = 2; i <= 9; i++)
    {
        dfs(1, i, i, i);
    }
    sort(cand.begin(),cand.end());

    res A = cand[0];
    res B = {0, 0, -1};

    for (int i = 1; i < cand.size(); i++)
    {
        if (cand[i].f != A.f)
        {
            B = cand[i];
            break;
        }
    }
    cout << A.num << " " << B.num << endl;
}

int main(){
    solve();
    return 0;
}