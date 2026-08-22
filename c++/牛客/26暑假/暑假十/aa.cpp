#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
const int MOD = 998244353;
const ll INF = 0x0f0f0f0f0f0f;
double getres(double ax, double ay, double bx, double by)
{
    // ay/ax(x-bx)+by;
    // ay/ax*x-bx*ay/ax+by;
    //(bx*ay/ax-by)*ax/ay;
    // cout<<(ay * bx - by * ax) / ay<<endl;
    return fabs((double)(ay * bx - by * ax) / ay);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cout << fixed << setprecision(15);
    while (t--)
    {
        double sx, sy, ax, ay, bx, by, px, py, temp, minn = INF, maxx = -INF;
        cin >> sx >> sy >> ax >> ay >> bx >> by;
        // cout<<sx/ay<<endl;
        // cout<<sx<<endl;
        if (sx == 0)
        {
            if (ax >= 0 && bx <= 0)
            {
                cout << 0.000000000000000 << " " << max(fabs(ax), fabs(bx)) << '\n';
                continue;
            }
            else
            {
                cout << min(fabs(ax), fabs(bx)) << " " << max(fabs(ax), fabs(bx)) << '\n';
                continue;
            }
        }
        if ((sx * ay - sy * ax) * (sx * by - sy * bx) <= 0)
        {
            minn = 0;
        }
        double os = sqrt(sx * sx + sy * sy), ob = sqrt(bx * bx + by * by);
        double m = ob / os;
        sx *= m;
        sy *= m;
        px = (double)-1 * sy;
        py = sx;

        if ((px * ay - py * ax) * (px * by - py * bx) <= 0)
        {
            maxx = getres(sx, sy, px, py);
        }
        maxx = max(maxx, getres(sx, sy, ax, ay));
        maxx = max(maxx, getres(sx, sy, bx, by));
        minn = min(minn, getres(sx, sy, ax, ay));
        minn = min(minn, getres(sx, sy, bx, by));
        cout << minn << " " << maxx << '\n';
    }
    return 0;
}