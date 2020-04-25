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
    ll n;
    cin >> n;

    const ll t = (n * 100 / 108);

    ll ans = -1;

    for (ll i=-1;i<=1;++i)
    {
        const ll ti = t + i;
        const ll k = ((ti * 108) / 100);
        if (k == n) { ans = ti; }
    }

    if (ans != -1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << ":(" << endl;
    }


    return 0;
}
