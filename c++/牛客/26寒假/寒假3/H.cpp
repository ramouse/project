#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



int main(){ //叉积求三角形面积
    double xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;

    double ans = 0.0;
    if(ya == yb){
        double t = fabs(xa*yb - xb*ya);
        if(fabs(4 - t) <=1e-9){
            cout<<0.0<<endl;
            return 0;
        }else{
            cout << "no answer";
            return 0;
        }
    }else{
        double a = xa * yb - xb * ya;
        double b = ya - yb;
        ans = (4 - a) / b;
        printf("%.10lf",ans);
    }

    return 0;
}