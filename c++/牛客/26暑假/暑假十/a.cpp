#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
const int MOD = 998244353;

double yzb(double sins, double sinb, double coss,double cosb,double ob)
{
    double bq = sinb * ob / sins;
    double res=ob*cosb+bq*fabs(coss);
    return res;
}
double yza(double sins, double sina,double coss,double cosa, double ob)
{
    double aq = sina * ob / sins;
    double res=ob*cosa+aq*fabs(coss);
    return res;
}
double yzb2(double sins, double sinb, double coss,double cosb,double ob)
{
    double bq = sinb * ob / sins;
    double res=ob*fabs(cosb)+bq*coss;
    return res;
}
double yza2(double sins, double sina,double coss,double cosa, double ob)
{
    double aq = sina * ob / sins;
    double res=ob*fabs(cosa)+aq*coss;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cout<<fixed<<setprecision(15);
    while (t--)
    {
        double sx, sy, ax, ay, bx, by, temp, minn, maxx;
        cin >> sx >> sy >> ax >> ay >> bx >> by;
        double os = sqrt(sx * sx + sy * sy), ob = sqrt(bx * bx + by * by);
        double coss = sx / os, cosb = bx / ob, cosa = ax / ob;
        double sins = sy / os, sinb = by / ob, sina = ay / ob;

        double resa = yza(sins, sina,coss,cosa, ob);
        double resb = yza(sins, sinb,coss,cosb, ob);

        double resa2 = yza2(sins, sina,coss,cosa, ob);
        double resb2 = yza2(sins, sinb,coss,cosb, ob);
        
        if(coss==cosb&&cosb==cosa)
        {
            cout<<0<<" "<<0<<'\n';
            continue;
        }
        if (coss < cosb)
        {
            double px = -sx, py = sy;
            double cosp = px / (sqrt(px * px + py * py));
            if (cosp <= cosa && cosp >= cosb)
            {
                maxx = ob / sins;
                minn = min(resa, resb);
                cout << minn << " " << maxx << '\n';
                continue;
            }
            else
            {
                minn = min(resa, resb);
                maxx = max(resa, resb);
                cout << minn << " " << maxx << '\n';
                continue;
            }
        }
        else if (coss <= cosa && coss >= cosb)
        {
            minn = 0;
            if(sx*ax+sy*ay<=0||sx*bx+sy*by<=0){
                maxx=ob*sins;
            }
            maxx = max(resa, resb);
            cout << minn << " " << maxx << '\n';
            continue;
        }
        else
        {
            double px = -sx, py = sy;
            double cosp = px / (sqrt(px * px + py * py));
            if (cosp <= cosa && cosp >= cosb)
            {
                maxx = ob / sins;
                minn = min(resa2, resb2);
                cout << minn << " " << maxx << '\n';
                continue;
            }
            else
            {
                minn = min(resa2, resb2);
                maxx = max(resa2, resb2);
                cout << minn << " " << maxx << '\n';
                continue;
            }
        }
    }

    return 0;
}