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

const ll mod = 2019;

int main()
{
    ll L, R;
    cin >> L >> R;

    if (R - L >= 673 * 3)
    {
        cout << 0 << endl;
    }
    else
    {
        ll ans = 2019;

        for (ll i=L;i<=R;++i)
        for (ll j=i+1;j<=R;++j)
        {
            const ll x = (i * j) % mod;
            ans = min(ans, x);
        }

        cout << ans << endl;
    }

    return 0;
}
