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

const ll MAXM = 200000;

ll M;
ll D[MAXM], C[MAXM];

int main()
{
    cin >> M;
    rep (i, M) { cin >> D[i] >> C[i]; }

    ll ans = 0;
    ll tmp = 0;

    rep (i, M)
    {
        tmp += D[i] * C[i];

        while (tmp >= 10)
        {
            const ll c1 = tmp / 10;
            const ll c2 = tmp % 10;

            ans += c1;
            tmp = c1 + c2;
        }

        ans += C[i];
    }

    cout << (ans - 1) << endl;

    return 0;
}
