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

const ll MAXN = 10000000;
// vector<ll> primes;
bool primes[MAXN];

int main()
{
    ll N;
    cin >> N;

    ll ans = N - 1;

    for (ll i=2;i*i<=N;++i)
    {
        if (primes[i]) { continue; }

        for (ll j=i*2;j*j<=N;j+=i)
        {
            primes[j] = true;
        }

        if ((N % i) == 0)
        {
            const ll k = N / i;
            const ll val = (i - 1) + (k - 1);

            ans = min(ans, val);
        }
    }

    cout << ans << endl;

    return 0;
}
