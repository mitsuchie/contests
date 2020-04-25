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

ll N;

int main()
{
    ll T;
    cin >> T;

    rep (t, T)
    {
        cin >> N;

        cout << "Case #" << t + 1 << ":" << endl;

        ll y = 0;
        ll v = 1;
        while (v <= N) { ++y; v *= 2; }

        --y;

        for (ll yy=1;yy<=y;++yy)
        for (ll xx=1;xx<=yy;++xx)
        {
            cout << ((yy % 2) ? xx : yy - xx + 1 ) << " " << yy << endl;
        }

        const ll r = N - (v / 2) + 1;

        rep (i, r)
        {
            cout << (((y + 1) % 2) ? 1 : y + i + 1) << " " << y + i + 1 << endl;
        }
    }

    return 0;
}
