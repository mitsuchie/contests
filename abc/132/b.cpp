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
    ll n;
    cin >> n;

    vector<ll> ps(n);
    rep (i, n) { cin >> ps[i]; }

    ll res = 0;

    rep (i, n - 2)
    {
        const bool a = ps[i] < ps[i + 1] && ps[i + 1] <= ps[i + 2];
        const bool b = ps[i + 2] < ps[i + 1] && ps[i + 1] <= ps[i];

        if (a || b) { ++res; }
    }

    cout << res << endl;

    return 0;
}
