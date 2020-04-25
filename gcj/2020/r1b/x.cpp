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

ll X, Y;
char S[1024];

bool solve(ll k, ll x, ll y)
{
    if (k == 10) { return false; }

    if (x == X && y == Y)
    {
        S[k] = 0;
        cout << S << endl;

        ll xx = 0, yy = 0;
        cout << "(0, 0)";

        rep (i, k)
        {
            if (S[i] == 'E') { xx += 1 << i; }
            if (S[i] == 'W') { xx -= 1 << i; }
            if (S[i] == 'N') { yy += 1 << i; }
            if (S[i] == 'S') { yy -= 1 << i; }
            cout << " -> (" << xx << ", " << yy << ")";
        }
        cout << endl;

        return true;
    }

    static constexpr ll dx[] = { 1, -1, 0, 0 };
    static constexpr ll dy[] = { 0, 0, 1, -1 };
    static const char* cc = "EWNS";

    bool res = false;

    rep (i, 4)
    {
        const auto dd = 1LL << k;

        const auto xx = x + dd * dx[i];
        const auto yy = y + dd * dy[i];

        S[k] = cc[i];
        res |= solve(k + 1, xx, yy);
    }

    return res;
}

int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        cin >> X >> Y;

        cout << "Case #" << t + 1 << ": " << X << ", " << Y << endl;
        const bool res = solve(0, 0, 0);
    }

    return 0;
}
