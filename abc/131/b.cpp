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

int main()
{
    ll n, l;
    cin >> n >> l;

    vector<ll> as(n);
    rep (i, n) { as[i] = l + i; }

    ll sum = 0;
    rep (i, n) { sum += as[i]; }

    ll distance = static_cast<ll>(1e9);
    ll ans = 0;

    rep (i, n)
    {
        const ll val = abs(as[i]);

        if (val < distance)
        {
            ans = sum - as[i];
            distance = val;
        }
    }

    cout << ans << endl;

    return 0;
}
