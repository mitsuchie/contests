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

const ll mod = 998244353;

ll N, S;

const ll MAXN = 3000;
ll A[MAXN];

ll dp[MAXN][MAXN];

int main()
{
    cin >> N >> S;
    rep (i, N) { cin >> A[i]; }

    ll s = 0;

    rep (i, N)
    {
        if (i >= 1) { dp[0][i] += dp[0][i - 1]; }


        s += A[i];
    }


    return 0;
}
