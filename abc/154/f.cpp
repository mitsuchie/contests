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

const ll N = 2000000LL + 2LL;
const ll M = static_cast<ll>(1e9) + 7LL;

int main()
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    vector<ll> fact(N, 0);
    vector<ll> finv(N, 0);
    vector<ll> inv(N, 0);

    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1]  = 1;

    for (ll i=2;i<N;++i)
    {
        fact[i] = (i * fact[i - 1]) % M;
        inv[i]  = M - (inv[M % i] * (M / i)) % M;
        finv[i] = (finv[i - 1] * inv[i]) % M;
    }

    const auto ncr = [&](ll n, ll r)
    {
        return (fact[n] * ((finv[r] * finv[n - r]) % M)) % M;
    };

    const auto sum = [&](ll x, ll y)
    {
        ll res = 0;
        for (ll i=0;i<x+1;++i) { res = (res + ncr(y + i + 1, y)) % M; }
        return res;
    };

    const ll a = sum(r2, c2);
    const ll b = sum(r1 - 1, c2);
    const ll c = sum(r2, c1 - 1);
    const ll d = sum(r1 - 1, c1 - 1);

    const ll ans = (a + d - b - c + 4 * M) % M;
    cout << ans << endl;

    return 0;
}
