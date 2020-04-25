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

const ll MAXN = 100000;
ll dp[MAXN + 1] = { 0 };

const ll M = 6;
const ll items[M] = { 100, 101, 102, 103, 104, 105 };

const ll MAXK = 1000000;

int main()
{
    ll X;
    cin >> X;

    dp[0] = 1;

    rep (i, M)
    rep (j, X)
    {
        if (dp[j] == 0) { continue; }
        if (dp[j] == i + 1) { continue; }

        rep (k, MAXK)
        {
            const ll val = j + (k + 1) * items[i];
            if (X < val) { continue; }

            dp[val] = i + 1;
        }
    }

    cout << (dp[X] ? 1 : 0) << endl;

    return 0;
}
