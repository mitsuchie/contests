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

const ll MAXN = 2000;
string M[MAXN];

ll dp[MAXN][MAXN];

ll W, H;

int main()
{
    cin >> H >> W;
    rep (i, H) { cin >> M[i]; }

    rep (y, H)
    rep (x, W)
    {
        if (M[y][x] == '#') { continue; }

        ll n = 0;

        for (ll i=x;i<W;++i)
        {
            if (M[y][i] == '#') { break; }
            ++n;
        }

        while (x < W)
        {
            if (M[y][x] == '#') { break; }

            dp[y][x] += n;
            ++x;
        }
    }

    rep (x, W)
    rep (y, H)
    {
        if (M[y][x] == '#') { continue; }

        ll n = 0;

        for (ll i=y;i<H;++i)
        {
            if (M[i][x] == '#') { break; }
            ++n;
        }

        while (y < H)
        {
            if (M[y][x] == '#') { break; }
            dp[y][x] += n;
            ++y;
        }
    }

    ll ans = 0;

    rep (y, H)
    rep (x, W)
    {
        ans = max(ans, dp[y][x] - 1);
    }

    cout << ans << endl;

    return 0;
}
