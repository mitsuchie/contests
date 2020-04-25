#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int main()
{
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    if ((W%2) == 0 && (H%2) == 0 && (W/2) == x && (H/2) == y)
    {
        const double ans = static_cast<double>((W * H) >> 1);
        printf("%.09lf 1\n", ans);
    }
    else // else if (((W%2) == 0 && (W/2) == x) || ((H%2) == 0 && (H/2) == y))
    {
        const double ans = static_cast<double>((W * H)) * 0.5;
        printf("%.09lf 0\n", ans);
    }

    return 0;
}
