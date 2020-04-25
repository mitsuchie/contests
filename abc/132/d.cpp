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

const ll mod = 1000000007;

ll pow_with_mod(ll x, ll n)
{
    if (n == 0){ return 1; }
    if (n == 1){ return x; }
    ll xx = pow_with_mod(x, n >> 1) % mod;
    return (((xx * xx) % mod) * (n & 1 ? x : 1)) % mod;
}

ll ncr_with_mod(ll n, ll r)
{
    ll x = 1, y = 1;
    for (ll i=n-r+1;i<=n;++i) { x *= i; x %= mod; }
    for (ll i=1;    i<=r;++i) { y *= i; y %= mod; }
    y = pow_with_mod(y, mod - 2);
    return ((x % mod) * y) % mod;
}


int main()
{
    ll n, k;
    cin >> n >> k;

    for (ll i=1;i<=k;++i)
    {
        const ll t = n - k + 1;
        if (t < i) { cout << 0 << endl; continue; }

        const ll c1 = ncr_with_mod(t, i);
        const ll c2 = i - 1 <= 0 ? 1 : ncr_with_mod(k - 1, i - 1);

        cout << (c1 * c2 % mod) << endl;
    }

    return 0;
}
