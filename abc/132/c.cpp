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

    vector<ll> ds(n);
    rep (i, n) { cin >> ds[i]; }

    sort(ds.begin(), ds.end());

    if (ds.size() % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        const ll mid = ds.size() / 2;

        const ll lhs = ds[mid - 1];
        const ll rhs = ds[mid];

        cout << (rhs - lhs) << endl;
    }

    return 0;
}
