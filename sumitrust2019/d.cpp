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
string S;

const ll MAXT = 1000;
ll dp[MAXT] = { 0 };

ll cs[10] = { 0 };

int main()
{
    cin >> N;
    cin >> S;

    rep (i, N)
    {
        const ll s = S[i] - '0';
        cs[s] = min(cs[s] + 1, 3LL);
    }

    ll ans = 0;

    rep (i, 10)
    rep (j, 10)
    rep (k, 10)
    {
        --cs[i];
        --cs[j];
        --cs[k];

        if (cs[i] >= 0 && cs[j] >= 0 && cs[k] >= 0)
        {
            ++ans;
        }

        ++cs[i];
        ++cs[j];
        ++cs[k];
    }

    cout << ans << endl;

    return 0;
}
