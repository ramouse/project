#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll maxn = 1e6;
vector<ll> prime;              // 存储已经找到的所有素数（相当于 “素数字典”）；
vector<ll> phi(maxn + 1, 1);   // 存储每个数的欧拉函数值(顺带计算)
vector<bool> vis(maxn + 1, 0); // 标记某个数是否为合数（false= 素数，true = 合数）
void init()
{
    phi[1] = 1;
    vis[1] = 1; // 1既不是质数也不是合数，但在筛法中标记为1避免重复处理
    for (ll i = 2; i <= maxn; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size(); ++j)
        {
            ll p = prime[j];
            if (p * i > maxn)
                break;
            vis[p * i] = true;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            else
            {
                phi[i * p] = phi[i] * phi[p];
            }
        }
    }
}
int main()
{
    init();
    for (int i = 1; i <= 10; i++)
    {
        cout << phi[i] << endl;
    }
    return 0;
}