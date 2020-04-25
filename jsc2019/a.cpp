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
    ll M, D;
    cin >> M >> D;

    ll ans = 0;

    for (ll m=1;m<=M;++m)
    for (ll d=1;d<=D;++d)
    {
        const ll d1 = d % 10;
        const ll d2 = (d / 10) % 10;

        if (d1 < 2) { continue; }
        if (d2 < 2) { continue; }

        const ll dd = d1 * d2;

        if (dd == m)
        {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
