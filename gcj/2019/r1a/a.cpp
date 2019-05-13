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
// using det1 = vector< vector<ll> >
// using det2 = vector< vector<pll> >

int Ti;
int R, C;

const int MAXN = 20;
bool M[MAXN][MAXN];

const int MAXA = MAXN * MAXN;
pll ROUTE[MAXA];

bool IsDone;

void solve(int d, int xx, int yy)
{
    if (IsDone) { return; }

    M[xx][yy] = true;

    ROUTE[d].first  = xx;
    ROUTE[d].second = yy;

    if (d == R * C - 1)
    {
        IsDone = true;

        printf("Case #%d: POSSIBLE\n", Ti + 1);

        // rep(i, R * C) { cout << (ROUTE[i].first + 1) << " " << (ROUTE[i].second + 1) << endl; }
        rep(i, R * C) { cout << (ROUTE[i].second + 1) << " " << (ROUTE[i].first + 1) << endl; }

    }
    else
    {
        rep(x, C)
        rep(y, R)
        {
            if (M[x][y]) { continue; }

            if (x == xx) { continue; }
            if (y == yy) { continue; }
            if (y - x == yy - xx) { continue; }
            if (y + x == yy + xx) { continue; }

            solve(d + 1, x, y);
        }
    }

    M[xx][yy] = false;
}

void solve()
{
    IsDone = false;

    rep(x, C)
    rep(y, R)
    {
        M[x][y] = false;
    }

    rep(x, C)
    rep(y, R)
    {
        solve(0, x, y);
    }

    if (!IsDone)
    {
        printf("Case #%d: IMPOSSIBLE\n", Ti + 1);
    }
}

int main()
{
    int T;
    cin >> T;

    rep(i, T)
    {
        Ti = i;

        cin >> R >> C;

        solve();
    }

    return 0;
}
