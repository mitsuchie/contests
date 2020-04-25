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

const ll MAXN = 128;
ll M[MAXN][MAXN];

int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        ll N;
        cin >> N;

        rep(i, N)
        rep(j, N)
        {
            cin >> M[i][j];
        }

        ll sum = 0, row = 0, column = 0;

        rep (i, N)
        {
            sum += M[i][i];
        }

        rep (i, N)
        {
            set<ll> rElements, cElements;
            bool rr = false, cc = false;

            rep (j, N)
            {
                const ll r = M[i][j];
                const ll c = M[j][i];

                rr = rr || rElements.find(r) != rElements.end();
                cc = cc || cElements.find(c) != cElements.end();

                rElements.insert(r);
                cElements.insert(c);
            }

            if (rr) { ++row; }
            if (cc) { ++column; }
        }

        printf("Case #%lld: %lld %lld %lld\n", t + 1, sum, row, column);
    }

    return 0;
}
