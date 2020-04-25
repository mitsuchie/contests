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

string solve(ll x, ll y)
{
    if ((x&1) == (y&1)) { return "IMPOSSIBLE"; }

    const auto getLength = [](ll val)
    {
        ll res = 0;
        while (val) { val >>= 1; ++res; }
        return res;
    };

    const auto w = getLength(abs(x));
    const auto h = getLength(abs(y));
    const auto l = max(w, h);

    const auto func = [](ll xx, ll yy, ll length)
    {
        S[length] = 0;

        rep (i, length)
        {
            const auto k = length - i - 1;
            const auto d = 1 << k;

            if (abs(yy) < abs(xx))
            {
                if (xx < 0) { S[k] = 'W'; xx += d; }
                else        { S[k] = 'E'; xx -= d; }
            }
            else
            {
                if (yy < 0) { S[k] = 'S'; yy += d; }
                else        { S[k] = 'N'; yy -= d; }
            }
        }

        return xx == 0 && yy == 0;
    };

    func(x, y, l) || func(x, y, l + 1);
    return S;
}

int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        cin >> X >> Y;

        const auto res = solve(X, Y);
        cout << "Case #" << t + 1 << ": " << res << endl;
    }

    return 0;
}
