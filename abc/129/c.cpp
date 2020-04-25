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

#define REP(i,p,n) for(int i=p;i<n;++i)
#define rep(i,n) REP(i,0,n)

using ll = long long int;
using pll = pair<ll, ll>;

const ll MAXN = 100002;
ll dp[MAXN];

const ll mod = 1000000007;

int main()
{
    ll N, M;
    cin >> N >> M;

    rep (i, M)
    {
        ll a;
        cin >> a;

        dp[a] = -1;
    }


    dp[0] = 1;

    rep(i, N) if (dp[i] != -1)
    {
        if (dp[i + 1] != -1)
        {
            dp[i + 1] += dp[i];
            dp[i + 1] %= mod;
        }

        if (dp[i + 2] != -1)
        {
            dp[i + 2] += dp[i];
            dp[i + 2] %= mod;
        }
    }

    cout << dp[N] << endl;

    return 0;
}
