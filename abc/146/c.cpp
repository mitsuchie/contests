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

using ll = unsigned long long;
using pll = pair<ll, ll>;

const ll mod = static_cast<ll>(1e9) + 7;
const ll MAXN = static_cast<ll>(1e9);

ll A, B, X;

ll calcCount(ll n)
{
    ll d = 0;
    while (n != 0) { ++d; n /= 10; }

    return d;
}

ll calcValue(ll n)
{
    const ll d = calcCount(n);

    return A * n + B * d;
}

int main()
{
    cin >> A >> B >> X;

    ll lhs = 0, rhs = MAXN + 1;

    while (lhs + 1 < rhs)
    {
        const ll mid = (lhs + rhs) >> 1;
        const ll val = calcValue(mid);

        const bool ok = val <= X;

        if (ok)
        {
            lhs = mid;
        }
        else
        {
            rhs = mid;
        }
    }

    cout << lhs << endl;

    return 0;
}
