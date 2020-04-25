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

#define REP(i,p,n) for(ll i=p;i<ll(n);++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll mod = static_cast<ll>(1e9) + 7;
const ll MAXN = 100001;

ll W, H;

const ll MAXH = 101;
string S[MAXH];

ll dp[MAXH][MAXH];

ll dfs(ll x, ll y)
{
    if (dp[x][y]) { return dp[x][y] - 1; }

    ll res = MAXN;

    if (x < W - 1)
    {
        const auto neq = S[y][x] == '.' && S[y][x + 1] == '#';
        res = min(res, dfs(x + 1, y) + (neq ? 1 : 0));
    }

    if (y < H - 1)
    {
        const auto neq = S[y][x] == '.' && S[y + 1][x] == '#';
        res = min(res, dfs(x, y + 1) + (neq ? 1 : 0));
    }

    res = res != MAXN ? res : 0;
    return (dp[x][y] = res + 1) -1;
}

int main()
{
    cin >> H >> W;
    rep (i, H) { cin >> S[i]; }

    const ll ans = dfs(0, 0) + (S[0][0] == '#' ? 1 : 0);
    cout << ans << endl;

    return 0;
}
