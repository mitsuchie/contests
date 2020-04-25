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
using namespace std;

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

ll N, M, K;

const ll mod = 1000000000 + 7;

ll pow_with_mod(ll x, ll n)
{
    if (n == 0){ return 1; }
    if (n == 1){ return x; }
    ll xx = pow_with_mod(x, n >> 1) % mod;
    return (((xx * xx) % mod) * (n & 1 ? x : 1)) % mod;
}

ll ncr_with_mod(ll n,ll r)
{
    ll x = 1, y = 1;
    for (ll i=n-r+1;i<=n;++i) { x *= i; x %= mod; }
    for (ll i=1;    i<=r;++i) { y *= i; y %= mod; }
    y = pow_with_mod(y, mod - 2);
    return ((x % mod) * y) % mod;
}

int main()
{
    cin >> N >> M >> K;

    ll ans = 0;

    for (ll i=0,n=N*M;i<n;++i)
    {
        const ll x1 = i % N;
        const ll y1 = i / N;

        for (ll j=i+1;j<n;++j)
        {
            const ll x2 = j % N;
            const ll y2 = j / N;

            const ll val = abs(x1 - x2) + abs(y1 - y2);
            const ll ncr = ncr_with_mod(n, K);

            ans += val * ncr;
        }
    }

    cout << ans << endl;

    return 0;
}
