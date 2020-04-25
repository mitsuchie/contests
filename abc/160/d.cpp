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

int main()
{
    ll N, X, Y;
    cin >> N >> X >> Y;

    --X;
    --Y;

    REP (k, 1, N)
    {
        ll res = 0;

        rep (i, N)
        {
            if (N <= i + k) { continue; }

            if (i <= X && i + k <= X) { ++res; continue; }

            const ll d = k - abs(X - i) - 1;
            if (d < 0) { ++res; continue; }

            const ll a = Y - d;
            const ll b = Y + d;
            const ll c = i + k;

            if (c < a) { ++res; }
            if (b < N) { ++res; }
            if (c <= a && a < b) { ++res; }
        }

        cout << res << endl;
    }

    return 0;
}
