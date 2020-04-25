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

const ll MOD = 1000000007;

const ll MAXN = 2001;
ll dp[MAXN][MAXN];

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> S(n);
    vector<ll> T(m);

    for (auto& s : S) { cin >> s; }
    for (auto& t : T) { cin >> t; }

    rep (i, MAXN) { dp[0][i] = dp[i][0] = 1; }

    rep (i, n)
    rep (j, m)
    {
        const auto& s = S[i];
        const auto& t = T[j];

        auto& dst = dp[i + 1][j + 1];

        dst += dp[i + 1][j];
        dst += dp[i][j + 1];
        dst += (s == t ? 0 : MOD - dp[i][j]);
        dst %= MOD;
    }

    cout << dp[n][m] << endl;

    return 0;
}
