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

const int MAXN = 32;
char M[MAXN][MAXN];

int W, H, E;

bool isOKH(int x, int y)
{
    if (M[y][x] != '.') { return false; }

    for (int xx=x;xx>=0;--xx)
    {
        if (M[y][xx] == '#') { return false; }
        if (M[y][xx] != '.') { break; }
    }

    for (int xx=x;xx<W;++xx)
    {
        if (M[y][xx] == '#') { return false; }
        if (M[y][xx] != '.') { break; }
    }

    return true;
}

bool isOKV(int x, int y)
{
    if (M[y][x] != '.') { return false; }

    for (int yy=y;yy>=0;--yy)
    {
        if (M[yy][x] == '#') { return false; }
        if (M[yy][x] != '.') { break; }
    }

    for (int yy=y;yy<H;++yy)
    {
        if (M[yy][x] == '#') { return false; }
        if (M[yy][x] != '.') { break; }
    }

    return true;
}

int solve(int depth = 0, int fn = 0)
{
    const auto calcRes = [depth]()
    {
        if ((depth % 2) == 0) { return 0; }

        return 1;
    };

    if (fn == E) { return calcRes(); }

    const auto calcV = [&](int x, int y)
    {
        int ym = y;
        int yp = y;
        int ff = 0;

        for (ym=y-1;ym>=0;--ym)
        {
            if (M[ym][x] != '.') { break; }
            ++ff;
        }

        for (yp=y+1;yp<H;++yp)
        {
            if (M[yp][x] != '.') { break; }
            ++ff;
        }

        for (int yy=y;yy>ym;--yy) { M[yy][x] = 'V'; }
        for (int yy=y;yy<yp;++yy) { M[yy][x] = 'V'; }

        M[y][x] = 'V';
        ++ff;

        const int res = solve(depth + 1, fn + ff);

        M[y][x] = '.';

        for (int yy=y;yy>ym;--yy) { M[yy][x] = '.'; }
        for (int yy=y;yy<yp;++yy) { M[yy][x] = '.'; }


        return res;
    };

    const auto calcH = [&](int x, int y)
    {
        int xm = x;
        int xp = x;
        int ff = 0;

        for (xm=x-1;xm>=0;--xm)
        {
            if (M[y][xm] != '.') { break; }
            ++ff;
        }

        for (xp=x+1;xp<W;++xp)
        {
            if (M[y][xp] != '.') { break; }
            ++ff;
        }

        for (int xx=x;xx>xm;--xx) { M[y][xx] = 'H'; }
        for (int xx=x;xx<xp;++xx) { M[y][xx] = 'H'; }

        M[y][x] = 'H';
        ++ff;

        const int res = solve(depth + 1, fn + ff);

        M[y][x] = '.';

        for (int xx=x;xx>xm;--xx) { M[y][xx] = '.'; }
        for (int xx=x;xx<xp;++xx) { M[y][xx] = '.'; }

        return res;
    };

    if ((depth % 2) == 1)
    {
        bool isPuttable = false;

        rep(y, H)
        rep(x, W)
        {
            const bool v = isOKV(x, y);
            const bool h = isOKH(x, y);

            isPuttable |= v || h;
        }

        if (!isPuttable) { return 1; }
    }

    int ans = 0;

    rep(y, H)
    rep(x, W)
    {
        if (M[y][x] != '.') { continue; }

        const int lhs = isOKV(x, y) ? calcV(x, y) : 0;
        const int rhs = isOKH(x, y) ? calcH(x, y) : 0;

        const int res = lhs + rhs;
        ans += res;
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    rep(t, T)
    {
        cin >> H >> W;

        rep(y, H) { cin >> M[y]; }

        E = 0;

        rep(y, H)
        rep(x, W)
        {
            if (M[y][x] == '.') { ++E; }
        }

        const int ans = solve();
        printf("Case #%d: %d\n", t + 1, ans);
    }

    return 0;
}
