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
    ll N, K;
    cin >> N >> K;

    const ll k1 = ((K * (K + 1)) >> 1) % mod;
    const ll k2 = ((K * (K - 1)) >> 1) % mod;

    vector<ll> A(N);
    for (auto& a : A) { cin >> a; }

    ll ans = 0;

    for (ll i=0;i<N;++i)
    {
        ll n = 0, m = 0;

        for (ll j=0;j<N;++j) if (A[i] > A[j])
        {
            if (i < j) { ++n; } else { ++m; }
        }

        const ll v = (n * k1) % mod;
        ans += v;
        ans %= mod;

        const ll w = (m * k2) % mod;
        ans += w;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}
