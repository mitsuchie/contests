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

    vector<ll> p(n);
    rep (i, n) { cin >> p[i]; }

    bool ans = true;
    rep (i, n - 1) { ans &= p[i] <= p[i + 1]; }

    for (ll i=0;i<n;++i)
    for (ll j=i+1;j<n;++j)
    {
        const ll tmp = p[j];
        p[j] = p[i];
        p[i] = tmp;

        bool ok = true;
        rep (k, n - 1) { ok &= p[k] <= p[k + 1]; }

        ans = ans || ok;

        p[i] = p[j];
        p[j] = tmp;
    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}
