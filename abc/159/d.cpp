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

ll N;

const ll MAXN = 2 * 100000;
ll A[MAXN];
ll B[MAXN];
ll C[MAXN];

int main()
{
    cin >> N;

    rep (i, N)
    {
        cin >> A[i];
        --A[i];
        ++B[A[i]];
    }

    ll sum = 0;

    rep (i, N) if (!C[A[i]])
    {
        const ll b = B[A[i]];
        sum += b * (b - 1) / 2;
        C[A[i]] = 1;
    }

    rep (i, N)
    {
        const ll b = B[A[i]];

        const ll prev = b >= 2 ? (b * (b - 1)) / 2 : 0;
        const ll next = b >= 2 ? ((b - 1) * (b - 2)) / 2 : 0;

        const ll ans = sum - prev + next;
        cout << ans << endl;
    }

    return 0;
}
