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
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

int T;
int P, Q;

const int MAXQ=16;
int M[MAXQ][MAXQ];

void solve(int t)
{
    rep(i, P)
    {
        int x, y;
        char d;

        cin >> x >> y >> d;

        if (d == 'N') { for (int yy=y+1;yy<=Q;++yy) { for (int xx=0;xx<=Q;++xx)   { M[xx][yy] += 1; } } }
        if (d == 'S') { for (int yy=y-1;yy>=0;--yy) { for (int xx=0;xx<=Q;++xx)   { M[xx][yy] += 1; } } }
        if (d == 'E') { for (int yy=0;yy<=Q;++yy)   { for (int xx=x+1;xx<=Q;++xx) { M[xx][yy] += 1; } } }
        if (d == 'W') { for (int yy=0;yy<=Q;++yy)   { for (int xx=x-1;xx>=0;--xx) { M[xx][yy] += 1; } } }
    }

    int maxValue = 0;

    rep (xx, Q+1)
    rep (yy, Q+1)
    {
        maxValue = max(maxValue, M[xx][yy]);
    }

    rep (yy, Q+1)
    rep (xx, Q+1)
    {
        if (M[xx][yy] == maxValue)
        {
            printf("Case #%d: %d %d\n", t + 1, xx, yy);
            return;
        }
    }

    printf("Case #%d: %d %d\n", t + 1, 0, 0);
}

int main()
{
    cin >> T;

    rep(t, T)
    {
        rep(i, MAXQ) { rep(j, MAXQ) { M[i][j] = 0; } }

        cin >> P >> Q;
        Q = min(Q, MAXQ);

        solve(t);
    }

    return 0;
}
