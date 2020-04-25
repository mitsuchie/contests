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

ll N;

const ll MAXN = 2 * 100000;
ll A[MAXN];
ll S[MAXN + 1];

ll calc(ll ai, ll bi, ll ci, ll di)
{
    if (ai < 0 || ai >= bi || bi >= ci || ci >= di) { return S[N]; }

    const ll a = S[ai + 1] - S[0];
    const ll b = S[bi + 1] - S[ai + 1];

    const ll c = S[ci + 1] - S[bi + 1];
    const ll d = S[di + 1] - S[ci + 1];

    const ll lhs = min(a, min(b, min(c, d)));
    const ll rhs = max(a, max(b, max(c, d)));

    return rhs - lhs;
}

int main()
{
    cin >> N;

    rep (i, N) { cin >> A[i]; }
    rep (i, N) { S[i + 1] = S[i] + A[i]; }

    ll ans = S[N];

    ll ai = 0;
    ll ci = 0;

    for (ll bi=1;bi<N-2;++bi)
    {
        if (ci <= bi) { ci = bi + 1; }

        while (ai + 1 < bi)
        {
            const ll a = S[ai + 2];
            const ll b = S[bi + 1] - S[ai + 2];

            if (a <= b) { ++ai; } else { break; }
        }

        while (ci + 1 < N - 1)
        {
            const ll c = S[ci + 2] - S[bi + 1];
            const ll d = S[N] - S[ci + 2];

            if (c <= d) { ++ci; } else { break; }
        }

        for (ll i=0;i<=1;++i)
        for (ll j=0;j<=1;++j)
        {
            const ll res = calc(ai + i, bi, ci + j, N - 1);
            ans = min(ans, res);
        }
    }

    cout << ans << endl;

    return 0;
}
