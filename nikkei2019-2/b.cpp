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

// const ll mod = static_cast<ll>(1e9) + 7;
const ll mod = 998244353;

ll N;
vector<ll> D;

const ll MAXN = 100000 + 5;
ll M[MAXN];

ll solve()
{
    if (D[0]) { return 0; }

    ll ans = 1;

    M[0] = 1;

    rep (i, N - 1)
    {
        const ll d = D[i + 1];
        if (d == 0) { return 0; }

        const ll m = M[d - 1];
        if (m == 0) { return 0; }

        ++M[d];

        ans *= m;
        ans %= mod;
    }

    return ans % mod;
}

int main()
{
    cin >> N;

    D.assign(N, 0);
    for (auto&& d : D) { cin >> d; }

    if (D[0] != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(D.begin(), D.end());

    const ll ans = solve();
    cout << ans << endl;

    return 0;
}
