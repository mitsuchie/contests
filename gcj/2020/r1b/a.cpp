#include <iostream>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <tuple>
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

#define BIT(n) std::bitset<8>(n)

using ll = long long int;

ll X, Y;
char S[1024];

bool dfs(ll k, ll x, ll y)
{
    if (x == 0 && y == 0) { return true; }

    if ((x&1) == (y&1)) { return false; }

    if (x&1)
    {
        S[k] = X >= 0 ? 'E' : 'W';
        if (dfs(k+1, (x-1)>>1, y>>1)) { return true; }

        S[k] = X >= 0 ? 'W' : 'E';
        if (dfs(k+1, (x+1)>>1, y>>1)) { return true; }
    }

    if (y&1)
    {
        S[k] = Y >= 0 ? 'N' : 'S';
        if (dfs(k+1, x>>1, (y-1)>>1)) { return true; }

        S[k] = Y >= 0 ? 'S' : 'N';
        if (dfs(k+1, x>>1, (y+1)>>1)) { return true; }
    }

    return false;
}

string solve(ll x, ll y)
{
    if ((x&1) == (y&1)) { return "IMPOSSIBLE"; }

    dfs(0, x, y);
    return S;
}

int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        cin >> X >> Y;

        const auto res = solve(abs(X), abs(Y));
        cout << "Case #" << t + 1 << ": " << res << endl;
    }

    return 0;
}
