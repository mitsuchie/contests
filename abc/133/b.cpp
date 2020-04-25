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

const ll MAXN = 10;
const ll MAXD = 10;
ll X[MAXN][MAXD];

int main()
{
    ll N, D;
    cin >> N >> D;

    rep (i, N)
    rep (j, D)
    {
        cin >> X[i][j];
    }

    ll ans = 0;

    for (ll i=0;i<N;++i)
    for (ll j=i+1;j<N;++j)
    {
        ll d = 0;

        for (ll k=0;k<D;++k)
        {
            d += abs(X[i][k] - X[j][k]) * abs(X[i][k] - X[j][k]);
        }

        ll t = 0;
        while (t * t < d) { ++t; }

        if (t * t == d)
        {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
